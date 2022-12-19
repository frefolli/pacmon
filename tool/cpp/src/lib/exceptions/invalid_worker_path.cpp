#include<lib/exceptions/invalid_worker_path.hpp>

lib::exceptions::InvalidWorkerPath::InvalidWorkerPath(std::string path)
 : lib::exceptions::InvalidIndexFilePath("worker", path) {}
