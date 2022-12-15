#include<lib/source/source.hpp>
#include<yaml-cpp/yaml.h>
#include<fstream>
#include<stdexcept>
#include<algorithm>

lib::source::Source::Source(std::string path) : lib::types::IndexFile(path) {
  this->load();
}

lib::source::Source::~Source() {
  delete this->platforms;
}

long unsigned int lib::source::Source::getNumberOfPlatforms() {
  return this->platforms->size();
}

std::string lib::source::Source::getPlatform(long unsigned int which) {
  return this->platforms->get(which);
}

void lib::source::Source::addPlatform(std::string platform) {
  this->platforms->add(platform);
}

void lib::source::Source::deletePlatform(std::string platform) {
  this->platforms->del(platform);
}

void lib::source::Source::renamePlatform(std::string platform, std::string newname) {
  this->platforms->set(platform, newname);
}

bool lib::source::Source::containsPlatform(std::string platform) {
  return this->platforms->contains(platform);
}

std::string lib::source::Source::toString() {
  std::string string = "(source:source";
  string += " :platforms " + this->platforms->toString();
  return string + ")";
}

void lib::source::Source::load() {
  YAML::Node document;
  try {
    document = YAML::LoadFile(this->getIndexPath());
  } catch(...) {
    throw new std::runtime_error("couldn't load source index file: " + this->getIndexPath() + " doesn't exists");
  }

  this->platforms = new lib::types::StringList();
  if (document["platforms"]) {
    this->platforms->load(document["platforms"]);
  }
}

void lib::source::Source::dump() {
  YAML::Node document;
  document["platforms"] = this->platforms->dump();
  std::ofstream output; output.open(this->getIndexPath());
  output << document; output.close();
}

void lib::source::Source::commit() {
  this->dump();
}
