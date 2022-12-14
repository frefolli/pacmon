#include<lib/types/string_list.hpp>
#include<boost/algorithm/string/join.hpp>
#include<lib/exceptions/index_out_of_bound.hpp>
#include<lib/exceptions/item_not_found.hpp>
#include<lib/exceptions/item_already_there.hpp>

lib::types::StringList::StringList() {
  this->strings = new std::vector<std::string>();
}

lib::types::StringList::~StringList() {
  delete this->strings;
}

std::vector<std::string>::iterator
lib::types::StringList::find(std::string string) {
  return std::find(this->strings->begin(),
		   this->strings->end(), string);
}

long unsigned int
lib::types::StringList::size() {
  return this->strings->size();
}

std::string
lib::types::StringList::get(long unsigned int which) {
  if (which < this->size())
    return this->strings->at(which);
  else
    throw lib::exceptions::IndexOutOfBound("string list");
}

void lib::types::StringList::set(std::string old_, std::string new_) {
  if (this->contains(new_))
    throw lib::exceptions::ItemAlreadyThere("string list", "string");
  auto it = this->find(old_);
  if (it != this->strings->end())
    *it = new_;
  else
    throw lib::exceptions::ItemNotFound("string list", "string");
}

void lib::types::StringList::add(std::string string) {
  if (this->contains(string))
    throw lib::exceptions::ItemAlreadyThere("string list", "string");
  else
    this->strings->push_back(string);
}

void lib::types::StringList::del(std::string string) {
  auto it = this->find(string);
  if (it != this->strings->end())
    this->strings->erase(it);
  else
    throw lib::exceptions::ItemNotFound("string list", "string");
}

bool lib::types::StringList::contains(std::string string) {
  return this->strings->end() != this->find(string);
}

std::string lib::types::StringList::toString() {
  std::string rep = "(types:string-list";
  rep += " :strings '(" + boost::algorithm::join(*(this->strings), " ") + ")";
  return rep + ")";
}

YAML::Node lib::types::StringList::dump() {
  YAML::Node node;
  for (auto it = this->strings->begin(); it != this->strings->end(); ++it)
    node.push_back(*it);
  return node;
}

void lib::types::StringList::load(YAML::Node node) {
  this->strings->clear();
  for (YAML::const_iterator it = node.begin(); it != node.end(); ++it)
    this->strings->push_back(it->as<std::string>());
}
