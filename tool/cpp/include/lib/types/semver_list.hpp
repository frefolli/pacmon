#ifndef TOOL_LIB_TYPES_SEMVER_LIST
#define TOOL_LIB_TYPES_SEMVER_LIST

#include<vector>
#include<string>
#include<lib/types/semver.hpp>
#include<yaml-cpp/yaml.h>

namespace lib::types {
    class SemverList {
        private:
            std::vector<Semver>* semvers = NULL;
            std::vector<Semver>::iterator find(Semver semver);
        public:
            SemverList();
            ~SemverList();

            long unsigned int size();
            Semver get(long unsigned int which);
            void set(Semver old_, Semver new_);
            void add(Semver semver);
            void del(Semver semver);
            bool contains(Semver semver);
            
            YAML::Node dump();
            void load(YAML::Node node);

            std::string toString();
    };

}

#endif
