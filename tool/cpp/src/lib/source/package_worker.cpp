#include <lib/source/package_worker.hpp>

lib::source::PackageWorker::PackageWorker(std::string path) {
  // TODO
}

lib::source::PackageWorker::PackageWorker() {
  // TODO
}

lib::source::PackageWorker::~PackageWorker() {
  // TODO
}

// actions
void lib::source::PackageWorker::doInit() {
  // TODO
}

void lib::source::PackageWorker::checkCoherence() {
  // TODO
}

void lib::source::PackageWorker::printAll() {
  // TODO
}

void lib::source::PackageWorker::listVersions(std::string version) {
  // TODO
}

void lib::source::PackageWorker::listDependencies(std::string dependency) {
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
lib::source::VersionWorker*
lib::source::PackageWorker::getVersionWorker(std::string version) {
  // TODO
}
