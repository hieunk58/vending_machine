cmake_minimum_required(VERSION 3.12)

project(VendingMachine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/bin")

add_subdirectory(src)
