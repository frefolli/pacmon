#include<lib/repository/version.hpp>
#include<lib/types/string_list.hpp>
#include<lib/types/index_file.hpp>
#include<fstream>

lib::repository::Version::Version(std::string path) : IndexFile(path) {
  this->load();
}

lib::repository::Version::~Version() {
  delete this->filesToInstall;
  delete this->filesAsSupport;
  delete this->softwares;
  delete this->installCommands;
  delete this->uninstallCommands;
}

std::string lib::repository::Version::getPlatform() {
  return this->platform;
}

std::string lib::repository::Version::getPackage() {
  return this->package;
}

std::string lib::repository::Version::getLicense() {
  return this->license;
}

std::string lib::repository::Version::getDescription() {
  return this->description;
}

std::string lib::repository::Version::getUrl() {
  return this->url;
}

lib::types::Semver lib::repository::Version::getVersion() {
  return this->version->toString();
}

void lib::repository::Version::setPlatform(std::string platform) {
  this->platform = platform;
}

void lib::repository::Version::setPackage(std::string package) {
  this->package = package;
}

void lib::repository::Version::setLicense(std::string license) {
  this->license = license;
}

void lib::repository::Version::setUrl(std::string url) {
  this->url = url;
}

void lib::repository::Version::setDescription(std::string description) {
  this->description = description;
}

void lib::repository::Version::setVersion(lib::types::Semver version) {
  this->version->setAll(version.toString());
}

long unsigned int lib::repository::Version::getNumberOfFilesToInstall() {
  return this->filesToInstall->size();
}

long unsigned int lib::repository::Version::getNumberOfFilesAsSupport() {
  return this->filesAsSupport->size();
}

long unsigned int lib::repository::Version::getNumberOfSoftwares() {
  return this->softwares->size();
}

long unsigned int lib::repository::Version::getNumberOfInstallCommands() {
  return this->installCommands->size();
}

long unsigned int lib::repository::Version::getNumberOfUninstallCommands() {
  return this->uninstallCommands->size();
}

long unsigned int lib::repository::Version::getNumberOfDependencies() {
  return this->depends->size();
}

std::string lib::repository::Version::getFileToInstall(long unsigned int which) {
  return this->filesToInstall->get(which);
}

std::string lib::repository::Version::getFileAsSupport(long unsigned int which) {
  return this->filesAsSupport->get(which);
}

std::string lib::repository::Version::getFileHash(long unsigned int which) {
  return this->fileHashes->get(which);
}

std::string lib::repository::Version::getSoftware(long unsigned int which) {
  return this->softwares->get(which);
}

std::string lib::repository::Version::getInstallCommand(long unsigned int which) {
  return this->installCommands->get(which);
}

std::string lib::repository::Version::getUninstallCommand(long unsigned int which) {
  return this->uninstallCommands->get(which);
}

std::string lib::repository::Version::getDependency(long unsigned int which) {
  return this->depends->get(which);
}

void lib::repository::Version::addFileToInstall(std::string file) {
  this->filesToInstall->add(file);
}

void lib::repository::Version::addFileAsSupport(std::string file) {
  this->filesAsSupport->add(file);
}

void lib::repository::Version::addSoftware(std::string software) {
  this->softwares->add(software);
}

void lib::repository::Version::addInstallCommand(std::string command) {
  this->installCommands->add(command);
}

void lib::repository::Version::addUninstallCommand(std::string command) {
  this->uninstallCommands->add(command);
}

void lib::repository::Version::addDependency(std::string dependency) {
  this->depends->add(dependency);
}

void lib::repository::Version::renameFileToInstall(std::string file,
						   std::string newname) {
  this->filesToInstall->set(file, newname);
}

void lib::repository::Version::renameFileAsSupport(std::string file,
						   std::string newname) {
  this->filesAsSupport->set(file, newname);
}

void lib::repository::Version::renameSoftware(std::string software,
					      std::string newname) {
  this->softwares->set(software, newname);
}

void lib::repository::Version::renameInstallCommand(std::string command,
						    std::string newname) {
  this->installCommands->set(command, newname);
}

void lib::repository::Version::renameUninstallCommand(std::string command,
						      std::string newname) {
  this->uninstallCommands->set(command, newname);
}

void lib::repository::Version::renameDependency(std::string dependency, std::string newname) {
  this->depends->set(dependency, newname);
}

void lib::repository::Version::deleteFileToInstall(std::string file) {
  this->filesToInstall->del(file);
}

void lib::repository::Version::deleteFileAsSupport(std::string file) {
  this->filesAsSupport->del(file);
}

void lib::repository::Version::deleteSoftware(std::string software) {
  this->softwares->del(software);
}

void lib::repository::Version::deleteInstallCommand(std::string command) {
  this->installCommands->del(command);
}

void lib::repository::Version::deleteUninstallCommand(std::string command) {
  this->uninstallCommands->del(command);
}

void lib::repository::Version::deleteDependency(std::string dependency) {
  this->depends->del(dependency);
}

std::string lib::repository::Version::toString() {
  std::string string = "(repository:version";
  string += " :platform " + this->platform;
  string += " :package " + this->package;
  string += " :version " + this->version->toString();
  string += " :license " + this->license;
  string += " :description " + this->description;
  string += " :url " + this->url;
  string += " :files-to-install " + this->filesToInstall->toString();
  string += " :files-as-support " + this->filesAsSupport->toString();
  string += " :file-hashes " + this->fileHashes->toString();
  string += " :softwares " + this->softwares->toString();
  string += " :install-commands " + this->installCommands->toString();
  string += " :uninstall-commands " + this->uninstallCommands->toString();
  string += " :files-as-support " + this->filesAsSupport->toString();
  return string + ")";
}

void lib::repository::Version::load() {
  YAML::Node document;
  try {
    document = YAML::LoadFile(this->getIndexPath());
  } catch(...) {
    throw new std::runtime_error("couldn't load repository index file: " + this->getIndexPath() + " doesn't exists");
  }

  this->filesToInstall = new lib::types::StringList();
  this->filesAsSupport = new lib::types::StringList();
  this->fileHashes = new lib::types::StringList();
  this->softwares = new lib::types::StringList();
  this->installCommands = new lib::types::StringList();
  this->uninstallCommands = new lib::types::StringList();

  if (document["files"]) {
    this->filesToInstall->load(document["files"]["install"]);
    this->filesAsSupport->load(document["files"]["support"]);
    this->fileHashes->load(document["files"]["hashes"]);
  }

  this->softwares->load(document["softwares"]);
  this->installCommands->load(document["install"]);
  this->installCommands->load(document["uninstall"]);

  this->url = document["url"].as<std::string>();
  this->description = document["description"].as<std::string>();
  this->license = document["license"].as<std::string>();
  this->platform = document["platform"].as<std::string>();
  this->package = document["package"].as<std::string>();
  this->version = new lib::types::Semver(document["version"].as<std::string>());
}

void lib::repository::Version::dump() {
  YAML::Node document;
  document["files"]["install"] = this->filesToInstall->dump();
  document["files"]["support"] = this->filesAsSupport->dump();
  document["files"]["hashes"] = this->fileHashes->dump();

  document["softwares"] = this->softwares->dump();
  document["install"] = this->installCommands->dump();
  document["uninstall"] = this->uninstallCommands->dump();

  document["platform"] = this->platform;
  document["package"] = this->package;
  document["version"] = this->version->toString();
  document["license"] = this->license;
  document["description"] = this->description;
  document["url"] = this->url;

  std::ofstream output; output.open(this->getIndexPath());
  output << document; output.close();
}
