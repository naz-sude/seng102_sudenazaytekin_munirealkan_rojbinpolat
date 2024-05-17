#ifndef ATM_H
#define ATM_H

#include <string>
#include "Customer.h"

using namespace std;

class ATM {
public:
    ATM();
    void start();
private:
    Customer* currentCustomer;
    void showWelcomeMessage();
    void authenticateUser();
    void showMainMenu();
    void checkBalance();
    void depositMoney();
    void withdrawMoney();
    void manageAccounts();
    void showSavingsAccountInfo();
    void showFixedDepositAccountInfo();
    void showCheckingAccountInfo();
    void exitATM();
};

#endif // ATM_H
