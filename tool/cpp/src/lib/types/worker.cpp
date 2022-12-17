#include<lib/types/worker.hpp>
#include <lib/system/file_manager.hpp>

lib::types::Worker::Worker(std::string path)
: lib::types::IndexFile(path) {}

lib::types::Worker::Worker()
: lib::types::IndexFile(lib::system::FileManager::getWorkingDirectory()) {}