#include<lib/source/source.hpp>
#include<yaml-cpp/yaml.h>
#include<boost/algorithm/string/join.hpp>
#include<fstream>
#include<stdexcept>
#include<algorithm>

lib::source::Source::Source(std::string path) {
  this->path = path;
  this->load();
}

lib::source::Source::~Source() {
  delete this->platforms;
}

long unsigned int lib::source::Source::getNumberOfPlatforms() {
  return this->platforms->size();
}

std::string lib::source::Source::getPlatform(long unsigned int which) {
  if (which > this->getNumberOfPlatforms())
    throw new std::runtime_error("index out of range");
  return this->platforms->at(which);
}

void lib::source::Source::addPlatform(std::string platform) {
  if (this->containsPlatform(platform))
    throw new std::runtime_error("such platform already exists");
  this->platforms->push_back(platform);
  this->dump();
}

void lib::source::Source::deletePlatform(std::string platform) {
  if (!(this->containsPlatform(platform)))
    throw new std::runtime_error("such platform doesn't exists");
  this->platforms->erase(this->findPlatform(platform));
  this->dump();
}

void lib::source::Source::renamePlatform(std::string platform, std::string newname) {
  if (this->containsPlatform(newname))
    throw new std::runtime_error("such platform already exists");
  if (!(this->containsPlatform(platform)))
    throw new std::runtime_error("such platform doesn't exists");
  auto it = this->findPlatform(platform);
  *it = newname;
  this->dump();
}

bool lib::source::Source::containsPlatform(std::string platform) {
  auto it = this->findPlatform(platform);
  return it != this->platforms->end();
}

std::vector<std::string>::iterator lib::source::Source::findPlatform(std::string platform) {
  return std::find(this->platforms->begin(), this->platforms->end(), platform);
}

std::string lib::source::Source::toString() {
  std::string string = "(source:source :platforms '(";
  string += boost::algorithm::join(*(this->platforms), " ");
  return string + "))";
}

void lib::source::Source::load() {
  YAML::Node document = YAML::LoadFile(this->path + "/index.yml");
  if (! document["platforms"])
    throw new std::runtime_error("source index file is empty or doesn't exists");

  YAML::Node platforms = document["platforms"];
  if (! platforms.Type() == YAML::NodeType::Sequence)
    throw new std::runtime_error("wrong source index file format");

  this->platforms = new std::vector<std::string>();
  for (YAML::const_iterator it = platforms.begin(); it != platforms.end(); it++)
    this->platforms->push_back(it->as<std::string>());
}

void lib::source::Source::dump() {
  YAML::Node document;
  for (auto it = this->platforms->begin(); it != this->platforms->end(); it++)
    document["platforms"].push_back(*it);
  std::ofstream output; output.open(this->path + "/index.yml");
  output << document; output.close();
}
