cmake_minimum_required(VERSION 3.5)

project(test LANGUAGES CXX)

set(CMAKE_CXX_COMPILER g++)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories (lib/include)


add_executable(test test.cpp)

add_library(lib STATIC IMPORTED)
set_target_properties(lib PROPERTIES
    IMPORTED_LOCATION ../lib/lib64/debug/libmysqlcppconn8-static.a
)
target_link_libraries(test lib)

target_link_libraries(test ssl crypto pthread resolv)