#ifndef TOOL_LIB_CLI_OPTION
#define TOOL_LIB_CLI_OPTION

#include <string>
#include <vector>

namespace lib::cli {
  class Option {
    private:
      std::string description,
        longTrigger, shortTrigger;
    public:
      Option();
      ~Option();

      void help();
      std::string getDescription();
      std::string getLongTrigger();
      std::string getShortTrigger();
      
      void setDescription(std::string description);
      void setLongTrigger(std::string longTrigger);
      void setShortTrigger(std::string shortTrigger);

      unsigned int parseArgs(int argc, char** args);
      unsigned int parseArgs(std::vector<std::string>* args);
      unsigned int parseArgs(std::vector<std::string>::iterator begin,
                     std::vector<std::string>::iterator end);
  };
}

#endif
