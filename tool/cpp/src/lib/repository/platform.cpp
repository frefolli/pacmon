#include<lib/repository/platform.hpp>
#include<yaml-cpp/yaml.h>
#include<fstream>
#include<lib/exceptions/invalid_repository_platform_index_file_path.hpp>

lib::repository::Platform::Platform(std::string path) : lib::types::IndexFile(path) {
  this->load();
}

lib::repository::Platform::~Platform() {
  delete this->packages;
}

long unsigned int lib::repository::Platform::getNumberOfPackages() {
  return this->packages->size();
}

std::string lib::repository::Platform::getPackage(long unsigned int which) {
  return this->packages->get(which);
}

void lib::repository::Platform::addPackage(std::string package) {
  this->packages->add(package);
}

void lib::repository::Platform::deletePackage(std::string package) {
  this->packages->del(package);
}

void lib::repository::Platform::renamePackage(std::string package, std::string newname) {
  this->packages->set(package, newname);
}

bool lib::repository::Platform::containsPackage(std::string package) {
  return this->packages->contains(package);
}

std::string lib::repository::Platform::toString() {
  std::string string = "(repository:platform";
  string += " :packages " + this->packages->toString();
  return string + ")";
}

void lib::repository::Platform::load() {
  YAML::Node document;
  try {
    document = YAML::LoadFile(this->getIndexPath());
  } catch(...) {
    throw lib::exceptions::InvalidRepositoryPlatformIndexFilePath(this->getIndexPath());
  }
  this->packages = new lib::types::StringList();
  this->packages->load(document["packages"]);
}

void lib::repository::Platform::dump() {
  YAML::Node document;
  document["packages"] = this->packages->dump();
  std::ofstream output; output.open(this->getIndexPath());
  output << document; output.close();
}

void lib::repository::Platform::commit() {
  this->dump();
}
