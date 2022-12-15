#ifndef TOOL_LIB_SOURCE_SOURCE
#define TOOL_LIB_SOURCE_SOURCE

#include<string>
#include<vector>
#include<lib/types/index_file.hpp>
#include<lib/types/string_list.hpp>

namespace lib::source {
  class Source : public lib::types::IndexFile {
  private:
    lib::types::StringList* platforms = NULL;

    void load();
    void dump();
  public:
    Source(std::string path);
    ~Source();

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
