set(SRC_FILES
    main.cpp
)

add_executable(vending_machine_utest ${SRC_FILES})
target_link_libraries(vending_machine_utest PRIVATE gtest gtest_main)
