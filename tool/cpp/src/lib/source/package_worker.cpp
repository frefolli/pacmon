#include <lib/source/package_worker.hpp>
#include <lib/source/package.hpp>
#include <stdexcept>
#include <lib/system/file_manager.hpp>

lib::source::PackageWorker::PackageWorker(std::string path)
: lib::types::Worker(path) {}

lib::source::PackageWorker::PackageWorker()
: lib::types::Worker() {}

lib::source::PackageWorker::~PackageWorker() {}

// actions
void lib::source::PackageWorker::doInit() {
  if (lib::system::FileManager::existsFile(getPath()))
    throw std::exception();
  lib::system::FileManager::createFile(getIndexPath());
  lib::source::Package index (getPath()); index.commit();
}

void lib::source::PackageWorker::checkCoherence() {
  if (lib::system::FileManager::existsFile(getPath()))
    throw std::exception();
  lib::source::Package index (getPath());
  // TODO
}

void lib::source::PackageWorker::printAll() {
  if (lib::system::FileManager::existsFile(getPath()))
    throw std::exception();
  lib::source::Package index (getPath());
  // TODO
}

std::string lib::source::PackageWorker::getVersionPath(std::string version) {
  return getPath() + "/" + version;
}

void lib::source::PackageWorker::listVersions() {
  if (lib::system::FileManager::existsFile(getPath()))
    throw std::exception();
  lib::source::Package index (getPath());
  std::printf("\t\tsource :: versions {");
  for (long unsigned int i = 0; i < index.getNumberOfVersions(); i++) {
    std::printf("\t\t\t[%i] - %s\n", i, index.getVersion(i).toString().c_str());
  }
  std::printf("\t\t}");
}

void lib::source::PackageWorker::listDependencies() {
  // TODO
}

void lib::source::PackageWorker::printLicense() {
  // TODO
}

void lib::source::PackageWorker::printUrl() {
  // TODO
}

void lib::source::PackageWorker::printDescription() {
  // TODO
}

void lib::source::PackageWorker::setLicense(std::string license) {
  // TODO
}

void lib::source::PackageWorker::setUrl(std::string url) {
  // TODO
}

void lib::source::PackageWorker::setDescription(std::string description) {
  // TODO
}

void lib::source::PackageWorker::addVersion(std::string version) {
  // TODO
}

void lib::source::PackageWorker::addDependency(std::string dependency) {
  // TODO
}

void lib::source::PackageWorker::removeVersion(std::string version) {
  // TODO
}

void lib::source::PackageWorker::removeDependency(std::string dependency) {
  // TODO
}

void lib::source::PackageWorker::renameVersion(std::string version, std::string newname) {
  // TODO
}

void lib::source::PackageWorker::renameDependency(std::string dependency, std::string newname) {
  // TODO
}

void lib::source::PackageWorker::forkVersion(std::string version, std::string clonename) {
  // TODO
}

// access
lib::source::VersionWorker
lib::source::PackageWorker::getVersionWorker(std::string version) {
  // TODO
}
