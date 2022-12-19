#include <lib/source/source_worker.hpp>
#include <lib/cli/menu.hpp>
#include <stdexcept>
#include <iostream>

void worker(int argc, char** args) {
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

void cli(int argc, char** args) {
  lib::cli::Menu menu;
  menu.setName("tool");
  menu.parseArgs(argc, args);
}

int main(int argc, char** args) {
  worker(argc, args);
  // cli(argc, args);
}
