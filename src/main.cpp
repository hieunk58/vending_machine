/**
 * @file main.cpp
 * @author Hieu Nguyen
 * @brief Main program
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>

#include "vending_machine.h"

int main(int argc, char const *argv[])
{
    webfleet::VendingMachine machine;
    machine.runMachine();
    
    return 0;
}
