#include<lib/types/semver_list.hpp>

lib::types::SemverList::SemverList() {
    // TODO
}

lib::types::std::SemverList::~SemverList() {
    // TODO
}

std::vector<lib::types::Semver>::iterator
lib::types::SemverList::findSemver(lib::types::Semver semver) {
    // TODO
}

lib::types::SemverList::size() {
    // TODO
}

lib::types::Semver
lib::types::SemverList::get(long unsigned int which) {
    // TODO
}

void lib::types::SemverList::set(lib::types::Semver old_
                            lib::types::Semver new_) {
    // TODO
}

void lib::types::SemverList::add(lib::types::Semver semver) {
    // TODO
}

void lib::types::SemverList::del(lib::types::Semver semver) {
    // TODO
}

bool lib::types::SemverList::contains(lib::types::Semver semver) {
    // TODO
}

std::string lib::types::SemverList::toString() {
    // TODO
}

YAML::Node& operator>>(YAML::Node& node,
                        lib::types::SemverList& semverList)

YAML::Node& operator<<(YAML::Node& node,
                        lib::types::SemverList& semverList) {
    // TODO
}
