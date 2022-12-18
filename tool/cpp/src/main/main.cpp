#include <lib/source/source_worker.hpp>
#include <stdexcept>
#include <iostream>

int main(int argc, char** args) {
  try {
    lib::source::SourceWorker* worker = NULL;
    if (argc > 1) {
      worker = new lib::source::SourceWorker(args[1]);
    } else {
      worker = new lib::source::SourceWorker();
    }
    worker->printAll();
    delete worker;
  } catch(std::runtime_error& error) {
    std::cout << args[0] << ":: panic = " << error.what() << std::endl;
  } catch(std::exception& error) {
    std::cout << args[0] << ":: panic = " << error.what() << std::endl;
  }
}