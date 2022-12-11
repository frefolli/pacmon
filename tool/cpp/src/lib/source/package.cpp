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
  if (which > this->getNumberOfVersions())
    throw new std::runtime_error("index out of range");
  return this->versions->at(which);
}

void lib::source::Package::addVersion(lib::types::Semver version) {
  if (this->containsVersion(version))
    throw new std::runtime_error("such version already exists");
  this->versions->push_back(version);
  this->dump();
}

void lib::source::Package::deleteVersion(lib::types::Semver version) {
  if (!(this->containsVersion(version)))
    throw new std::runtime_error("such version doesn't exists");
  this->versions->erase(this->findVersion(version));
  this->dump();
}

void lib::source::Package::renameVersion(lib::types::Semver version, lib::types::Semver newname) {
  if (this->containsVersion(newname))
    throw new std::runtime_error("such version already exists");
  if (!(this->containsVersion(version)))
    throw new std::runtime_error("such version doesn't exists");
  auto it = this->findVersion(version);
  *it = newname;
  this->dump();
}

bool lib::source::Package::containsVersion(lib::types::Semver version) {
  auto it = this->findVersion(version);
  return it != this->versions->end();
}

long unsigned int lib::source::Package::getNumberOfDependencies() {
    return this->depends->size();
}

std::string lib::source::Package::getDependency(long unsigned int which) {
    if (which > this->getNumberOfDependencies())
        throw new std::runtime_error("index out of range");
      return this->depends->at(which);    
}

void lib::source::Package::addDependency(std::string dependency) {
  if (this->containsDependency(dependency))
    throw new std::runtime_error("such dependency already exists");
  this->depends->push_back(dependency);
  this->dump();
}

void lib::source::Package::deleteDependency(std::string dependency) {
if (!(this->containsDependency(dependency)))
    throw new std::runtime_error("such dependency doesn't exists");
  this->depends->erase(this->findDependency(dependency));
  this->dump();
}

void lib::source::Package::renameDependency(std::string dependency, std::string newname) {
    if (this->containsDependency(newname))
        throw new std::runtime_error("such dependency already exists");
      if (!(this->containsDependency(dependency)))
        throw new std::runtime_error("such dependency doesn't exists");
      auto it = this->findDependency(dependency);
      *it = newname;
      this->dump();
}

bool lib::source::Package::containsDependency(std::string dependency) {
  auto it = this->findDependency(dependency);
  return it != this->depends->end();
}

std::vector<lib::types::Semver>::iterator lib::source::Package::findVersion(lib::types::Semver version) {
  return std::find(this->versions->begin(), this->versions->end(), version);
}

std::vector<std::string>::iterator lib::source::Package::findDependency(std::string dependency) {
  return std::find(this->depends->begin(), this->depends->end(), dependency);
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
  std::vector<std::string> versionStrings;
  for (auto it = this->versions->begin(); it != this->versions->end(); it++)
      versionStrings.push_back(it->toString());
  string += " :versions '(" + boost::algorithm::join(versionStrings, " ") + ")";
  string += " :depends '(" + boost::algorithm::join(*(this->depends), " ") + ")";
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

  YAML::Node versions = document["versions"];
  this->versions = new std::vector<lib::types::Semver>();
  for (YAML::const_iterator it = versions.begin(); it != versions.end(); it++)
    this->versions->push_back(lib::types::Semver(it->as<std::string>()));

  YAML::Node depends = document["depends"];
  this->depends = new std::vector<std::string>();
  for (YAML::const_iterator it = depends.begin(); it != depends.end(); it++)
    this->depends->push_back(it->as<std::string>());

  this->url = document["url"].as<std::string>();
  this->description = document["description"].as<std::string>();
  this->license = document["license"].as<std::string>();
}

void lib::source::Package::dump() {
  YAML::Node document;
  for (auto it = this->versions->begin(); it != this->versions->end(); it++)
    document["versions"].push_back(it->toString());
  for (auto it = this->depends->begin(); it != this->depends->end(); it++)
    document["depends"].push_back(*it);
  document["url"] = this->url;
  document["description"] = this->description;
  document["license"] = this->license;
  
  std::ofstream output; output.open(this->getIndexPath());
  output << document; output.close();
}
