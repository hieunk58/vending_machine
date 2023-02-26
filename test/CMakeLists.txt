set(SRC_FILES
    main.cpp
    vending_machine_utest.cpp
)

add_executable(vending_machine_utest ${SRC_FILES})
target_link_libraries(vending_machine_utest PRIVATE  vending_machine_lib gtest gtest_main)
