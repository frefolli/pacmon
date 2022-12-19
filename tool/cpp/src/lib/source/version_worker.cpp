#include <lib/source/version_worker.hpp>
#include <lib/source/version.hpp>
#include <lib/system/file_manager.hpp>
#include <stdexcept>
#include <lib/exceptions/invalid_worker_path.hpp>
#include <lib/config/config.hpp>

lib::source::VersionWorker::VersionWorker(std::string path)
: lib::types::Worker(path) {
  doInit();
}

lib::source::VersionWorker::VersionWorker()
: lib::types::Worker() {
  doInit();
}

lib::source::VersionWorker::~VersionWorker() {}

void lib::source::VersionWorker::doInit() {
  try {
    if (! lib::system::FileManager::existsFile(getPath())) {
      if (lib::config::alwaysInit) {
        lib::system::FileManager::createFile(getIndexPath());
        lib::source::Version index (getPath()); index.commit();
      } else {
        throw lib::exceptions::InvalidWorkerPath(getPath());
      }
    }
  } catch(...) {
    throw lib::exceptions::InvalidWorkerPath(getPath());
  }
}

void lib::source::VersionWorker::checkCoherence() {
  lib::source::Version index (getPath());
  // TODO
}

void lib::source::VersionWorker::printAll(unsigned int indentLevel) {
  std::string indentation (indentLevel, '\t');
  std::printf("%ssource :: version = {\n", indentation.c_str());
  listAllFiles(indentLevel+1);
  listSoftwares(indentLevel+1);
  listInstallCommands(indentLevel+1);
  listUninstallCommands(indentLevel+1);
  std::printf("%s}\n", indentation.c_str());
}

void lib::source::VersionWorker::listFilesAsSupport(unsigned int indentLevel) {
  lib::source::Version index (getPath());
  std::string indentation (indentLevel, '\t');
  std::printf("%ssource :: files-as-support = {\n", indentation.c_str());
  for (long unsigned int i = 0; i < index.getNumberOfFilesAsSupport(); i++) {
    std::printf("%s\t[%i] - %s\n", indentation.c_str(), i, index.getFileAsSupport(i).c_str());
  }
  std::printf("%s}\n", indentation.c_str());
}

void lib::source::VersionWorker::listFilesToInstall(unsigned int indentLevel) {
  lib::source::Version index (getPath());
  std::string indentation (indentLevel, '\t');
  std::printf("%ssource :: files-to-install = {\n", indentation.c_str());
  for (long unsigned int i = 0; i < index.getNumberOfFilesToInstall(); i++) {
    std::printf("%s\t[%i] - %s\n", indentation.c_str(), i, index.getFileToInstall(i).c_str());
  }
  std::printf("%s}\n", indentation.c_str());
}

void lib::source::VersionWorker::listAllFiles(unsigned int indentLevel) {
  listFilesAsSupport(indentLevel);
  listFilesToInstall(indentLevel);
}

void lib::source::VersionWorker::listSoftwares(unsigned int indentLevel) {
  lib::source::Version index (getPath());
  std::string indentation (indentLevel, '\t');
  std::printf("%ssource :: softwares = {\n", indentation.c_str());
  for (long unsigned int i = 0; i < index.getNumberOfSoftwares(); i++) {
    std::printf("%s\t[%i] - %s\n", indentation.c_str(), i, index.getSoftware(i).c_str());
  }
  std::printf("%s}\n", indentation.c_str());
}

void lib::source::VersionWorker::listInstallCommands(unsigned int indentLevel) {
  lib::source::Version index (getPath());
  std::string indentation (indentLevel, '\t');
  std::printf("%ssource :: install-commands = {\n", indentation.c_str());
  for (long unsigned int i = 0; i < index.getNumberOfInstallCommands(); i++) {
    std::printf("%s\t[%i] - %s\n", indentation.c_str(), i, index.getInstallCommand(i).c_str());
  }
  std::printf("%s}\n", indentation.c_str());
}

void lib::source::VersionWorker::listUninstallCommands(unsigned int indentLevel) {
  lib::source::Version index (getPath());
  std::string indentation (indentLevel, '\t');
  std::printf("%ssource :: uninstall-commands = {\n", indentation.c_str());
  for (long unsigned int i = 0; i < index.getNumberOfUninstallCommands(); i++) {
    std::printf("%s\t[%i] - %s\n", indentation.c_str(), i, index.getUninstallCommand(i).c_str());
  }
  std::printf("%s}\n", indentation.c_str());
}

void lib::source::VersionWorker::addFileAsSupport(std::string file) {
  lib::source::Version index (getPath());
  index.addFileAsSupport(file);
  index.commit();
}

void lib::source::VersionWorker::addFileToInstall(std::string file) {
  lib::source::Version index (getPath());
  index.addFileToInstall(file);
  index.commit();
}

void lib::source::VersionWorker::addSoftware(std::string software) {
  lib::source::Version index (getPath());
  index.addSoftware(software);
  index.commit();
}

void lib::source::VersionWorker::addInstallCommand(std::string command) {
  lib::source::Version index (getPath());
  index.addInstallCommand(command);
  index.commit();
}

void lib::source::VersionWorker::addUninstallCommand(std::string command) {
  lib::source::Version index (getPath());
  index.addUninstallCommand(command);
  index.commit();
}

void lib::source::VersionWorker::removeFileAsSupport(std::string file) {
  lib::source::Version index (getPath());
  index.deleteFileAsSupport(file);
  index.commit();
}

void lib::source::VersionWorker::removeFileToInstall(std::string file) {
  lib::source::Version index (getPath());
  index.deleteFileToInstall(file);
  index.commit();
}

void lib::source::VersionWorker::removeSoftware(std::string software) {
  lib::source::Version index (getPath());
  index.deleteSoftware(software);
  index.commit();
}

void lib::source::VersionWorker::removeInstallCommand(std::string command) {
  lib::source::Version index (getPath());
  index.deleteInstallCommand(command);
  index.commit();
}

void lib::source::VersionWorker::removeUninstallCommand(std::string command) {
  lib::source::Version index (getPath());
  index.deleteUninstallCommand(command);
  index.commit();
}

void lib::source::VersionWorker::renameFileAsSupport(std::string file,
                                                      std::string newname) {
  lib::source::Version index (getPath());
  index.renameFileAsSupport(file, newname);
  index.commit();
}

void lib::source::VersionWorker::renameFileToInstall(std::string file,
                                                      std::string newname) {
  lib::source::Version index (getPath());
  index.renameFileToInstall(file, newname);
  index.commit();
}

void lib::source::VersionWorker::renameSoftware(std::string software,
                                                std::string newname) {
  lib::source::Version index (getPath());
  index.renameSoftware(software, newname);
  index.commit();
}

void lib::source::VersionWorker::renameInstallCommand(std::string command,
                                                      std::string newname) {
  lib::source::Version index (getPath());
  index.renameInstallCommand(command, newname);
  index.commit();
}

void lib::source::VersionWorker::renameUninstallCommand(std::string command,
                                                        std::string newname) {
  lib::source::Version index (getPath());
  index.renameUninstallCommand(command, newname);
  index.commit();
}
