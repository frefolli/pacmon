#ifndef TOOL_LIB_SOURCE_PLATFORM_WORKER
#define TOOL_LIB_SOURCE_PLATFORM_WORKER 

#include<string>
#include<lib/source/package_worker.hpp>
#include<lib/source/version_worker.hpp>
#include<lib/types/worker.hpp>

namespace lib::source {
  class PlatformWorker : public lib::types::Worker {
  public:
    PlatformWorker(std::string path);
    PlatformWorker();
    ~PlatformWorker();

    // actions
    void doInit();
    void checkCoherence();
    void printAll();
            
    void listPackages(std::string package);
            
    void addPackage(std::string package);
            
    void removePackage(std::string package);
            
    void renamePackage(std::string package, std::string newname);

    void forkPackage(std::string package, std::string clonename);

    // access
    PackageWorker getPackageWorker(std::string package);

    VersionWorker getVersionWorker(std::string package,
				    std::string version);
  };
}

#endif
