#include "Account.h"
#include <iostream>
#include <ostream>

Account::Account() {
    setAccountID("");
    setAccountPIN("");
    setAccountBalance(0.0);
}

Account::Account(string inputAccountID, string inputAccountPIN, double inputAccountBalance) {
    bool createDummyAccount = false;

    if (inputAccountID.length() != 8) {
        createDummyAccount = true;
    }
    if (inputAccountPIN.length() != 4) {
        createDummyAccount = true;
    }
    // scan through string for non-digit char
    for (int i = 0; i < inputAccountPIN.length(); ++i) {
        char c = inputAccountPIN[i];
        if (!isdigit(c)) {
            createDummyAccount = true;
        }
    }
    if (inputAccountBalance < 0.0) {
            createDummyAccount = true;
    }

    // wasn't sure what to do in the invalid input case, so just init as dummy
    if (createDummyAccount) {
        setAccountID("");
        setAccountPIN("");
        setAccountBalance(0.0);
    } else {
        setAccountID(inputAccountID);
        setAccountPIN(inputAccountPIN);
        setAccountBalance(inputAccountBalance);
    }
}

string Account::getAccountID() {
    return accountID;
}
void Account::setAccountID(string newAccountID) {
    accountID = newAccountID;
}

string Account::getAccountPIN() {
    return accountPIN;
}
void Account::setAccountPIN(string newAccountPIN) {
    accountPIN = newAccountPIN;
}

double Account::getAccountBalance() {
    return accountBalance;
}
void Account::setAccountBalance(double newAccountBalance) {
    accountBalance = newAccountBalance;
}

void Account::printBalance() {
    cout << "Balance: $" << getAccountBalance() << endl;
}

void Account::Deposit(double amount) {
    if (amount > 0) {
        setAccountBalance(getAccountBalance() + amount);
    }
}

void Account::Withdraw(double amount) {
    if (amount > 0 && amount < getAccountBalance()) {
        setAccountBalance(getAccountBalance() - amount);
    }
}