#include<lib/repository/repository.hpp>
#include<yaml-cpp/yaml.h>
#include<fstream>
#include<lib/exceptions/invalid_repository_index_file_path.hpp>

lib::repository::Repository::Repository(std::string path) : lib::types::IndexFile(path) {
  this->load();
}

lib::repository::Repository::~Repository() {
  delete this->platforms;
}

long unsigned int lib::repository::Repository::getNumberOfPlatforms() {
  return this->platforms->size();
}

std::string lib::repository::Repository::getPlatform(long unsigned int which) {
  return this->platforms->get(which);
}

void lib::repository::Repository::addPlatform(std::string platform) {
  this->platforms->add(platform);
}

void lib::repository::Repository::deletePlatform(std::string platform) {
  this->platforms->del(platform);
}

void lib::repository::Repository::renamePlatform(std::string platform, std::string newname) {
  this->platforms->set(platform, newname);
}

bool lib::repository::Repository::containsPlatform(std::string platform) {
  return this->platforms->contains(platform);
}

std::string lib::repository::Repository::toString() {
  std::string string = "(repository:repository";
  string += " :platforms " + this->platforms->toString();
  return string + ")";
}

void lib::repository::Repository::load() {
  YAML::Node document;
  try {
    document = YAML::LoadFile(this->getIndexPath());
  } catch(...) {
    throw lib::exceptions::InvalidRepositoryIndexFilePath(this->getIndexPath());
  }

  this->platforms = new lib::types::StringList();
  if (document["platforms"]) {
    this->platforms->load(document["platforms"]);
  }
}

void lib::repository::Repository::dump() {
  YAML::Node document;
  document["platforms"] = this->platforms->dump();
  std::ofstream output; output.open(this->getIndexPath());
  output << document; output.close();
}

void lib::repository::Repository::commit() {
  this->dump();
}
