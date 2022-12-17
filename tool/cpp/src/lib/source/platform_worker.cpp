#include <lib/source/platform_worker.hpp>

lib::source::PlatformWorker::PlatformWorker(std::string path) {
  // TODO
}

lib::source::PlatformWorker::PlatformWorker() {
  // TODO
}

lib::source::PlatformWorker::~PlatformWorker() {
  // TODO
}

// actions
void lib::source::PlatformWorker::doInit() {
  // TODO
}

void lib::source::PlatformWorker::checkCoherence() {
  // TODO
}

void lib::source::PlatformWorker::printAll() {
  // TODO
}

void lib::source::PlatformWorker::listPackages(std::string package) {
  // TODO
}

void lib::source::PlatformWorker::addPackage(std::string package) {
  // TODO
}

void lib::source::PlatformWorker::removePackage(std::string package) {
  // TODO
}

void lib::source::PlatformWorker::renamePackage(std::string package, std::string newname) {
  // TODO
}

void lib::source::PlatformWorker::forkPackage(std::string package, std::string clonename) {
  // TODO
}

// access
lib::source::PackageWorker
lib::source::PlatformWorker::getPackageWorker(std::string package) {
  // TODO
}

lib::source::VersionWorker
lib::source::PlatformWorker::getVersionWorker(std::string package,
                                              std::string version) {
  // TODO
}
