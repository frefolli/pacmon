#ifndef TOOL_LIB_REPOSITORY_PLATFORM
#define TOOL_LIB_REPOSITORY_PLATFORM

#include<string>
#include<vector>
#include<lib/types/index_file.hpp>
#include<lib/types/string_list.hpp>

namespace lib::repository {
  class Platform : public lib::types::IndexFile {
  private:
      lib::types::StringList* packages = NULL;

    void load();
    void dump();
  public:
    Platform(std::string path);
    ~Platform();

    long unsigned int getNumberOfPackages();
    std::string getPackage(long unsigned int which);

    void addPackage(std::string package);
    void deletePackage(std::string package);
    void renamePackage(std::string package, std::string newname);
    bool containsPackage(std::string package);

    std::string toString();
  };
}

#endif
