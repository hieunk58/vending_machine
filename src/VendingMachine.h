/**
 * @file VendingMachine.h
 * @author Hieu Nguyen
 * @brief 
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef VENDING_MACHINE_H_
#define VENDING_MACHINE_H_

#include <iostream>

namespace webfleet {
class VendingMachine {
public:
    VendingMachine() : m_balance(0), m_selectedDrink(DrinkType::NONE) {}

    /**
     * @brief Display menu of drink to users
     * 
     */
    void displayMenu();

    /**
     * @brief Update currently selected drink from user input
     * 
     * @param selection character represents selected drink
     */
    void selectDrink(char selection);
private:
    /**
     * @brief an enum class represents types of drink 
     * that vending machine offers
     * 
     */
    enum class DrinkType {
        NONE=0,        /**< Not a drink */
        COLA=1,        /**< Cola */
        LEMONADE=2,    /**< Lemonade */
        WATER=3        /**< Water */
    };

    int m_balance; /**< total amount of inserted money */
    DrinkType m_selectedDrink; /**< currently selected drink */
};

} // namespace webfleet

#endif // VENDING_MACHINE_H_