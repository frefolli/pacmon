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
  if (which > this->getNumberOfPackages())
    throw new std::runtime_error("index out of range");
  return this->packages->at(which);
}

void lib::source::Platform::addPackage(std::string package) {
  if (this->containsPackage(package))
    throw new std::runtime_error("such package already exists");
  this->packages->push_back(package);
  this->dump();
}

void lib::source::Platform::deletePackage(std::string package) {
  if (!(this->containsPackage(package)))
    throw new std::runtime_error("such package doesn't exists");
  this->packages->erase(this->findPackage(package));
  this->dump();
}

void lib::source::Platform::renamePackage(std::string package, std::string newname) {
  if (this->containsPackage(newname))
    throw new std::runtime_error("such package already exists");
  if (!(this->containsPackage(package)))
    throw new std::runtime_error("such package doesn't exists");
  auto it = this->findPackage(package);
  *it = newname;
  this->dump();
}

bool lib::source::Platform::containsPackage(std::string package) {
  auto it = this->findPackage(package);
  return it != this->packages->end();
}

std::vector<std::string>::iterator lib::source::Platform::findPackage(std::string package) {
  return std::find(this->packages->begin(), this->packages->end(), package);
}

std::string lib::source::Platform::toString() {
  std::string string = "(source:platform :packages '(";
  string += boost::algorithm::join(*(this->packages), " ");
  return string + "))";
}

void lib::source::Platform::load() {
    YAML::Node document;
  try {
    document = YAML::LoadFile(this->getIndexPath());
  } catch(...) {
    throw new std::runtime_error("");
  }
  YAML::Node packages = document["packages"];
  if (packages.Type() != YAML::NodeType::Sequence)
    throw new std::runtime_error("wrong source index file format");

  this->packages = new std::vector<std::string>();
  for (YAML::const_iterator it = packages.begin(); it != packages.end(); it++)
    this->packages->push_back(it->as<std::string>());
}

void lib::source::Platform::dump() {
  YAML::Node document;
  for (auto it = this->packages->begin(); it != this->packages->end(); it++)
    document["packages"].push_back(*it);
  std::ofstream output; output.open(this->getIndexPath());
  output << document; output.close();
}
