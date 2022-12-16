#ifndef TOOL_LIB_EXCEPTIONS_INVALID_REPOSITORY_PACKAGE_INDEX_FILE_PATH
#define TOOL_LIB_EXCEPTIONS_INVALID_REPOSITORY_PACKAGE_INDEX_FILE_PATH

#include<string>
#include<stdexcept>
#include<lib/exceptions/invalid_index_file_path.hpp>

namespace lib::exceptions {
    class InvalidRepositoryPackageIndexFilePath : public InvalidIndexFilePath {
        public:
            InvalidRepositoryPackageIndexFilePath(std::string indexFilePath);
    };
}

#endif
