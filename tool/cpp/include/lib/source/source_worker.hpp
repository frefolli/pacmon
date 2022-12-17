#ifndef TOOL_LIB_SOURCE_SOURCE_WORKER
#define TOOL_LIB_SOURCE_SOURCE_WORKER 

#include<string>
#include<lib/source/platform_worker.hpp>
#include<lib/source/package_worker.hpp>
#include<lib/source/version_worker.hpp>

namespace lib::source {
  class SourceWorker {
  private:
    std::string path;
  public:
    SourceWorker(std::string path);
    SourceWorker();
    ~SourceWorker();

    // actions
    void doInit();
    void checkCoherence();
    void printAll();
            
    void listPlatforms(std::string platform);
            
    void addPlatform(std::string platform);
            
    void removePlatform(std::string platform);
            
    void renamePlatform(std::string platform, std::string newname);
            
    void forkPlatform(std::string platform, std::string clonename);

    // access
    PlatformWorker getPlatformWorker(std::string platform);
            
    PackageWorker getPackageWorker(std::string platform,
				    std::string package);

    VersionWorker getVersionWorker(std::string platform,
				    std::string package,
				    std::string version);
  };
}

#endif
