#ifndef TOOL_LIB_SOURCE_PACKAGE
#define TOOL_LIB_SOURCE_PACKAGE

#include<string>
#include<vector>
#include<lib/types/semver.hpp>
#include<lib/types/index_file.hpp>

namespace lib::source {
  class Package : public lib::types::IndexFile {
  private:
    std::vector<std::string>* depends = NULL;
    std::vector<lib::types::Semver>* versions = NULL;
    std::string license, url, description;

    std::vector<lib::types::Semver>::iterator findVersion(lib::types::Semver version);
    std::vector<std::string>::iterator findDependency(std::string dependency);
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

    long unsigned int getNumberOfDependencies();
    std::string getDependency(long unsigned int which);

    void addDependency(std::string dependency);
    void deleteDependency(std::string dependency);
    void renameDependency(std::string dependency, std::string newname);
    bool containsDependency(std::string dependency);

    void setUrl(std::string url);
    void setDescription(std::string description);
    void setLicense(std::string license);

    std::string getUrl();
    std::string getDescription();
    std::string getLicense();

    std::string toString();
  };
}

#endif
