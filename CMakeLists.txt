cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project ("lmc" VERSION 0.1.0)

set(SOURCE
    src/main.cpp
    src/lmc.cpp
)

add_executable (${PROJECT_NAME} ${SOURCE})
include_directories(${CMAKE_SOURCE_DIR}/include)
