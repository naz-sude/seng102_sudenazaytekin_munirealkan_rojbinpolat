#include "Customer.h"

using namespace std;

vector<Customer> Customer::customers = {
    Customer(12345, 54321, 1000.0),
    Customer(67890, 98765, 2000.0),
    Customer(11223, 33211, 3000.0)
};

Customer::Customer(int accountNumber, int pin, double balance)
    : accountNumber(accountNumber), pin(pin), balance(balance) {}

Customer* Customer::authenticate(int accountNumber, int pin) {
    for (auto& customer : customers) {
        if (customer.accountNumber == accountNumber && customer.pin == pin) {
            return &customer;
        }
    }
    return nullptr;
}

double Customer::getBalance() const {
    return balance;
}

void Customer::deposit(double amount) {
    balance += amount;
}

void Customer::withdraw(double amount) {
    balance -= amount;
}
