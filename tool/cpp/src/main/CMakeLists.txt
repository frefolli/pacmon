add_executable(main main.cpp)

target_include_directories(main
    PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(main
    libsource librepository
    libtypes libexceptions
    libsystem
    yaml-cpp ${Boost_LIBRARIES})
