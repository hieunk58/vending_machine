/**
 * @file vending_machine.cpp
 * @author Hieu Nguyen
 * @brief 
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "vending_machine.h"

namespace webfleet
{
void VendingMachine::displayMenu() {
    std::cout << "-----WELCOME-----\n"
              << "Please select a drink. Each drink costs 2€\n"
              << "c for Cola\n"
              << "l for Lemonade\n"
              << "w for Water\n";
}

void VendingMachine::selectDrink(char selection) {
    switch (selection)
    {
    case 'c':
        m_selectedDrink = DrinkType::COLA;
        std::cout << "You selected: Cola\n";
        break;
    case 'l':
        m_selectedDrink = DrinkType::LEMONADE;
        std::cout << "You selected: Lemonade\n";
        break;
    case 'w':
        m_selectedDrink = DrinkType::WATER;
        std::cout << "You selected: Water\n";
        break;
    default:
        std::cout << "Invalid type of drink!!!\n\n";
        break;
    }
}

void VendingMachine::insertMoney(int amount) {
    switch (amount)
    {
    case 1:
    case 2:
    case 5:
    case 10:
        m_balance += amount;
        std::cout << "You inserted: " << m_balance << "€\n";
        break;
    
    default:
        std::cout << "Invalid amount of money\n";
        break;
    }
}

void VendingMachine::completeTransaction() {
    // dispense drink
    std::cout << "Dispensing your selected drink!\n";
    // return any change
    int changeMoney = m_balance - VendingMachine::common_price;
    if (changeMoney > 0) {
        std::cout << "Return " << changeMoney << "€ in change\n";
    }
    // update balance and currently selected drink
    m_balance = 0;
    m_selectedDrink = DrinkType::NONE;
}

void VendingMachine::cancelTransaction() {
    // user inserted some money but want to cancel
    if (m_balance > 0) {
        std::cout << "Transaction was cancelled. Return " << m_balance << "€\n";
        m_balance = 0;
        m_selectedDrink = DrinkType::NONE;
    } else
    {
        std::cout << "There is no transaction to cancel!\n";
    }
}
} // namespace webfleet
