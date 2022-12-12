#ifndef TOOL_LIB_TYPES_SEMVER_LIST
#define TOOL_LIB_TYPES_SEMVER_LIST

#include<vector>
#include<string>
#include<yaml-cpp/yaml.h>

namespace lib::types {
    class StringList {
        private:
            std::vector<std::string>* strings = NULL;
            std::vector<std::string>::iterator findString(std::string string);
        public:
            StringList();
            ~StringList();

            long unsigned int size();
            std::string get(long unsigned int which);
            void set(std::string old_, std::string new_);
            void add(std::string string);
            void del(std::string string);
            bool contains(std::string string);

            std::string toString();
    };

    YAML::Node& operator>>(YAML::Node& node, StringList& stringList);
    YAML::Node& operator<<YAML::Node& node, StringList& stringList);
}

#endif
