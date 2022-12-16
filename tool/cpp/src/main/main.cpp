#include<lib/source.hpp>
#include<lib/repository.hpp>
#include<stdexcept>
#include<iostream>
#include<filesystem>

template<class T>
void println(T obj) {
  std::cout << obj << std::endl;
}

template<class Root, class Platform, class Package, class Version>
void someTree(std::string path) {
  Root* root = new Root(path);
  println(root->toString());
  for (int i = 0; i < root->getNumberOfPlatforms(); i++) {
    std::string platformName = root->getPlatform(i);
    Platform* platform = new Platform(path + "/" + platformName);
    println(platform->toString());
    for (int j = 0; j < platform->getNumberOfPackages(); j++) {
      std::string packageName = platform->getPackage(j);
      Package* package = new Package(path + "/" + platformName + "/" + packageName);
      println(package->toString());
      for (int k = 0; k < package->getNumberOfVersions(); k++) {
	lib::types::Semver semver = package->getVersion(k);
	Version* version = new Version(path + "/" + platformName + "/" + packageName + "/" + semver.toString());
	println(version->toString());
	delete version;
      }
      delete package;
    }
    delete platform;
  }
  delete root;
}

int main(int argc, char** args) {
  try {
    std::string path = std::filesystem::current_path().string();
    if (argc > 1) {
      path = std::filesystem::absolute(std::filesystem::path(std::string(args[1]))).string();
      if (! std::filesystem::exists(std::filesystem::path(path)))
	throw new std::runtime_error("folder <" + path + "> passed as argument doesn't exists");
    }

    someTree<lib::source::Source, lib::source::Platform,
	     lib::source::Package, lib::source::Version>
      (path + "/source");
    someTree<lib::repository::Repository, lib::repository::Platform,
	     lib::repository::Package, lib::repository::Version>
      (path + "/repository");
  
  } catch(std::runtime_error error) {
    println((&error)->what());
  }
}
