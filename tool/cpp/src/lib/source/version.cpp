#include<lib/source/version.hpp>
#include<lib/types/string_list.hpp>
#include<lib/types/index_file.hpp>
#include<fstream>

lib::source::Version::Version(std::string path) : IndexFile(path) {
  this->load();
}

lib::source::Version::~Version() {
  delete this->filesToInstall;
  delete this->filesAsSupport;
  delete this->softwares;
  delete this->installCommands;
  delete this->uninstallCommands;
}

long unsigned int lib::source::Version::getNumberOfFilesToInstall() {
  return this->filesToInstall->size();
}

long unsigned int lib::source::Version::getNumberOfFilesAsSupport() {
  return this->filesAsSupport->size();
}

long unsigned int lib::source::Version::getNumberOfSoftwares() {
  return this->softwares->size();
}

long unsigned int lib::source::Version::getNumberOfInstallCommands() {
  return this->installCommands->size();
}

long unsigned int lib::source::Version::getNumberOfUninstallCommands() {
  return this->uninstallCommands->size();
}

std::string lib::source::Version::getFileToInstall(long unsigned int which) {
  return this->filesToInstall->get(which);
}

std::string lib::source::Version::getFileAsSupport(long unsigned int which) {
  return this->filesAsSupport->get(which);
}

std::string lib::source::Version::getSoftware(long unsigned int which) {
  return this->softwares->get(which);
}

std::string lib::source::Version::getInstallCommand(long unsigned int which) {
  return this->installCommands->get(which);
}

std::string lib::source::Version::getUninstallCommand(long unsigned int which) {
  return this->uninstallCommands->get(which);
}

void lib::source::Version::addFileToInstall(std::string file) {
  this->filesToInstall->add(file);
}

void lib::source::Version::addFileAsSupport(std::string file) {
  this->filesAsSupport->add(file);
}

void lib::source::Version::addSoftware(std::string software) {
  this->softwares->add(software);
}

void lib::source::Version::addInstallCommand(std::string command) {
  this->installCommands->add(command);
}

void lib::source::Version::addUninstallCommand(std::string command) {
  this->uninstallCommands->add(command);
}

void lib::source::Version::renameFileToInstall(std::string file,
                                               std::string newname) {
  this->filesToInstall->set(file, newname);
}

void lib::source::Version::renameFileAsSupport(std::string file,
                                               std::string newname) {
  this->filesAsSupport->set(file, newname);
}

void lib::source::Version::renameSoftware(std::string software,
                                          std::string newname) {
  this->softwares->set(software, newname);
}

void lib::source::Version::renameInstallCommand(std::string command,
                                                std::string newname) {
  this->installCommands->set(command, newname);
}

void lib::source::Version::renameUninstallCommand(std::string command,
                                                  std::string newname) {
  this->uninstallCommands->set(command, newname);
}

void lib::source::Version::deleteFileToInstall(std::string file) {
  this->filesToInstall->del(file);
}

void lib::source::Version::deleteFileAsSupport(std::string file) {
  this->filesAsSupport->del(file);
}

void lib::source::Version::deleteSoftware(std::string software) {
  this->softwares->del(software);
}

void lib::source::Version::deleteInstallCommand(std::string command) {
  this->installCommands->del(command);
}

void lib::source::Version::deleteUninstallCommand(std::string command) {
  this->uninstallCommands->del(command);
}

std::string lib::source::Version::toString() {
  std::string string = "(source:version";
  string += " :files-to-install " + this->filesToInstall->toString();
  string += " :files-as-support " + this->filesAsSupport->toString();
  string += " :softwares " + this->softwares->toString();
  string += " :install-commands " + this->installCommands->toString();
  string += " :uninstall-commands " + this->uninstallCommands->toString();
  return string + ")";
}

void lib::source::Version::load() {
  YAML::Node document;
  try {
    document = YAML::LoadFile(this->getIndexPath());
  } catch(...) {
    throw new std::runtime_error("couldn't load source index file: " + this->getIndexPath() + " doesn't exists");
  }

  this->filesToInstall = new lib::types::StringList();
  this->filesAsSupport = new lib::types::StringList();
  this->softwares = new lib::types::StringList();
  this->installCommands = new lib::types::StringList();
  this->uninstallCommands = new lib::types::StringList();

  if (document["files"]) {
    if (document["files"]["install"])
      this->filesToInstall->load(document["files"]["install"]);
    if (document["files"]["support"])
      this->filesAsSupport->load(document["files"]["support"]);
  }
  if (document["softwares"])
    this->softwares->load(document["softwares"]);
  if (document["install"])
    this->installCommands->load(document["install"]);
  if (document["uninstall"])
    this->installCommands->load(document["uninstall"]);
}

void lib::source::Version::dump() {
  YAML::Node document;
  document["files"]["install"] = this->filesToInstall->dump();
  document["files"]["support"] = this->filesAsSupport->dump();
  document["softwares"] = this->softwares->dump();
  document["install"] = this->installCommands->dump();
  document["uninstall"] = this->uninstallCommands->dump();
  std::ofstream output; output.open(this->getIndexPath());
  output << document; output.close();
}

void lib::source::Version::commit() {
  this->dump();
}
