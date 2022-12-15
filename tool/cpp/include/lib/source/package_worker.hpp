#ifndef TOOL_LIB_SOURCE_PACKAGE_WORKER
#define TOOL_LIB_SOURCE_PACKAGE_WORKER 

#include<string>
#include<lib/source/version_worker.hpp>

namespace lib::source {
  class PackageWorker {
  private:
    std::string path;
  public:
    PackageWorker(std::string path);
    PackageWorker();
    ~PackageWorker();

    // actions
    void doInit();
    void checkCoherence();
    void printAll();

    void listVersions(std::string version);
    void listDependencies(std::string dependency);

    void printLicense();
    void printUrl();
    void printDescription();

    void setLicense(std::string license);
    void setUrl(std::string url);
    void setDescription(std::string description);
            
    void addVersion(std::string version);
    void addDependency(std::string dependency);
            
    void removeVersion(std::string version);
    void removeDependency(std::string dependency);
            
    void renameVersion(std::string version, std::string newname);
    void renameDependency(std::string dependency, std::string newname);

    void forkVersion(std::string version, std::string clonename);

    // access
    VersionWorker* getVersionWorker(std::string version);
  };
}

#endif
