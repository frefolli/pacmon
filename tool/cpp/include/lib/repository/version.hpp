#ifndef TOOL_LIB_REPOSITORY_VERSION
#define TOOL_LIB_REPOSITORY_VERSION

#include<string>
#include<vector>
#include<lib/types/index_file.hpp>
#include<lib/types/string_list.hpp>
#include<lib/types/semver.hpp>

namespace lib::repository {
  class Version : public lib::types::IndexFile {
  private:
    lib::types::StringList* filesToInstall = NULL;
    lib::types::StringList* filesAsSupport = NULL;
    lib::types::StringList* fileHashes = NULL;
    lib::types::StringList* softwares = NULL;
    lib::types::StringList* installCommands = NULL;
    lib::types::StringList* uninstallCommands = NULL;
    lib::types::StringList* depends = NULL;
    std::string platform, package, license, description, url;
    lib::types::Semver* version;

    void load();
    void dump();

  public:
    Version(std::string path);
    ~Version();

    std::string getPlatform();
    std::string getPackage();
    std::string getLicense();
    std::string getDescription();
    std::string getUrl();
    lib::types::Semver getVersion();

    void setPlatform(std::string platform);
    void setPackage(std::string package);
    void setLicense(std::string license);
    void setUrl(std::string url);
    void setDescription(std::string description);
    void setVersion(lib::types::Semver semver);

    long unsigned int getNumberOfFilesToInstall();
    long unsigned int getNumberOfFilesAsSupport();
    long unsigned int getNumberOfSoftwares();
    long unsigned int getNumberOfInstallCommands();
    long unsigned int getNumberOfUninstallCommands();
    long unsigned int getNumberOfDependencies();

    std::string getFileToInstall(long unsigned int which);
    std::string getFileAsSupport(long unsigned int which);
    std::string getSoftware(long unsigned int which);
    std::string getInstallCommand(long unsigned int which);
    std::string getUninstallCommand(long unsigned int which);
    std::string getDependency(long unsigned int which);
    std::string getFileHash(long unsigned int which);

    void addFileToInstall(std::string file);
    void addFileAsSupport(std::string file);
    void addSoftware(std::string software);
    void addInstallCommand(std::string command);
    void addUninstallCommand(std::string command);
    void addDependency(std::string dependency);

    void renameFileToInstall(std::string file,
                             std::string newname);
    void renameFileAsSupport(std::string file,
                             std::string newname);
    void renameSoftware(std::string software,
                        std::string newname);
    void renameInstallCommand(std::string command,
                              std::string newname);
    void renameUninstallCommand(std::string command,
                                std::string newname);
    void renameDependency(std::string dependency,
			  std::string newname);

    void deleteFileToInstall(std::string file);
    void deleteFileAsSupport(std::string file);
    void deleteSoftware(std::string software);
    void deleteInstallCommand(std::string command);
    void deleteUninstallCommand(std::string command);
    void deleteDependency(std::string dependency);

    std::string toString();
  };
}

#endif
