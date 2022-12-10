#ifndef TOOL_LIB_SOURCE_SOURCE
#define TOOL_LIB_SOURCE_SOURCE

#include<string>
#include<vector>

namespace lib::source {
  class Source {
  private:
    std::vector<std::string>* platforms = NULL;
    std::string path;

    std::vector<std::string>::iterator findPlatform(std::string platform);
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
  };
}

#endif
