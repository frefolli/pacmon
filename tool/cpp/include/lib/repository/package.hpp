#ifndef TOOL_LIB_REPOSITORY_PACKAGE
#define TOOL_LIB_REPOSITORY_PACKAGE

#include<string>
#include<vector>
#include<lib/types/semver.hpp>
#include<lib/types/index_file.hpp>
#include<lib/types/string_list.hpp>
#include<lib/types/semver_list.hpp>

namespace lib::repository {
  class Package : public lib::types::IndexFile {
  private:
    lib::types::StringList* depends = NULL;
    lib::types::SemverList* versions = NULL;
    std::string license, url, description;

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
    void commit();
  };
}

#endif
