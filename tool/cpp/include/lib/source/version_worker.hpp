#ifndef TOOL_LIB_SOURCE_VERSION_WORKER
#define TOOL_LIB_SOURCE_VERSION_WORKER 

#include<string>
#include<lib/types/worker.hpp>

namespace lib::source {
  class VersionWorker : public lib::types::Worker {
  public:
    VersionWorker(std::string path);
    VersionWorker();
    ~VersionWorker();

    // init
    void doInit();
    void checkCoherence();
    void printAll();

    void listFilesAsSupport();
    void listFilesToInstall();
    void listAllFiles();
    void listSoftwares();
    void listInstallCommands();
    void listUninstallCommands();
            
    void addFileAsSupport(std::string file);
    void addFileToInstall(std::string file);
    void addSoftware(std::string software);
    void addInstallCommand(std::string command);
    void addUninstallCommand(std::string command);
            
    void removeFileAsSupport(std::string file);
    void removeFileToInstall(std::string file);
    void removeSoftware(std::string software);
    void removeInstallCommand(std::string command);
    void removeUninstallCommand(std::string command);
            
    void renameFileAsSupport(std::string file, std::string newname);
    void renameFileToInstall(std::string file, std::string newname);
    void renameSoftware(std::string software, std::string newname);
    void renameInstallCommand(std::string command, std::string newname);
    void renameUninstallCommand(std::string command, std::string newname);
  };
}

#endif
