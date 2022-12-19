#include <lib/source/package_worker.hpp>
#include <lib/source/package.hpp>
#include <stdexcept>
#include <lib/system/file_manager.hpp>
#include <lib/exceptions/invalid_worker_path.hpp>
#include <lib/config/config.hpp>

lib::source::PackageWorker::PackageWorker(std::string path)
: lib::types::Worker(path) {
  doInit();
}

lib::source::PackageWorker::PackageWorker()
: lib::types::Worker() {
  doInit();
}

lib::source::PackageWorker::~PackageWorker() {}

void lib::source::PackageWorker::doInit() {
  try {
    if (! lib::system::FileManager::existsFile(getPath())) {
      if (lib::config::alwaysInit) {
        lib::system::FileManager::createFile(getIndexPath());
        lib::source::Package index (getPath()); index.commit();
      } else {
        throw lib::exceptions::InvalidWorkerPath(getPath());
      }
    }
  } catch(...) {
    throw lib::exceptions::InvalidWorkerPath(getPath());
  }
}

void lib::source::PackageWorker::checkCoherence() {
  lib::source::Package index (getPath());
  // TODO
}

void lib::source::PackageWorker::printAll(unsigned int indentLevel) {
  lib::source::Package index (getPath());
  std::string indentation (indentLevel, '\t');
  std::printf("%ssource :: package = {\n", indentation.c_str());
  listDependencies(indentLevel+1);
  printLicense(indentLevel+1);
  printDescription(indentLevel+1);
  printUrl(indentLevel+1);
  for (long unsigned int i = 0; i < index.getNumberOfVersions(); i++) {
    std::printf("%s\tversion: <%s>\n", indentation.c_str(), index.getVersion(i).toString().c_str());
    getVersionWorker(index.getVersion(i).toString()).printAll(indentLevel+1);
  }
  std::printf("%s}\n", indentation.c_str());
}

std::string lib::source::PackageWorker::getVersionPath(std::string version) {
  return getPath() + "/" + version;
}

void lib::source::PackageWorker::listVersions(unsigned int indentLevel) {
  lib::source::Package index (getPath());
  std::string indentation (indentLevel, '\t');
  std::printf("%ssource :: versions = {\n", indentation.c_str());
  for (long unsigned int i = 0; i < index.getNumberOfVersions(); i++) {
    std::printf("%s\t[%i] - %s\n", indentation.c_str(), i, index.getVersion(i).toString().c_str());
  }
  std::printf("%s}\n", indentation.c_str());
}

void lib::source::PackageWorker::listDependencies(unsigned int indentLevel) {
  lib::source::Package index (getPath());
  std::string indentation (indentLevel, '\t');
  std::printf("%ssource :: dependencies = {\n", indentation.c_str());
  for (long unsigned int i = 0; i < index.getNumberOfDependencies(); i++) {
    std::printf("%s\t[%i] - %s\n", indentation.c_str(), i, index.getDependency(i).c_str());
  }
  std::printf("%s}\n", indentation.c_str());
}

void lib::source::PackageWorker::printLicense(unsigned int indentLevel) {
  lib::source::Package index (getPath());
  std::string indentation (indentLevel, '\t');
  std::printf("%ssource :: license = %s\n", indentation.c_str(),
              index.getLicense().c_str());
}

void lib::source::PackageWorker::printUrl(unsigned int indentLevel) {
  lib::source::Package index (getPath());
  std::string indentation (indentLevel, '\t');
  std::printf("%ssource :: url = %s\n", indentation.c_str(),
              index.getUrl().c_str());
}

void lib::source::PackageWorker::printDescription(unsigned int indentLevel) {
  lib::source::Package index (getPath());
  std::string indentation (indentLevel, '\t');
  std::printf("%ssource :: description = %s\n", indentation.c_str(),
              index.getDescription().c_str());
}

void lib::source::PackageWorker::setLicense(std::string license) {
  lib::source::Package index (getPath());
  index.setLicense(license);
  index.commit();
}

void lib::source::PackageWorker::setUrl(std::string url) {
  lib::source::Package index (getPath());
  index.setUrl(url);
  index.commit();
}

void lib::source::PackageWorker::setDescription(std::string description) {
  lib::source::Package index (getPath());
  index.setDescription(description);
  index.commit();
}

void lib::source::PackageWorker::addVersion(std::string version) {
  lib::source::Package index (getPath());
  index.addVersion(version);
  lib::system::FileManager::createDirectory(getVersionPath(version));
  getVersionWorker(version).doInit();
  index.commit();
}

void lib::source::PackageWorker::addDependency(std::string dependency) {
  lib::source::Package index (getPath());
  index.addDependency(dependency);
  index.commit();
}

void lib::source::PackageWorker::removeVersion(std::string version) {
  lib::source::Package index (getPath());
  index.deleteVersion(version);
  lib::system::FileManager::deleteDirectory(getVersionPath(version));
  index.commit();
}

void lib::source::PackageWorker::removeDependency(std::string dependency) {
  lib::source::Package index (getPath());
  index.deleteDependency(dependency);
  index.commit();
}

void lib::source::PackageWorker::renameVersion(std::string version,
                                                std::string newname) {
  lib::source::Package index (getPath());
  index.renameVersion(version, newname);
  lib::system::FileManager::moveDirectory(getVersionPath(version),
                                          getVersionPath(newname));
  index.commit();
}

void lib::source::PackageWorker::renameDependency(std::string dependency,
                                                  std::string newname) {
  lib::source::Package index (getPath());
  index.renameDependency(dependency, newname);
  index.commit();
}

void lib::source::PackageWorker::forkVersion(std::string version,
                                              std::string clonename) {
  lib::source::Package index (getPath());
  if (! index.containsVersion(version))
    throw std::exception();
  index.addVersion(clonename);
  lib::system::FileManager::copyDirectory(getVersionPath(version),
                                          getVersionPath(clonename));
  index.commit();
}

// access
lib::source::VersionWorker
lib::source::PackageWorker::getVersionWorker(std::string version) {
  return lib::source::VersionWorker(getVersionPath(version));
}
