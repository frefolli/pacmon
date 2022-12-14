#include <lib/source/source_worker.hpp>

lib::source::SourceWorker::SourceWorker(std::string path) {
    // TODO
}

lib::source::SourceWorker::SourceWorker() {
    // TODO
}

lib::source::SourceWorker::~SourceWorker() {
    // TODO
}

// actions
void lib::source::SourceWorker::doInit() {
    // TODO
}

void lib::source::SourceWorker::listPlatforms(std::string platform) {
    // TODO
}

void lib::source::SourceWorker::addPlatform(std::string platform) {
    // TODO
}

void lib::source::SourceWorker::removePlatform(std::string platform) {
    // TODO
}

void lib::source::SourceWorker::renamePlatform(std::string platform, std::string newname) {
    // TODO
}

void lib::source::SourceWorker::forkPlatform(std::string platform, std::string clonename) {
    // TODO
}

// access
lib::source::PlatformWorker*
lib::source::SourceWorker::getPlatformWorker(std::string platform) {
    // TODO
}

lib::source::PackageWorker*
lib::source::SourceWorker::getPackageWorker(std::string platform,
                                            std::string package) {
    // TODO
}

lib::source::VersionWorker*
lib::source::SourceWorker::getVersionWorker(std::string platform,
                                            std::string package,
                                            std::string version) {
    // TODO
}
