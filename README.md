# VENDING MACHINE
This repository implements a working vending machine.
We assume our Vending Machine has following features:
- Unlimited money and drinks
- Only offers 3 types of drinks: Cola, Lemonade and Water. Each costs 2€
- Only accepts 1€, 2€, 5€ and 10€ for payment
- Runs in endless loop
- Be able to order only one drink at a time

Working flow:
- The machine is running in idle state and ready for order
- User presses button to select drinks: 'c' for Cola, 'l' for Lemonade and 'w' for Water
- User inserts money
- User confirms order by pressing 'y' or 'x' to cancel
- The machine dispenses selected drink and returns change (if any)
- The machine is back to idle state

## SETUP
Vending machine project uses some libraries for building, testing and generating documents:

- **CMake** for building project
- **Google Test** for unit testing
- **Doxygen** for source code documents
- **GCOVR** for code coverage report

In the next section, you will find the guide how to install these libraries in order to build and run this project. Currently, we supports running on Linux only.

First, clone this repo to your local machine:
```
git clone --recurse-submodules https://github.com/hieunk58/vending_machine
```
If your current git version does not support above command, you can try:

```
git clone https://github.com/hieunk58/vending_machine

git submodule update --init --recursive
```
After cloning this repo, you should see folder **googletest** inside **vending_machine/lib**.

Next we will install some libraries used by our project.
### INSTALL CMAKE
```
sudo snap install cmake
```
### INSTALL DOXYGEN
```
sudo apt-get install doxygen
```
### INSTALL GCOVR
```
pip install gcovr
```

## BUILDING
After installing all required libraries, we are ready to build our project.
Go to project source code and create a folder **build**
```
cd vending_machine
mkdir build
```
Go to folder build and start building
```
cd build
cmake ..
make
```
If everything is correct, two binary files **vending_machine** and **vending_machine_utest** are generated in **build/bin**

## RUNNING
Our main application name **vending_machine** locates in **build/bin**
Run below command to run it:
```
./vending_machine
```
This program is command line based application. You have to enter selection from the keyboard.
Here is an example working flow:

```
-----WELCOME-----
Please select a drink and then insert money
Each drink costs 2€
We only accept 1€, 2€, 5€ and 10€
-----------------
Press 'c' for Cola
Press 'l' for Lemonade
Press 'w' for Water
-----------------

Please enter your selection: c
You selected: Cola

Please insert money: 10
The total money you inserted: 10€

Confirm your order
Press 'y' to proceed or 'x' to cancel
Your selection: y
Dispensing your selected drink...
Done! Please get your drink at the compartment below
Return 8€
```

## DOXYGEN DOCUMENTS
We support generate doxygen documents by default in CMake file.
To generate document, run command:
```
cd build
make docs
```
In folder **build/docs/generated_docs/html**, open **index.html** in your browser to view the genrated document

## CODE COVERAGE REPORT
Code coverage is also supported by default in CMake file.
To generate code coverage report, run command:
```
cd build
make coverage
```
In folder **build/coverage**, open **index.html** in your browser to view the genrated code coverage report
