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

    void setMajor(long unsigned int major);
    void setMinor(long unsigned int minor);
    void setPatch(long unsigned int patch);

    void setAll(long unsigned int major,
		long unsigned int minor,
		long unsigned int patch);
    void setAll(std::string semver);

    bool operator>(Semver other);
    bool operator<(Semver other);
    bool operator==(Semver other);
    bool operator>=(Semver other);
    bool operator<=(Semver other);

    std::string toString();
  };
}

#endif
