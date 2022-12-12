#ifndef TOOL_LIB_TYPES_STRING_LIST
#define TOOL_LIB_TYPES_STRING_LIST

#include<vector>
#include<string>
#include<yaml-cpp/yaml.h>

namespace lib::types {
    class StringList {
        private:
            std::vector<std::string>* strings = NULL;
            std::vector<std::string>::iterator find(std::string string);
        public:
            StringList();
            ~StringList();

            long unsigned int size();
            std::string get(long unsigned int which);
            void set(std::string old_, std::string new_);
            void add(std::string string);
            void del(std::string string);
            bool contains(std::string string);

            YAML::Node dump();
            void load(YAML::Node node);
            
            std::string toString();
    };
}

#endif
