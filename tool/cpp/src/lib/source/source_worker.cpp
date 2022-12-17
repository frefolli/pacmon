#include <lib/source/source_worker.hpp>
#include <stdexcept>
#include <fstream>

lib::source::SourceWorker::SourceWorker(std::string path) {
  this->path = path;
}

lib::source::SourceWorker::SourceWorker() {
  this->std::filesystem::current_path().string();
}

lib::source::SourceWorker::~SourceWorker() {
  // TODO
}

// actions
void lib::source::SourceWorker::doInit() {
  if (std::filesystem::exists(std::filesystem::path(this->path)))
    throw std::exception();
  std::ofstream ofs(this->path + "/index.yml"); ofs.close();
  lib::source::Source index (this->path); index.dump();
}

void lib::source::SourceWorker::checkCoherence() {
  if (std::filesystem::exists(std::filesystem::path(this->path)))
    throw std::exception();
  lib::source::Source index (this->path);
  // TODO
}

void lib::source::SourceWorker::printAll() {
  if (std::filesystem::exists(std::filesystem::path(this->path)))
    throw std::exception();
  lib::source::Source index (this->path);
  // TODO
}

void lib::source::SourceWorker::listPlatforms(std::string platform) {
  if (std::filesystem::exists(std::filesystem::path(this->path)))
    throw std::exception();
  lib::source::Source index (this->path);
  std::printf("source :: platforms {");
  for (long unsigned int i = 0; i < index.getNumberOfPlatforms(); i++) {
    std::printf("\t[%i] - %s\n", i, index.getPlatform(i).c_str());
  }
  std::printf("}");
}

void lib::source::SourceWorker::addPlatform(std::string platform) {
  if (std::filesystem::exists(std::filesystem::path(this->path)))
    throw std::exception();
  lib::source::Source index (this->path);
  index.addPlatform(platform);
  std::filesystem::create_directory(
    std::filesystem::path(this->path) / std::filesystem::path(platform));
  this->getPlatformWorker(platform).doInit();
  index.dump();
}

void lib::source::SourceWorker::removePlatform(std::string platform) {
  if (std::filesystem::exists(std::filesystem::path(this->path)))
    throw std::exception();
  lib::source::Source index (this->path);
  index.deletePlatform(platform);
  std::filesystem::remove_directory(
    std::filesystem::path(this->path) / std::filesystem::path(platform));
  index.dump();
}

void lib::source::SourceWorker::renamePlatform(std::string platform, std::string newname) {
  if (std::filesystem::exists(std::filesystem::path(this->path)))
    throw std::exception();
  lib::source::Source index (this->path);
  index.renamePlatform(platform, newname);
  std::filesystem::rename(
    std::filesystem::path(this->path) / std::filesystem::path(platform),
    std::filesystem::path(this->path) / std::filesystem::path(newname));
  index.dump();
}

void lib::source::SourceWorker::forkPlatform(std::string platform, std::string clonename) {
  if (std::filesystem::exists(std::filesystem::path(this->path)))
    throw std::exception();
  lib::source::Source index (this->path);
  if (! index.containsPlatform(platform))
    throw std::exception();
  index.addPlatform(clonename);
  std::filesystem::rename(
    std::filesystem::path(this->path) / std::filesystem::path(platform),
    std::filesystem::path(this->path) / std::filesystem::path(clonename));
  index.dump();
}

// access
lib::source::PlatformWorker
lib::source::SourceWorker::getPlatformWorker(std::string platform) {
  if (std::filesystem::exists(std::filesystem::path(this->path)))
    throw std::exception();
  return new lib::source::PlatformWorker(
    std::filesystem::path(this->path) / std::filesystem::path(platform));
}

lib::source::PackageWorker
lib::source::SourceWorker::getPackageWorker(std::string platform,
                                            std::string package) {
  if (std::filesystem::exists(std::filesystem::path(this->path)))
    throw std::exception();
  return lib::source::PlatformWorker(
    std::filesystem::path(this->path) / std::filesystem::path(platform))
      .getPackageWorker(package);
}

lib::source::VersionWorker
lib::source::SourceWorker::getVersionWorker(std::string platform,
                                            std::string package,
                                            std::string version) {
  if (std::filesystem::exists(std::filesystem::path(this->path)))
    throw std::exception();
  return lib::source::PlatformWorker(
    std::filesystem::path(this->path) / std::filesystem::path(platform))
      .getVersionWorker(package, version);
}