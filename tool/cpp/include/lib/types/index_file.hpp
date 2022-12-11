#ifndef TOOL_LIB_TYPES_INDEX_FILE
#define TOOL_LIB_TYPES_INDEX_FILE

#include<string>

namespace lib::types {
    class IndexFile {
        std::string path;
        public:
            IndexFile(std::string path);
            
            std::string getPath();
            std::string getIndexPath();
    };
}

#endif
