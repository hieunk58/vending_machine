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
    machine.displayMenu();

    char selection;
    std::cin >> selection;

    machine.selectDrink(selection);

    std::cout << "Now insert money. We only accept 1€, 2€, 5€ and 10€!\n";
    int amount;
    std::cin >> amount;
    machine.insertMoney(amount);
    // test cancel transaction
    machine.cancelTransaction();


    // machine.completeTransaction();


    return 0;
}
