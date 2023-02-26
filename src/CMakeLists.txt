set(SRC_FILES
    main.cpp
    vending_machine.cpp
)

add_executable(vending_machine ${SRC_FILES})
add_library(vending_machine_lib STATIC ${SRC_FILES})
