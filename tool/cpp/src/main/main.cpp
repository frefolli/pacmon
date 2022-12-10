#include<lib/source/source.hpp>
#include<lib/source/platform.hpp>
#include<lib/source/package.hpp>
#include<stdexcept>
#include<iostream>

template<class T>
void println(T obj) {
  std::cout << obj << std::endl;
}

int main() {
  try {
    std::string path = "/home/refo/Documents/testing/source";
    lib::source::Source* source = new lib::source::Source(path);
    println(source->toString());
    for (int i = 0; i < source->getNumberOfPlatforms(); i++) {
      std::string platformName = source->getPlatform(i);
      lib::source::Platform* platform = new lib::source::Platform(path + "/" + platformName);
      println(platform->toString());
      for (int j = 0; j < platform->getNumberOfPackages(); j++) {
        std::string packageName = platform->getPackage(j);
        lib::source::Package* package = new lib::source::Package(path + "/" + platformName + "/" + packageName);
        println(package->toString());
        delete package;
      }
      delete platform;
    }
    delete source;
  } catch(std::runtime_error* error) {
    println(error->what());
  }
}
