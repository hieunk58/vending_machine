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
    std::cout << "\n-----WELCOME-----\n"
              << "Please select a drink and then insert money\n"
              << "Each drink costs 2€\n"
              << "We only accept 1€, 2€, 5€ and 10€\n"
              << "-----------------\n"
              << "Press 'c' for Cola\n"
              << "Press 'l' for Lemonade\n"
              << "Press 'w' for Water\n"
              << "-----------------\n";
}

bool VendingMachine::selectDrink(char selection) {
    bool result = true;
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
        std::cout << "Invalid type of drink!!!\n";
        result = false;
        break;
    }

    return result;
}

bool VendingMachine::insertMoney(int amount) {
    bool result = true;
    switch (amount)
    {
    case 1:
    case 2:
    case 5:
    case 10:
        m_balance += amount;
        std::cout << "The total money you inserted: " << m_balance << "€\n";
        break;
    
    default:
        std::cout << "Invalid amount of money\n"
                  << "We only accept 1€, 2€, 5€ and 10€\n";
        result = false;
        break;
    }
    
    return result;
}

bool VendingMachine::dispenseDrink() {
    bool result = true;

    std::cout << "Dispensing your selected drink...\n";
    std::cout << "Done! Please get your drink "
                "at the compartment below\n";

    return result;
}

bool VendingMachine::returnMoney(int amount) {
    bool result = true;

    if (amount) {
        std::cout << "Return " << amount << "€\n";
    } else {
        std::cout << "Oops! Something went wrong\nPlease contact our "
                    "customer service\n";
        result = false;
    }

    return result;
}

void VendingMachine::reset() {
    // reset balance and selected drink
    m_balance = 0;
    m_selectedDrink = DrinkType::NONE;
}

void VendingMachine::completeTransaction() {
    // dispense drink
    dispenseDrink();
    // calculate and return any change
    int changeMoney = m_balance - VendingMachine::common_price;
    if (changeMoney > 0) {
        returnMoney(changeMoney);
    }
    reset();
}

void VendingMachine::cancelTransaction() {
    std::cout << "Cancel transaction\n";
    // return inserted money (if any)
    if (m_balance > 0) {
        returnMoney(m_balance);
    }
    reset();
}

void VendingMachine::runMachine() {
    while (true) {
        // display menu to user
        displayMenu();

        // select drink
        char selection;
        do {
            std::cout << "\nPlease enter your selection: ";
            std::cin >> selection;
        } while (!selectDrink(selection));

        // insert money
        int money;
        do {
            std::cout << "\nPlease insert money: ";
            std::cin >> money;

            // unsupported money
            if (!insertMoney(money)) {
                cancelTransaction();
                break;
            }

            // not enough money
            if (m_balance < common_price) {
                std::cout << "\nNot enough money!";
                continue;
            }

            // confirm order
            std::cout << "\nConfirm your order\n"
                      << "Press 'y' to proceed or 'x' to cancel\n";
            std::cout << "Your selection: ";
            char confirm;
            std::cin >> confirm;

            if (confirm == 'x') {
                cancelTransaction();
                break;
            } else {
                completeTransaction();
                break;
            }
        } while (true);
    }
}
} // namespace webfleet
