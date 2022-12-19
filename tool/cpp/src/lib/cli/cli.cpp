#include <lib/cli/cli.hpp>

lib::cli::CLI::CLI() {
  // TODO
}

lib::cli::CLI::~CLI() {
  // TODO
}

void lib::cli::CLI::setName(std::string name) {
  // TODO
}

void lib::cli::CLI::setDescription(std::string description) {
  // TODO
}

void lib::cli::CLI::setAuthor(std::string author) {
  // TODO
}

void lib::cli::CLI::setDate(std::string date) {
  // TODO
}

void lib::cli::CLI::setVersion(std::string version) {
  // TODO
}

void lib::cli::CLI::parseArgs(int argc, char** args) {
  std::vector<std::string>* vct = new std::vector<std::string>(args + 1, args + argc);
  this->parseArgs(vct);
  delete vct;
}

void lib::cli::CLI::parseArgs(std::vector<std::string>* args) {
  // TODO
}
