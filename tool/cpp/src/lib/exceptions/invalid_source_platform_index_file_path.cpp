#include<lib/exceptions/invalid_source_package_index_file_path.hpp>

lib::exceptions::InvalidSourcePackageIndexFilePath::InvalidSourcePackageIndexFilePath(std::string indexFilePath)
 : lib::exceptions::InvalidIndexFilePath("source package", indexFilePath) {}