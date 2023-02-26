#include <gtest/gtest.h>

#include "vending_machine.h"

using namespace webfleet;

class VendingMachineTest : public ::testing::Test {
protected:
    VendingMachine vm;
};

// Test that the balance is initially zero
TEST_F(VendingMachineTest, InitialZeroBalance) {
    ASSERT_EQ(vm.getBalance(), 0);
}

// Test that the selection is initially NONE
TEST_F(VendingMachineTest, InitialNoneSelection) {
    ASSERT_EQ(vm.getSelectedDrink(), VendingMachine::DrinkType::NONE);
}

TEST_F(VendingMachineTest, DisplayMenuTest) {
    // Define the expected output string
    std::string expected_output = "\n-----WELCOME-----\n"
                "Please select a drink and then insert money\n"
                "Each drink costs 2€\n"
                "We only accept 1€, 2€, 5€ and 10€\n"
                "-----------------\n"
                "Press 'c' for Cola\n"
                "Press 'l' for Lemonade\n"
                "Press 'w' for Water\n"
                "-----------------\n";

    // Use GTest's Capture Output utility to capture the output of the function
    testing::internal::CaptureStdout();
    vm.displayMenu();
    std::string output = testing::internal::GetCapturedStdout();

    // Assert that the captured output matches the expected string
    ASSERT_EQ(expected_output, output);
}

TEST_F(VendingMachineTest, SelectDrinkTest) {
    // Test selecting Cola
    ASSERT_TRUE(vm.selectDrink('c'));
    ASSERT_EQ(VendingMachine::DrinkType::COLA, vm.getSelectedDrink());

    // Test selecting Lemonade
    ASSERT_TRUE(vm.selectDrink('l'));
    ASSERT_EQ(VendingMachine::DrinkType::LEMONADE, vm.getSelectedDrink());

    // Test selecting Water
    ASSERT_TRUE(vm.selectDrink('w'));
    ASSERT_EQ(VendingMachine::DrinkType::WATER, vm.getSelectedDrink());

    // Test selecting an invalid drink
    ASSERT_FALSE(vm.selectDrink('x'));
}

TEST_F(VendingMachineTest, InsertMoneyTest) {
    // Test inserting 1€
    ASSERT_TRUE(vm.insertMoney(1));
    ASSERT_EQ(1, vm.getBalance());

    // Test inserting 2€
    ASSERT_TRUE(vm.insertMoney(2));
    ASSERT_EQ(3, vm.getBalance());

    // Test inserting 5€
    ASSERT_TRUE(vm.insertMoney(5));
    ASSERT_EQ(8, vm.getBalance());

    // Test inserting 10€
    ASSERT_TRUE(vm.insertMoney(10));
    ASSERT_EQ(18, vm.getBalance());

    // Test inserting an invalid amount
    ASSERT_FALSE(vm.insertMoney(3));
    ASSERT_EQ(18, vm.getBalance());
}

TEST_F(VendingMachineTest, DispenseDrinkTest) {
    ASSERT_TRUE(vm.dispenseDrink());
}

TEST_F(VendingMachineTest, ReturnMoneyTest) {
    int balance = 10;

    // Insert money into vending machine
    ASSERT_TRUE(vm.insertMoney(balance));

    // Return money from vending machine
    std::string expectedOutput = "Return " + std::to_string(balance) + "€\n";
    testing::internal::CaptureStdout();
    bool result = vm.returnMoney(balance);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_TRUE(result);
    ASSERT_EQ(expectedOutput, output);

    // Attempt to return money from vending machine with zero balance
    balance = 0;
    testing::internal::CaptureStdout();
    result = vm.returnMoney(balance);
    output = testing::internal::GetCapturedStdout();

    ASSERT_FALSE(result);
    expectedOutput = "Oops! Something went wrong\nPlease contact our customer service\n";
    ASSERT_EQ(expectedOutput, output);
}

TEST_F(VendingMachineTest, CompleteTransaction_DispensesDrinkAndReturnsChange) {
    int insertedMoney = 10;
    vm.selectDrink('c');
    vm.insertMoney(insertedMoney);
    vm.completeTransaction();

    // dispense drink
    ASSERT_TRUE(vm.dispenseDrink());

    // Return money from vending machine
    int change = insertedMoney - VendingMachine::getCommonPrice();
    std::string expectedOutput = "Return " + std::to_string(change) + "€\n";
    testing::internal::CaptureStdout();
    bool result = vm.returnMoney(change);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_TRUE(result);
    ASSERT_EQ(expectedOutput, output);

    // Check if the balance and selected drink are reset
    ASSERT_EQ(vm.getBalance(), 0);
    ASSERT_EQ(vm.getSelectedDrink(), VendingMachine::DrinkType::NONE);
}

TEST_F(VendingMachineTest, ResetsBalanceAndSelectedDrink) {
    vm.insertMoney(2);
    vm.selectDrink('c');
    vm.reset();

    // Check if the balance and selected drink are reset
    ASSERT_EQ(vm.getBalance(), 0);
    ASSERT_EQ(vm.getSelectedDrink(), VendingMachine::DrinkType::NONE);
}

TEST_F(VendingMachineTest, CancelTransaction_ReturnsMoneyAndResets) {
    int insertedMoney = 5;

    vm.selectDrink('c');
    vm.insertMoney(insertedMoney);
    vm.cancelTransaction();

    // return all inserted money
    std::string expectedOutput = "Return " + std::to_string(insertedMoney) + "€\n";
    testing::internal::CaptureStdout();
    bool result = vm.returnMoney(insertedMoney);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(result);
    ASSERT_EQ(expectedOutput, output);

    // Check if the balance and selected drink are reset
    EXPECT_EQ(0, vm.getBalance());
    EXPECT_EQ(VendingMachine::DrinkType::NONE, vm.getSelectedDrink());

}
