#include <lib/system/file_manager.hpp>
#include <filesystem>
#include <fstream>

void lib::system::FileManager::createFile(std::string filepath) {
    std::ofstream file (filepath); file.close();
}

void lib::system::FileManager::deleteFile(std::string filepath) {
    std::filesystem::remove(filepath);
}

void lib::system::FileManager::copyFile(std::string filepath,
                                        std::string newpath) {
    std::filesystem::copy_file(filepath, newpath);
}

void lib::system::FileManager::moveFile(std::string filepath,
                                        std::string newpath) {
    std::filesystem::rename(filepath, newpath);
}

bool lib::system::FileManager::existsFile(std::string filepath) {
    return std::filesystem::exists(filepath);
}

void lib::system::FileManager::createDirectory(std::string dirpath) {
    std::filesystem::create_directories(dirpath);
}

void lib::system::FileManager::deleteDirectory(std::string dirpath) {
    std::filesystem::remove_all(dirpath);
}

void lib::system::FileManager::copyDirectory(std::string dirpath,
                                                std::string newpath) {
    std::filesystem::copy(dirpath, newpath);
}

void lib::system::FileManager::moveDirectory(std::string dirpath,
                                            std::string newpath) {
    std::filesystem::rename(dirpath, newpath);
}

bool lib::system::FileManager::existsDirectory(std::string dirpath) {
    return std::filesystem::exists(dirpath);
}

std::string lib::system::FileManager::getWorkingDirectory() {
    return std::filesystem::current_path().string();
}