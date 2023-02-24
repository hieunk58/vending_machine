#include "VendingMachine.h"

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
} // namespace webfleet
