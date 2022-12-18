#include <lib/source/platform_worker.hpp>
#include <lib/source/platform.hpp>
#include <stdexcept>
#include <lib/system/file_manager.hpp>
#include <lib/exceptions/invalid_source_platform_index_file_path.hpp>

lib::source::PlatformWorker::PlatformWorker(std::string path)
: lib::types::Worker(path) {}

lib::source::PlatformWorker::PlatformWorker()
: lib::types::Worker() {}

lib::source::PlatformWorker::~PlatformWorker() {}

void lib::source::PlatformWorker::doInit() {
  if (lib::system::FileManager::existsFile(getPath()))
    throw lib::exceptions::InvalidSourcePlatformIndexFilePath(getPath());
  lib::system::FileManager::createFile(getIndexPath());
  lib::source::Platform index (getPath()); index.commit();
}

void lib::source::PlatformWorker::checkCoherence() {
  if (! lib::system::FileManager::existsFile(getPath()))
    throw lib::exceptions::InvalidSourcePlatformIndexFilePath(getPath());
  lib::source::Platform index (getPath());
  // TODO
}

void lib::source::PlatformWorker::printAll(unsigned int indentLevel) {
  if (! lib::system::FileManager::existsFile(getPath()))
    throw lib::exceptions::InvalidSourcePlatformIndexFilePath(getPath());
  lib::source::Platform index (getPath());
  std::string indentation (indentLevel, '\t');
  std::printf("%ssource :: platform = {\n", indentation.c_str());
  for (long unsigned int i = 0; i < index.getNumberOfPackages(); i++) {
    std::printf("%s\tpackage: <%s>\n", indentation.c_str(), index.getPackage(i).c_str());
    getPackageWorker(index.getPackage(i)).printAll(indentLevel+1);
  }
  std::printf("%s}\n", indentation.c_str());
}

std::string lib::source::PlatformWorker::getPackagePath(std::string package) {
  return getPath() + "/" + package;
}

void lib::source::PlatformWorker::listPackages(unsigned int indentLevel) {
  if (! lib::system::FileManager::existsFile(getPath()))
    throw lib::exceptions::InvalidSourcePlatformIndexFilePath(getPath());
  lib::source::Platform index (getPath());
  std::string indentation (indentLevel, '\t');
  std::printf("%ssource :: packages = {\n", indentation.c_str());
  for (long unsigned int i = 0; i < index.getNumberOfPackages(); i++) {
    std::printf("%s\t[%i] - %s\n", indentation.c_str(), i, index.getPackage(i).c_str());
  }
  std::printf("%s}\n", indentation.c_str());
}

void lib::source::PlatformWorker::addPackage(std::string package) {
  if (! lib::system::FileManager::existsFile(getPath()))
    throw lib::exceptions::InvalidSourcePlatformIndexFilePath(getPath());
  lib::source::Platform index (getPath());
  index.addPackage(package);
  lib::system::FileManager::createDirectory(getPackagePath(package));
  getPackageWorker(package).doInit();
  index.commit();
}

void lib::source::PlatformWorker::removePackage(std::string package) {
  if (! lib::system::FileManager::existsFile(getPath()))
    throw lib::exceptions::InvalidSourcePlatformIndexFilePath(getPath());
  lib::source::Platform index (getPath());
  index.deletePackage(package);
  lib::system::FileManager::deleteDirectory(getPackagePath(package));
  index.commit();
}

void lib::source::PlatformWorker::renamePackage(std::string package,
                                                std::string newname) {
  if (! lib::system::FileManager::existsFile(getPath()))
    throw lib::exceptions::InvalidSourcePlatformIndexFilePath(getPath());
  lib::source::Platform index (getPath());
  index.renamePackage(package, newname);
  lib::system::FileManager::moveDirectory(getPackagePath(package),
                                          getPackagePath(newname));
  index.commit();
}

void lib::source::PlatformWorker::forkPackage(std::string package,
                                              std::string clonename) {
  if (! lib::system::FileManager::existsFile(getPath()))
    throw lib::exceptions::InvalidSourcePlatformIndexFilePath(getPath());
  lib::source::Platform index (getPath());
  if (! index.containsPackage(package))
    throw lib::exceptions::InvalidSourcePlatformIndexFilePath(getPath());
  index.addPackage(clonename);
  lib::system::FileManager::copyDirectory(getPackagePath(package),
                                          getPackagePath(clonename));
  index.commit();
}

lib::source::PackageWorker
lib::source::PlatformWorker::getPackageWorker(std::string package) {
  return lib::source::PackageWorker(getPackagePath(package));
}

lib::source::VersionWorker
lib::source::PlatformWorker::getVersionWorker(std::string package,
                                              std::string version) {
  return getPackageWorker(package)
          .getVersionWorker(version);
}
