#include<lib/source/source.hpp>
#include<stdexcept>
#include<iostream>

int main() {
  try {
    lib::source::Source* source = new lib::source::Source("/home/refo/Documents/testing/source");
    source->addPlatform("fedora");
    delete source;
  } catch(std::runtime_error* error) {
    std::cout << error->what() << std::endl;
  }
}
