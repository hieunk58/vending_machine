cmake_minimum_required(VERSION 3.12)

project(VendingMachine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/bin")
# cmake module path for CodeCoverage.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

option(ENABLE_UTEST "Enable unit tests" ON)
option(ENABLE_DOXYDOC "Generate doxygen document" ON)
option(ENABLE_COVERAGE "Generate code coverage report" ON)

include_directories(src)

add_subdirectory(src)

# enable unit tests
if(ENABLE_UTEST)
    add_subdirectory(test)
    add_subdirectory(lib/googletest)
endif()

# generate doxygen document
if(ENABLE_DOXYDOC)
    add_subdirectory(docs) 
endif()
