#ifndef TOOL_LIB_TYPES_SEMVER
#define TOOL_LIB_TYPES_SEMVER

#include<string>

namespace lib::types {
    class Semver {
        private:
            long unsigned int major, minor, patch;

        public:
            Semver(long unsigned int major,
                   long unsigned int minor,
                   long unsigned int patch);
            Semver(std::string semver);

            long unsigned int getMajor();
            long unsigned int getMinor();
            long unsigned int getPatch();

            bool operator>(Semver other);
            bool operator<(Semver other);
            bool operator==(Semver other);
            bool operator>=(Semver other);
            bool operator<=(Semver other);

            std::string toString();
    };
}

#endif
