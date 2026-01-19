cmake_minimum_required(VERSION 3.16)
project(L-Gen VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp
    src/core/scale.cpp
)

add_executable(lgen ${SOURCES})

target_include_directories(lgen PRIVATE src)
