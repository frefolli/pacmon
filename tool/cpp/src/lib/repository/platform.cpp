#include<lib/repository/platform.hpp>
#include<yaml-cpp/yaml.h>
#include<boost/algorithm/string/join.hpp>
#include<fstream>
#include<stdexcept>
#include<algorithm>

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
  this->dump();
}

void lib::repository::Platform::deletePackage(std::string package) {
  this->packages->del(package);
  this->dump();
}

void lib::repository::Platform::renamePackage(std::string package, std::string newname) {
    this->packages->set(package, newname);
  this->dump();
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
    throw new std::runtime_error("repository platform index file doesn't exists");
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
