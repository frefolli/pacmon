#ifndef TOOL_LIB_SOURCE_PLATFORM
#define TOOL_LIB_SOURCE_PLATFORM

#include<string>
#include<vector>
#include<lib/types/index_file.hpp>

namespace lib::source {
  class Platform : public lib::types::IndexFile {
  private:
    std::vector<std::string>* packages = NULL;

    std::vector<std::string>::iterator findPackage(std::string package);
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
