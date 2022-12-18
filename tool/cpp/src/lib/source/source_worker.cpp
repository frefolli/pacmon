#include <lib/source/source_worker.hpp>
#include <lib/source/source.hpp>
#include <stdexcept>
#include <lib/system/file_manager.hpp>
#include <lib/exceptions/invalid_source_index_file_path.hpp>

lib::source::SourceWorker::SourceWorker(std::string path)
: lib::types::Worker(path) {}

lib::source::SourceWorker::SourceWorker()
: lib::types::Worker() {}

lib::source::SourceWorker::~SourceWorker() {}

void lib::source::SourceWorker::doInit() {
  if (lib::system::FileManager::existsFile(getPath()))
    throw lib::exceptions::InvalidSourceIndexFilePath(getPath());
  lib::system::FileManager::createFile(getIndexPath());
  lib::source::Source index (getPath()); index.commit();
}

void lib::source::SourceWorker::checkCoherence() {
  if (! lib::system::FileManager::existsFile(getPath()))
    throw lib::exceptions::InvalidSourceIndexFilePath(getPath());
  lib::source::Source index (getPath());
  // TODO
}

void lib::source::SourceWorker::printAll(unsigned int indentLevel) {
  if (! lib::system::FileManager::existsFile(getPath()))
    throw lib::exceptions::InvalidSourceIndexFilePath(getPath());
  lib::source::Source index (getPath());
  std::string indentation (indentLevel, '\t');
  std::printf("%ssource = {\n", indentation.c_str());
  for (long unsigned int i = 0; i < index.getNumberOfPlatforms(); i++) {
    std::printf("%s\tplatform: <%s>\n", indentation.c_str(), index.getPlatform(i).c_str());
    getPlatformWorker(index.getPlatform(i)).printAll(indentLevel+1);
  }
  std::printf("%s}\n", indentation.c_str());
}

std::string lib::source::SourceWorker::getPlatformPath(std::string platform) {
  return getPath() + "/" + platform;
}

void lib::source::SourceWorker::listPlatforms(unsigned int indentLevel) {
  if (! lib::system::FileManager::existsFile(getPath()))
    throw lib::exceptions::InvalidSourceIndexFilePath(getPath());
  lib::source::Source index (getPath());
  std::string indentation (indentLevel, '\t');
  std::printf("%ssource :: platforms = {\n", indentation.c_str());
  for (long unsigned int i = 0; i < index.getNumberOfPlatforms(); i++) {
    std::printf("%s\t[%i] - %s\n", indentation.c_str(), i, index.getPlatform(i).c_str());
  }
  std::printf("%s}\n", indentation.c_str());
}

void lib::source::SourceWorker::addPlatform(std::string platform) {
  if (! lib::system::FileManager::existsFile(getPath()))
    throw lib::exceptions::InvalidSourceIndexFilePath(getPath());
  lib::source::Source index (getPath());
  index.addPlatform(platform);
  lib::system::FileManager::createDirectory(getPlatformPath(platform));
  getPlatformWorker(platform).doInit();
  index.commit();
}

void lib::source::SourceWorker::removePlatform(std::string platform) {
  if (! lib::system::FileManager::existsFile(getPath()))
    throw lib::exceptions::InvalidSourceIndexFilePath(getPath());
  lib::source::Source index (getPath());
  index.deletePlatform(platform);
  lib::system::FileManager::deleteDirectory(getPlatformPath(platform));
  index.commit();
}

void lib::source::SourceWorker::renamePlatform(std::string platform,
                                                std::string newname) {
  if (! lib::system::FileManager::existsFile(getPath()))
    throw lib::exceptions::InvalidSourceIndexFilePath(getPath());
  lib::source::Source index (getPath());
  index.renamePlatform(platform, newname);
  lib::system::FileManager::moveDirectory(getPlatformPath(platform),
                                          getPlatformPath(newname));
  index.commit();
}

void lib::source::SourceWorker::forkPlatform(std::string platform,
                                            std::string clonename) {
  if (! lib::system::FileManager::existsFile(getPath()))
    throw lib::exceptions::InvalidSourceIndexFilePath(getPath());
  lib::source::Source index (getPath());
  if (! index.containsPlatform(platform))
    throw std::exception();
  index.addPlatform(clonename);
  lib::system::FileManager::copyDirectory(getPlatformPath(platform),
                                          getPlatformPath(clonename));
  index.commit();
}

lib::source::PlatformWorker
lib::source::SourceWorker::getPlatformWorker(std::string platform) {
  if (! lib::system::FileManager::existsFile(getPath()))
    throw lib::exceptions::InvalidSourceIndexFilePath(getPath());
  return lib::source::PlatformWorker(getPlatformPath(platform));
}

lib::source::PackageWorker
lib::source::SourceWorker::getPackageWorker(std::string platform,
                                            std::string package) {
  if (! lib::system::FileManager::existsFile(getPath()))
    throw lib::exceptions::InvalidSourceIndexFilePath(getPath());
  return getPlatformWorker(platform)
          .getPackageWorker(package);
}

lib::source::VersionWorker
lib::source::SourceWorker::getVersionWorker(std::string platform,
                                            std::string package,
                                            std::string version) {
  if (! lib::system::FileManager::existsFile(getPath()))
    throw lib::exceptions::InvalidSourceIndexFilePath(getPath());
  return getPlatformWorker(platform)
          .getVersionWorker(package, version);
}
