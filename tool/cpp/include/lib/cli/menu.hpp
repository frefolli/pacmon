#ifndef TOOL_LIB_CLI_MENU
#define TOOL_LIB_CLI_MENU

#include <string>
#include <vector>
#include <map>

#include <lib/cli/option.hpp>

namespace lib::cli {
  class Menu {
    private:
      std::string name, description;
      std::map<std::string, lib::cli::Option*>* options = NULL;
      std::map<std::string, lib::cli::Menu*>* menus = NULL;

      std::map<std::string, lib::cli::Menu*>::iterator getMenu(std::string menu);
      std::map<std::string, lib::cli::Option*>::iterator getOption(std::string option);
    public:
      Menu();
      ~Menu();

      void help();
      void help(std::string something);

      void setName(std::string name);
      void setDescription(std::string description);

      std::string getName();
      std::string getDescription();

      void addMenu(Menu* menu);
      void addOption(Option* option);

      unsigned int parseArgs(int argc, char** args);
      unsigned int parseArgs(std::vector<std::string>* args);
      unsigned int parseArgs(std::vector<std::string>::iterator begin,
                     std::vector<std::string>::iterator end);
  };
}

#endif
