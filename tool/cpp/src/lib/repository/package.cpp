#include<lib/repository/package.hpp>
#include<yaml-cpp/yaml.h>
#include<boost/algorithm/string/join.hpp>
#include<fstream>
#include<stdexcept>
#include<algorithm>

lib::repository::Package::Package(std::string path) : lib::types::IndexFile(path) {
  this->load();
}

lib::repository::Package::~Package() {
  delete this->versions;
  delete this->depends;
}

long unsigned int lib::repository::Package::getNumberOfVersions() {
  return this->versions->size();
}

lib::types::Semver lib::repository::Package::getVersion(long unsigned int which) {
  return this->versions->get(which);
}

void lib::repository::Package::addVersion(lib::types::Semver version) {
  this->versions->add(version);
  this->dump();
}

void lib::repository::Package::deleteVersion(lib::types::Semver version) {
  this->versions->del(version);
  this->dump();
}

void lib::repository::Package::renameVersion(lib::types::Semver version, lib::types::Semver newname) {
  this->versions->set(version, newname);
  this->dump();
}

bool lib::repository::Package::containsVersion(lib::types::Semver version) {
  return this->versions->contains(version);
}

long unsigned int lib::repository::Package::getNumberOfDependencies() {
  return this->depends->size();
}

std::string lib::repository::Package::getDependency(long unsigned int which) {
  return this->depends->get(which);    
}

void lib::repository::Package::addDependency(std::string dependency) {
  this->depends->add(dependency);
  this->dump();
}

void lib::repository::Package::deleteDependency(std::string dependency) {
  this->depends->del(dependency);
  this->dump();
}

void lib::repository::Package::renameDependency(std::string dependency, std::string newname) {
  this->depends->set(dependency, newname);
  this->dump();
}

bool lib::repository::Package::containsDependency(std::string dependency) {
  return this->depends->contains(dependency);
}

void lib::repository::Package::setUrl(std::string url) {
  this->url = url;
}

void lib::repository::Package::setDescription(std::string description) {
  this->description = description;
}

void lib::repository::Package::setLicense(std::string license) {
  this->license = license;
}

std::string lib::repository::Package::getUrl() {
  return this->url;
}

std::string lib::repository::Package::getDescription() {
  return this->description;
}

std::string lib::repository::Package::getLicense() {
  return this->license;
}

std::string lib::repository::Package::toString() {
  std::string string = "(repository:package";
  string += " :versions " + this->versions->toString();
  string += " :depends " + this->depends->toString();
  string += " :url \"" + this->url + "\"";
  string += " :description \"" + this->description + "\"";
  string += " :license \"" + this->license + "\"";
  return string + ")";
}

void lib::repository::Package::load() {
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

void lib::repository::Package::dump() {
  YAML::Node document;
  document["versions"] = this->versions->dump();
  document["depends"] = this->depends->dump();

  document["url"] = this->url;
  document["description"] = this->description;
  document["license"] = this->license;
  
  std::ofstream output; output.open(this->getIndexPath());
  output << document; output.close();
}
