#include "VendingMachine.h"

namespace webfleet
{
void VendingMachine::displayMenu() {
    std::cout << "-----WELCOME-----\n"
              << "Please select a drink!\n"
              << "c for Cola\n"
              << "l for Lemonade\n"
              << "w for Water\n"
              << "x to Cancel\n";
}

} // namespace webfleet
