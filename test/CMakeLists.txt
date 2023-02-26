set(SRC_FILES
    main.cpp
    vending_machine_utest.cpp
    ../src/vending_machine.cpp
)

add_executable(vending_machine_utest ${SRC_FILES})
target_link_libraries(vending_machine_utest PRIVATE gtest gtest_main)

# generate code coverage report (html)
if(ENABLE_COVERAGE)
    include(CodeCoverage)
    append_coverage_compiler_flags()
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O0")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")

    setup_target_for_coverage_gcovr_html(
        NAME coverage
        EXECUTABLE vending_machine_utest
        EXCLUDE "${PROJECT_SOURCE_DIR}/lib" "${PROJECT_SOURCE_DIR}/src/main.cpp"
    )
endif()
