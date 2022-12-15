#ifndef TOOL_LIB_REPOSITORY_REPOSITORY
#define TOOL_LIB_REPOSITORY_REPOSITORY

#include<string>
#include<vector>
#include<lib/types/index_file.hpp>
#include<lib/types/string_list.hpp>

namespace lib::repository {
  class Repository : public lib::types::IndexFile {
  private:
    lib::types::StringList* platforms = NULL;

    void load();
    void dump();
  public:
    Repository(std::string path);
    ~Repository();

    long unsigned int getNumberOfPlatforms();
    std::string getPlatform(long unsigned int which);

    void addPlatform(std::string platform);
    void deletePlatform(std::string platform);
    void renamePlatform(std::string platform, std::string newname);
    bool containsPlatform(std::string platform);

    std::string toString();
    void commit();
  };
}

#endif
