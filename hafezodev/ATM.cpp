#include <iostream>
#include "ATM.h"

using namespace std;

ATM::ATM() : currentCustomer(nullptr) {}

void ATM::start() {
    while (true) {
        showWelcomeMessage();
        authenticateUser();
        if (currentCustomer) {
            showMainMenu();
        }
    }
}

void ATM::showWelcomeMessage() {
    cout << "Welcome to the ATM!" << endl;
}

void ATM::authenticateUser() {
    int accountNumber;
    int pin;

    cout << "Enter Account Number: ";
    cin >> accountNumber;
    cout << "Enter PIN: ";
    cin >> pin;

    currentCustomer = Customer::authenticate(accountNumber, pin);

    if (!currentCustomer) {
        cout << "Invalid Account Number or PIN!" << endl;
    }
}

void ATM::showMainMenu() {
    int choice;
    do {
        cout << "1. View Balance\n2. Deposit Funds\n3. Withdraw Cash\n4. Exit\n5. Manage Accounts\nSelect an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            checkBalance();
            break;
        case 2:
            depositMoney();
            break;
        case 3:
            withdrawMoney();
            break;
        case 4:
            exitATM();
            break;
        case 5:
            manageAccounts();
            break;
        default:
            cout << "Invalid Choice!" << endl;
        }
    } while (choice != 4);
}

void ATM::checkBalance() {
    cout << "Your balance is: $" << currentCustomer->getBalance() << endl;
    cout << "1. Main Menu\n2. Exit\nSelect an option: ";
    int choice;
    cin >> choice;
    if (choice == 2) {
        exitATM();
    }
}

void ATM::depositMoney() {
    int amount;
    cout << "Enter deposit amount in cents (or 0 to cancel): ";
    cin >> amount;

    if (amount == 0) {
        cout << "Transaction canceled." << endl;
        return;
    }

    if (amount > 0) {
        double depositAmount = amount / 100.0;
        currentCustomer->deposit(depositAmount);
        cout << "Please insert deposit envelope..." << endl;
        // Simulate deposit envelope insertion
        cout << "Amount deposited. New balance: $" << currentCustomer->getBalance() << endl;
    }
    else {
        cout << "Invalid amount!" << endl;
    }
}

void ATM::withdrawMoney() {
    int choice;
    do {
        cout << "Select withdrawal amount:\n1. $20\n2. $40\n3. $60\n4. $100\n5. $200\n6. Cancel\nSelect an option: ";
        cin >> choice;

        double amounts[] = { 20.0, 40.0, 60.0, 100.0, 200.0 };

        if (choice >= 1 && choice <= 5) {
            double amount = amounts[choice - 1];
            if (amount <= currentCustomer->getBalance()) {
                currentCustomer->withdraw(amount);
                cout << "Please take your cash. New balance: $" << currentCustomer->getBalance() << endl;
            }
            else {
                cout << "Insufficient balance!" << endl;
            }
        }
        else if (choice != 6) {
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);
}

void ATM::manageAccounts() {
    int choice;
    cout << "Select account type:\n1. Savings Account\n2. Fixed Deposit Account\n3. Checking Account\nSelect an option: ";
    cin >> choice;

    switch (choice) {
    case 1:
        showSavingsAccountInfo();
        break;
    case 2:
        showFixedDepositAccountInfo();
        break;
    case 3:
        showCheckingAccountInfo();
        break;
    default:
        cout << "Invalid choice!" << endl;
    }

    cout << "4. Main Menu\n5. Exit\nSelect an option: ";
    int menuChoice;
    cin >> menuChoice;
    if (menuChoice == 5) {
        exitATM();
    }
}

void ATM::showSavingsAccountInfo() {
    cout << "Savings Account Information:\n";
    cout << "1. Interest Rate Calculation: Savings accounts usually earn interest at a specified rate, calculated periodically (monthly or yearly).\n";
    cout << "2. Transaction Fee: Fees may apply for certain transactions or when exceeding a transaction limit.\n";
    cout << "3. Minimum Balance Check: Alerts are sent if the account balance falls below a certain minimum threshold.\n";
}

void ATM::showFixedDepositAccountInfo() {
    cout << "Fixed Deposit Account Information:\n";
    cout << "1. Fixed Interest Rate: Earns interest at a fixed rate for a specified term.\n";
    cout << "2. Maturity Alerts: Notifications are sent as the maturity date approaches or when the term ends.\n";
    cout << "3. Early Withdrawal Penalty: Penalties may apply if funds are withdrawn before the maturity date.\n";
}

void ATM::showCheckingAccountInfo() {
    cout << "Checking Account Information:\n";
    cout << "1. Transaction Fee: Fees may apply for certain transactions or when exceeding a transaction limit.\n";
    cout << "2. Negative Balance Alerts: Alerts are sent if the account balance becomes negative.\n";
    cout << "3. Automatic Payments: Allows automatic deduction of specific bills or payments from the account.\n";
}

void ATM::exitATM() {
    cout << "Thank you for using the ATM!" << endl;
    exit(0); // Terminate the program
}
