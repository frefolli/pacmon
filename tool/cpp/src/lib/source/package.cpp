#include<lib/source/package.hpp>
#include<yaml-cpp/yaml.h>
#include<boost/algorithm/string/join.hpp>
#include<fstream>
#include<stdexcept>
#include<algorithm>

lib::source::Package::Package(std::string path) : lib::types::IndexFile(path) {
  this->load();
}

lib::source::Package::~Package() {
  delete this->versions;
  delete this->depends;
}

long unsigned int lib::source::Package::getNumberOfVersions() {
  return this->versions->size();
}

lib::types::Semver lib::source::Package::getVersion(long unsigned int which) {
  return this->versions->get(which);
}

void lib::source::Package::addVersion(lib::types::Semver version) {
  this->versions->add(version);
}

void lib::source::Package::deleteVersion(lib::types::Semver version) {
  this->versions->del(version);
}

void lib::source::Package::renameVersion(lib::types::Semver version, lib::types::Semver newname) {
  this->versions->set(version, newname);
}

bool lib::source::Package::containsVersion(lib::types::Semver version) {
  return this->versions->contains(version);
}

long unsigned int lib::source::Package::getNumberOfDependencies() {
  return this->depends->size();
}

std::string lib::source::Package::getDependency(long unsigned int which) {
  return this->depends->get(which);    
}

void lib::source::Package::addDependency(std::string dependency) {
  this->depends->add(dependency);
}

void lib::source::Package::deleteDependency(std::string dependency) {
  this->depends->del(dependency);
}

void lib::source::Package::renameDependency(std::string dependency, std::string newname) {
  this->depends->set(dependency, newname);
}

bool lib::source::Package::containsDependency(std::string dependency) {
  return this->depends->contains(dependency);
}

void lib::source::Package::setUrl(std::string url) {
  this->url = url;
}

void lib::source::Package::setDescription(std::string description) {
  this->description = description;
}

void lib::source::Package::setLicense(std::string license) {
  this->license = license;
}

std::string lib::source::Package::getUrl() {
  return this->url;
}

std::string lib::source::Package::getDescription() {
  return this->description;
}

std::string lib::source::Package::getLicense() {
  return this->license;
}

std::string lib::source::Package::toString() {
  std::string string = "(source:package";
  string += " :versions " + this->versions->toString();
  string += " :depends " + this->depends->toString();
  string += " :url \"" + this->url + "\"";
  string += " :description \"" + this->description + "\"";
  string += " :license \"" + this->license + "\"";
  return string + ")";
}

void lib::source::Package::load() {
  YAML::Node document;
  try {
    document = YAML::LoadFile(this->getIndexPath());
  } catch(...) {
    throw new std::runtime_error("");
  }

  this->versions = new lib::types::SemverList();
  this->versions->load(document["versions"]);

  this->depends = new lib::types::StringList();
  this->depends->load(document["depends"]);
  
  this->url = document["url"].as<std::string>();
  this->description = document["description"].as<std::string>();
  this->license = document["license"].as<std::string>();
}

void lib::source::Package::dump() {
  YAML::Node document;
  document["versions"] = this->versions->dump();
  document["depends"] = this->depends->dump();

  document["url"] = this->url;
  document["description"] = this->description;
  document["license"] = this->license;
  
  std::ofstream output; output.open(this->getIndexPath());
  output << document; output.close();
}

void lib::source::Package::commit() {
  this->dump();
}
