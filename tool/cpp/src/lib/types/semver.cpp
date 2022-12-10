#include<lib/types/semver.hpp>

lib::types::Semver::Semver(long unsigned int major,
                            long unsigned int minor,
                            long unsigned int patch) {
    this->major = major;
    this->minor = minor;
    this->patch = patch;
}

lib::types::Semver::Semver(std::string semver) {
    this->major = 1;
    this->minor = 0;
    this->patch = 0;
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
