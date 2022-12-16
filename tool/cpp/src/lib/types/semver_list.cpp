#include<lib/types/semver_list.hpp>
#include<boost/algorithm/string/join.hpp>
#include<lib/exceptions/index_out_of_bound.hpp>
#include<lib/exceptions/item_not_found.hpp>
#include<lib/exceptions/item_already_there.hpp>

lib::types::SemverList::SemverList() {
  this->semvers = new std::vector<lib::types::Semver>();
}

lib::types::SemverList::~SemverList() {
  delete this->semvers;
}

std::vector<lib::types::Semver>::iterator
lib::types::SemverList::find(lib::types::Semver semver) {
  return std::find(this->semvers->begin(),
		   this->semvers->end(), semver);
}

long unsigned int lib::types::SemverList::size() {
  return this->semvers->size();
}

lib::types::Semver
lib::types::SemverList::get(long unsigned int which) {
  if (which < this->size())
    return this->semvers->at(which);
  else
    throw lib::exceptions::IndexOutOfBound("semver list");
}

void lib::types::SemverList::set(lib::types::Semver old_, lib::types::Semver new_) {
  if (this->contains(new_))
    throw lib::exceptions::ItemAlreadyThere("semver list", "semver");
  auto it = this->find(old_);
  if (it != this->semvers->end())
    *it = new_;
  else
    throw lib::exceptions::ItemNotFound("semver list", "semver");
}

void lib::types::SemverList::add(lib::types::Semver semver) {
  if (this->contains(semver))
    throw lib::exceptions::ItemAlreadyThere("semver list", "semver");
  else
    this->semvers->push_back(semver);
}

void lib::types::SemverList::del(lib::types::Semver semver) {
  auto it = this->find(semver);
  if (it != this->semvers->end())
    this->semvers->erase(it);
  else
    throw lib::exceptions::ItemNotFound("semver list", "semver");
}

bool lib::types::SemverList::contains(lib::types::Semver semver) {
  return this->semvers->end() != this->find(semver);
}

std::string lib::types::SemverList::toString() {
  std::string rep = "(types:semver-list";
  std::vector<std::string> semverStrings;
  for (auto it = this->semvers->begin(); it != this->semvers->end(); ++it)
    semverStrings.push_back(it->toString());
  rep += " :semvers '(" + boost::algorithm::join(semverStrings, " ") + ")";
  return rep + ")";
}

YAML::Node lib::types::SemverList::dump() {
  YAML::Node node;
  for (auto it = this->semvers->begin(); it != this->semvers->end(); it++)
    node.push_back(it->toString());
  return node;
}

void lib::types::SemverList::load(YAML::Node node) {
  this->semvers->clear();
  for (YAML::const_iterator it = node.begin(); it != node.end(); ++it)
    this->semvers->push_back(lib::types::Semver(it->as<std::string>()));
}
