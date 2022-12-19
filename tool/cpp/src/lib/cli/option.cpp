#include <lib/cli/option.hpp>

lib::cli::Option::Option() {
  // TODO
}

lib::cli::Option::~Option() {
  // TODO
}

void lib::cli::Option::help() {
  // TODO
}

std::string lib::cli::Option::getDescription() {
  return this->description;
}

std::string lib::cli::Option::getLongTrigger() {
  return this->longTrigger;
}

std::string lib::cli::Option::getShortTrigger() {
  return this->shortTrigger;
}

void lib::cli::Option::setDescription(std::string description) {
  this->description = description;
}

void lib::cli::Option::setLongTrigger(std::string longTrigger) {
  this->longTrigger = longTrigger;
}

void lib::cli::Option::setShortTrigger(std::string shortTrigger) {
  this->shortTrigger = shortTrigger;
}

unsigned int lib::cli::Option::parseArgs(int argc, char** args) {
  std::vector<std::string>* vct = new std::vector<std::string>(args + 1, args + argc);
  unsigned int retval = this->parseArgs(vct);
  delete vct; return retval;
}

unsigned int lib::cli::Option::parseArgs(std::vector<std::string>* args) {
  return this->parseArgs(args->begin(), args->end());
}

unsigned int lib::cli::Option::parseArgs(std::vector<std::string>::iterator begin,
                               std::vector<std::string>::iterator end) {
  // TODO
}
