cmake_minimum_required(VERSION 3.5)

project(test LANGUAGES CXX)

set(CMAKE_CXX_COMPILER clang++)

 #add_compile_options(-pthread)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(1_ex 1_ex.cpp)
add_executable(2_ex 2_ex.cpp)
add_executable(3_ex 3_ex.cpp)

find_package(Threads REQUIRED)
target_link_libraries(1_ex Threads::Threads)
target_link_libraries(2_ex Threads::Threads)
target_link_libraries(3_ex Threads::Threads)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)




