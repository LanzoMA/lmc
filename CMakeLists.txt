cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("lmc")

add_executable (${PROJECT_NAME} "src/main.cpp" "src/lmc.cpp")

include_directories(${CMAKE_SOURCE_DIR}/include)