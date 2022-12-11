#include<lib/types/index_file.hpp>

lib::types::IndexFile::IndexFile(std::string path) {
    this->path = path;
}

std::string lib::types::IndexFile::getPath() {
    return this->path;
}

std::string lib::types::IndexFile::getIndexPath() {
    return this->path + "/index.yml";
}
