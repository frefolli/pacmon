#include <lib/source/source_worker.hpp>
#include <lib/source/source.hpp>
#include <stdexcept>
#include <lib/system/file_manager.hpp>

lib::source::SourceWorker::SourceWorker(std::string path)
: lib::types::Worker(path) {}

lib::source::SourceWorker::SourceWorker()
: lib::types::Worker() {}

lib::source::SourceWorker::~SourceWorker() {}

void lib::source::SourceWorker::doInit() {
  if (lib::system::FileManager::existsFile(getPath()))
    throw std::exception();
  lib::system::FileManager::createFile(getIndexPath());
  lib::source::Source index (getPath()); index.commit();
}

void lib::source::SourceWorker::checkCoherence() {
  if (lib::system::FileManager::existsFile(getPath()))
    throw std::exception();
  lib::source::Source index (getPath());
  // TODO
}

void lib::source::SourceWorker::printAll() {
  if (lib::system::FileManager::existsFile(getPath()))
    throw std::exception();
  lib::source::Source index (getPath());
  // TODO
}

std::string lib::source::SourceWorker::getPlatformPath(std::string platform) {
  return getPath() + "/" + platform;
}

void lib::source::SourceWorker::listPlatforms() {
  if (lib::system::FileManager::existsFile(getPath()))
    throw std::exception();
  lib::source::Source index (getPath());
  std::printf("source :: platforms {");
  for (long unsigned int i = 0; i < index.getNumberOfPlatforms(); i++) {
    std::printf("\t[%i] - %s\n", i, index.getPlatform(i).c_str());
  }
  std::printf("}");
}

void lib::source::SourceWorker::addPlatform(std::string platform) {
  if (lib::system::FileManager::existsFile(getPath()))
    throw std::exception();
  lib::source::Source index (getPath());
  index.addPlatform(platform);
  lib::system::FileManager::createDirectory(getPath() + "/" + platform);
  this->getPlatformWorker(platform).doInit();
  index.commit();
}

void lib::source::SourceWorker::removePlatform(std::string platform) {
  if (lib::system::FileManager::existsFile(getPath()))
    throw std::exception();
  lib::source::Source index (getPath());
  index.deletePlatform(platform);
  lib::system::FileManager::deleteDirectory(getPath() + "/" + platform);
  index.commit();
}

void lib::source::SourceWorker::renamePlatform(std::string platform,
                                                std::string newname) {
  if (lib::system::FileManager::existsFile(getPath()))
    throw std::exception();
  lib::source::Source index (getPath());
  index.renamePlatform(platform, newname);
  lib::system::FileManager::moveDirectory(getPath() + "/" + platform,
                                          getPath() + "/" + newname);
  index.commit();
}

void lib::source::SourceWorker::forkPlatform(std::string platform,
                                            std::string clonename) {
  if (lib::system::FileManager::existsFile(getPath()))
    throw std::exception();
  lib::source::Source index (getPath());
  if (! index.containsPlatform(platform))
    throw std::exception();
  index.addPlatform(clonename);
  lib::system::FileManager::copyDirectory(getPath() + "/" + platform,
                                          getPath() + "/" + clonename);
  index.commit();
}

lib::source::PlatformWorker
lib::source::SourceWorker::getPlatformWorker(std::string platform) {
  if (lib::system::FileManager::existsFile(getPath()))
    throw std::exception();
  return lib::source::PlatformWorker(getPath() + "/" + platform);
}

lib::source::PackageWorker
lib::source::SourceWorker::getPackageWorker(std::string platform,
                                            std::string package) {
  if (lib::system::FileManager::existsFile(getPath()))
    throw std::exception();
  return lib::source::PlatformWorker(getPath() + "/" + platform)
                                  .getPackageWorker(package);
}

lib::source::VersionWorker
lib::source::SourceWorker::getVersionWorker(std::string platform,
                                            std::string package,
                                            std::string version) {
  if (lib::system::FileManager::existsFile(getPath()))
    throw std::exception();
  return lib::source::PlatformWorker(getPath() + "/" + platform)
                        .getVersionWorker(package, version);
}
