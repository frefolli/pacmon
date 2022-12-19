#ifndef TOOL_LIB_CLI_CLI
#define TOOL_LIB_CLI_CLI

#include <string>
#include <vector>

namespace lib::cli {
  class CLI {
    std::string name, description,
                author, date, version;
    public:
      CLI();
      ~CLI();

      void setName(std::string name);
      void setDescription(std::string description);
      void setAuthor(std::string author);
      void setDate(std::string date);
      void setVersion(std::string version);

      void parseArgs(int argc, char** args);
      void parseArgs(std::vector<std::string>* args);
  };
}

#endif
