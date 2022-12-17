#ifndef TOOL_LIB_TYPES_WORKER
#define TOOL_LIB_TYPES_WORKER

#include <string>
#include <lib/types/index_file.hpp>

namespace lib::types {
  class Worker : public IndexFile {
  public:
    Worker(std::string path);
    Worker();
  };
}

#endif