#ifndef TOOL_LIB_SYSTEM_FILE_MANAGER
#define TOOL_LIB_SYSTEM_FILE_MANAGER

#include <string>

namespace lib::system {
    class FileManager {
        public:
            static void createFile(std::string filepath);
            static void deleteFile(std::string filepath);
            static void moveFile(std::string filepath, std::string newpath);
            static bool existsFile(std::string filepath);
            
            static void createDirectory(std::string dirpath);
            static void deleteDirectory(std::string dirpath);
            static void moveDirectory(std::string dirpath, std::string newpath);
            static bool existsDirectory(std::string dirpath);
    };
}

#endif