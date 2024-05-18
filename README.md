ATM System Documentation



Overview


This ATM system allows users to perform basic financial transactions such as viewing account balances, depositing funds, withdrawing cash, and managing different types of accounts (Savings Account, Fixed Deposit Account, and Checking Account). The system includes user authentication and provides a menu-driven interface.

File Structure


main.cpp: Entry point for the program.


ATM.h: Declaration of the ATM class.


ATM.cpp: Implementation of the ATM class.


Customer.h: Declaration of the Customer class.


Customer.cpp: Implementation of the Customer class.


Class Descriptions


ATM Class


File: ATM.h, ATM.cpp


Purpose: Manages the ATM's functionality including user authentication, displaying menus, and handling transactions.


Attributes:


Customer* currentCustomer: Pointer to the authenticated customer (initially nullptr).


Methods:



ATM(): Constructor initializing currentCustomer to nullptr.


void start(): Starts the ATM system, handles user authentication, and displays the main menu.


void showWelcomeMessage(): Displays a welcome message.


void authenticateUser(): Prompts for account number and PIN, and authenticates the user.


void showMainMenu(): Displays the main menu and handles user selections.


void checkBalance(): Shows the user's balance and provides options to return to the menu or exit.


void depositMoney(): Prompts for deposit amount, simulates deposit, and updates the balance.


void withdrawMoney(): Prompts for withdrawal amount, checks balance, and updates the balance.


void manageAccounts(): Provides options for managing different account types.


void showSavingsAccountInfo(): Displays information about the savings account.


void showFixedDepositAccountInfo(): Displays information about the fixed deposit account.


void showCheckingAccountInfo(): Displays information about the checking account.


void exitATM(): Exits the program with a thank you message.


Customer Class


File: Customer.h, Customer.cpp



Purpose: Represents a bank customer and includes methods for authentication and managing account balance.



Attributes:



int accountNumber: The customer's account number.


int pin: The customer's PIN.


double balance: The customer's balance.


static vector<Customer> customers: List of all customers.,


Methods:


Customer(int accountNumber, int pin, double balance): Initializes the customer's account number, PIN, and balance.


*static Customer authenticate(int accountNumber, int pin)**: Authenticates the customer based on account number and PIN.


double getBalance() const: Returns the customer's balance.


void deposit(double amount): Deposits the specified amount into the customer's account.


void withdraw(double amount): Withdraws the specified amount from the customer's account.


Main Function


File: main.cpp


Purpose: Entry point for the program, creates an instance of the ATM class and starts the system.


cpp

#include "ATM.h"


int main() {
    ATM atm;
    atm.start();
    return 0;
}
Usage

Compilation: Compile using a C++ compiler.



g++ main.cpp ATM.cpp Customer.cpp -o atm


Execution: Run the compiled program.


./atm
Interaction: Authenticate and perform transactions through the menu.


Summary

The ATM class handles user interactions and transactions, while the Customer class represents bank customers with methods for authentication and balance management. Together, they create a functional ATM system for basic banking operations.


Sudenaz Aytekin
221504027

-------------------------

Münire Alkan
221504011

-------------------------

Rojbin Polat
221504035

-------------------------

Software Engineering
