#include<lib/exceptions/invalid_source_index_file_path.hpp>

lib::exceptions::InvalidSourceIndexFilePath::InvalidSourceIndexFilePath(std::string indexFilePath)
 : lib::exceptions::InvalidIndexFilePath("source", indexFilePath) {}