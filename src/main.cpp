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

#include "VendingMachine.h"

int main(int argc, char const *argv[])
{
    webfleet::VendingMachine machine;
    machine.displayMenu();

    char selection;
    std::cin >> selection;

    machine.selectDrink(selection);
    
    return 0;
}
