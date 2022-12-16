#include<lib/exceptions/invalid_source_version_index_file_path.hpp>

lib::exceptions::InvalidSourceVersionIndexFilePath::InvalidSourceVersionIndexFilePath(std::string indexFilePath)
 : lib::exceptions::InvalidIndexFilePath("source version", indexFilePath) {}