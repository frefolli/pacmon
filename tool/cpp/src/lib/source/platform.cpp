#include<lib/source/platform.hpp>
#include<yaml-cpp/yaml.h>
#include<boost/algorithm/string/join.hpp>
#include<fstream>
#include<stdexcept>
#include<algorithm>

lib::source::Platform::Platform(std::string path) : lib::types::IndexFile(path) {
  this->load();
}

lib::source::Platform::~Platform() {
  delete this->packages;
}

long unsigned int lib::source::Platform::getNumberOfPackages() {
  return this->packages->size();
}

std::string lib::source::Platform::getPackage(long unsigned int which) {
  return this->packages->get(which);
}

void lib::source::Platform::addPackage(std::string package) {
  this->packages->add(package);
  this->dump();
}

void lib::source::Platform::deletePackage(std::string package) {
  this->packages->del(package);
  this->dump();
}

void lib::source::Platform::renamePackage(std::string package, std::string newname) {
    this->packages->set(package, newname);
  this->dump();
}

bool lib::source::Platform::containsPackage(std::string package) {
  return this->packages->contains(package);
}

std::string lib::source::Platform::toString() {
  std::string string = "(source:platform";
  string += " :packages " + this->packages->toString();
  return string + ")";
}

void lib::source::Platform::load() {
    YAML::Node document;
  try {
    document = YAML::LoadFile(this->getIndexPath());
  } catch(...) {
    throw new std::runtime_error("source platform index file doesn't exists");
  }
  this->packages = new lib::types::StringList();
  this->packages->load(document["packages"]);
}

void lib::source::Platform::dump() {
  YAML::Node document;
  document["packages"] = this->packages->dump();
  std::ofstream output; output.open(this->getIndexPath());
  output << document; output.close();
}
