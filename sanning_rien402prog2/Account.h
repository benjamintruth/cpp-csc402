#pragma once
#define ACCOUNT_H
#include <string>
using namespace std;

class Account {
    protected:
        string accountID;
        string accountPIN;
        double accountBalance;

    public:
        Account();
        Account(string inputAccountID, string inputAccountPIN, double inputAccountBalance);
        string getAccountID();
        void setAccountID(string accountID);
        string getAccountPIN();
        void setAccountPIN(string accountPIN);
        double getAccountBalance();
        void setAccountBalance(double accountBalance);
        void printBalance();
        void Deposit( double amount );
        void Withdraw( double amount );
};