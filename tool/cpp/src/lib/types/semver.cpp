#include <lib/types/semver.hpp>
#include <regex>
#include <stdexcept>
#define SEMVER_REGEX "^([0-9]+)\\.([0-9]+)\\.([0-9]+)$"

lib::types::Semver::Semver(long unsigned int major,
			   long unsigned int minor,
			   long unsigned int patch) {
  this->setAll(major, minor, patch);
}

lib::types::Semver::Semver(std::string semver) {
  this->setAll(semver);
}

long unsigned int lib::types::Semver::getMajor() {
  return this->major;
}

long unsigned int lib::types::Semver::getMinor() {
  return this->minor;
}

long unsigned int lib::types::Semver::getPatch() {
  return this->patch;
}

void lib::types::Semver::setMajor(long unsigned int major) {
  this->major = major;
}

void lib::types::Semver::setMinor(long unsigned int minor) {
  this->minor = minor;
}

void lib::types::Semver::setPatch(long unsigned int patch) {
  this->patch = patch;
}

void lib::types::Semver::setAll(long unsigned int major,
                                long unsigned int minor,
                                long unsigned int patch) {
  this->setMajor(major);
  this->setMinor(minor);
  this->setPatch(patch);
}

void lib::types::Semver::setAll(std::string semverString) {
  std::regex regexObject (SEMVER_REGEX); std::smatch matchObject;
  std::regex_search(semverString, matchObject, regexObject);
  if (matchObject.size() == 0)
    throw std::exception();
  this->setAll(std::stoi(matchObject[1]),
                std::stoi(matchObject[2]),
                std::stoi(matchObject[3]));
}

bool lib::types::Semver::operator>(Semver other) {
  if (this->major > other.major) {
    return true;
  } else if (this->major == other.major) {
    if (this->minor > other.minor) {
      return true;
    } else if (this->minor == other.minor) {
      if (this->patch > other.patch) {
	return true;
      }
    }
  }
  return false;
}

bool lib::types::Semver::operator<(Semver other) {
  if (this->major < other.major) {
    return true;
  } else if (this->major == other.major) {
    if (this->minor < other.minor) {
      return true;
    } else if (this->minor == other.minor) {
      if (this->patch < other.patch) {
	return true;
      }
    }
  }
  return false;
}

bool lib::types::Semver::operator==(Semver other) {
  return ((this->major == other.major) &&
	  (this->minor == other.minor) &&
	  (this->patch == other.patch));
}

bool lib::types::Semver::operator>=(Semver other) {
  return this->operator>(other) || this->operator==(other);
}

bool lib::types::Semver::operator<=(Semver other) {
  return this->operator<(other) || this->operator==(other);
}

std::string lib::types::Semver::toString() {
  return std::to_string(this->major) + "." +
    std::to_string(this->minor) + "." +
    std::to_string(this->patch);
}
