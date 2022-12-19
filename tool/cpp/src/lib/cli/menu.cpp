#include <lib/cli/menu.hpp>

/* Options will have shortcuts, so i'm gonna register twice this
 * shortcuts and then when i delete them i remove both long and short forms
 * */
lib::cli::Menu::Menu() {
  this->options = new std::map<std::string, lib::cli::Option*>();
  this->menus = new std::map<std::string, lib::cli::Menu*>();
}

lib::cli::Menu::~Menu() {
  while(this->options->size() > 0) {
    lib::cli::Option* ptr = this->options->begin()->second;
    // remove its keys from options
    delete ptr;
  }
  delete this->options;
  //
  for (auto it = this->menus->begin(); it != this->menus->end(); it++)
    delete it->second;
  delete this->menus;
}

void lib::cli::Menu::setName(std::string name) {
  this->name = name;
}

void lib::cli::Menu::setDescription(std::string description) {
  this->description = description;
}

std::string lib::cli::Menu::getName() {
  return this->name;
}

std::string lib::cli::Menu::getDescription() {
  return this->description;
}

void lib::cli::Menu::addMenu(lib::cli::Menu* menu) {
  // TODO
}

void lib::cli::Menu::addOption(lib::cli::Option* option) {
  // TODO
}

std::map<std::string, lib::cli::Menu*>::iterator lib::cli::Menu::getMenu(std::string menu) {
  // TODO
}

std::map<std::string, lib::cli::Option*>::iterator lib::cli::Menu::getOption(std::string option) {
  // TODO
}

void lib::cli::Menu::help() {
  // TODO
}

void lib::cli::Menu::help(std::string something) {
  // TODO
}

unsigned int lib::cli::Menu::parseArgs(int argc, char** args) {
  std::vector<std::string>* vct = new std::vector<std::string>(args + 1, args + argc);
  unsigned int retval = this->parseArgs(vct);
  delete vct; return retval;
}

unsigned int lib::cli::Menu::parseArgs(std::vector<std::string>* args) {
  return this->parseArgs(args->begin(), args->end());
}

unsigned int lib::cli::Menu::parseArgs(std::vector<std::string>::iterator begin,
                               std::vector<std::string>::iterator end) {
  // TODO
}
