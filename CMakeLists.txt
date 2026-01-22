cmake_minimum_required(VERSION 3.16)
project(L-Gen VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ========================
# Core Library
# ========================
add_library(lgen_core
    src/core/rhythm.cpp
    src/core/scale.cpp
    src/core/pattern.cpp
)

target_include_directories(lgen_core
    PUBLIC
        ${PROJECT_SOURCE_DIR}/src
)

# ========================
# Executable
# ========================
add_executable(lgen
    src/main.cpp
)

target_link_libraries(lgen
    PRIVATE lgen_core
)
