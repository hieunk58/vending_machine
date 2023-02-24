#include "VendingMachine.h"

namespace webfleet
{
void VendingMachine::displayMenu() {
    std::cout << "-----WELCOME-----\n"
              << "Please select a drink!\n"
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
} // namespace webfleet
