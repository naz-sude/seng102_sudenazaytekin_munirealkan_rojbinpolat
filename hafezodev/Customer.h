#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

using namespace std;

class Customer {
public:
    Customer(int accountNumber, int pin, double balance);
    static Customer* authenticate(int accountNumber, int pin);
    double getBalance() const;
    void deposit(double amount);
    void withdraw(double amount);

private:
    int accountNumber;
    int pin;
    double balance;
    static vector<Customer> customers;
};

#endif // CUSTOMER_H
