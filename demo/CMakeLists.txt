cmake_minimum_required(VERSION 3.10)
project(demo)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM3 REQUIRED gtkmm-3.0)

add_executable(demo src/main.cpp src/main_window.cpp src/main_window.hpp)

target_link_libraries(demo CIRCUITSIM)
target_link_libraries(demo ${GTKMM3_LIBRARIES})
target_include_directories(demo PRIVATE ${GTKMM3_INCLUDE_DIRS})


install(TARGETS demo
        RUNTIME DESTINATION bin COMPONENT runtime
        LIBRARY DESTINATION lib COMPONENT runtime
        ARCHIVE DESTINATION lib COMPONENT dev)