cmake_minimum_required(VERSION 3.12)

project(VendingMachine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/bin")

option(ENABLE_UTEST "Enable unit tests" OFF)

add_subdirectory(src)

# enable unit tests
if(ENABLE_UTEST)
    add_subdirectory(test)
    add_subdirectory(lib/googletest)
endif()