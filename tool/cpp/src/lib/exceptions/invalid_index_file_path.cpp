#include<lib/exceptions/invalid_index_file_path.hpp>

lib::exceptions::InvalidIndexFilePath::InvalidIndexFilePath(std::string context, 
                                                            std::string indexFilePath)
: std::runtime_error(context + ": invalid index file path \"" + indexFilePath + "\"") {
    this->context = context;
    this->indexFilePath = indexFilePath;
}

std::string lib::exceptions::InvalidIndexFilePath::getContext() {
    return this->context;
}

std::string lib::exceptions::InvalidIndexFilePath::getIndexFilePath() {
    return this->indexFilePath;
}