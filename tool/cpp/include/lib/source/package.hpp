#ifndef TOOL_LIB_SOURCE_PACKAGE
#define TOOL_LIB_SOURCE_PACKAGE

#include<string>
#include<vector>
#include<lib/types/semver.hpp>

namespace lib::source {
  class Package {
  private:
    std::vector<std::string>* depends = NULL;
    std::vector<lib::types::Semver>* versions = NULL;
    std::string license, url, description, path;

    std::vector<lib::types::Semver>::iterator findVersion(lib::types::Semver version);
    void load();
    void dump();
  public:
    Package(std::string path);
    ~Package();

    long unsigned int getNumberOfVersions();
    lib::types::Semver getVersion(long unsigned int which);

    void addVersion(lib::types::Semver version);
    void deleteVersion(lib::types::Semver version);
    void renameVersion(lib::types::Semver version, lib::types::Semver newname);
    bool containsVersion(lib::types::Semver version);

    std::string toString();
  };
}

#endif
