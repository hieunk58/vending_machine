cmake_minimum_required(VERSION 3.12)

project(VendingMachine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/bin")

option(ENABLE_UTEST "Enable unit tests" OFF)
option(ENABLE_DOXYDOC "Generate doxygen document" OFF)

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
