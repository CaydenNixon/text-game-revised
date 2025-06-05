cmake_minimum_required(VERSION 3.10)

project(my_program LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

file(GLOB SOURCES "src/*.cpp")

add_executable(my_program ${SOURCES})

if(MINGW)
    target_compile_options(my_program PRIVATE -Wall -Wextra)
endif()