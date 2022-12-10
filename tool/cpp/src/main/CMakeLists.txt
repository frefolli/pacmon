add_executable(main main.cpp)
target_include_directories(main ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(main ${CONAN_LIBS} libsource)
