#ifndef TOOL_LIB_EXCEPTIONS_INVALID_SOURCE_PACKAGE_INDEX_FILE_PATH
#define TOOL_LIB_EXCEPTIONS_INVALID_SOURCE_PACKAGE_INDEX_FILE_PATH

#include<string>
#include<stdexcept>
#include<lib/exceptions/invalid_index_file_path.hpp>

namespace lib::exceptions {
    class InvalidSourcePackageIndexFilePath : public InvalidIndexFilePath {
        public:
            InvalidSourcePackageIndexFilePath(std::string indexFilePath);
    };
}

#endif
