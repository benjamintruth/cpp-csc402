#include "Bank.h"
#include "Account.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Account & Bank::findAccount(string id, string pin) {
    for (auto iter = allAccounts.rbegin(); iter != allAccounts.rend(); ++iter) {
        if (iter->getAccountID() == id && iter->getAccountPIN() == pin) {
            return *iter;
        }
    }
    return dummyAccount;
}

void Bank::addAccount(Account &account) {
    allAccounts.push_back(account);
}

void Bank::loadAccounts(ifstream &inf) {
    string line;
    while (getline(inf, line)) {
        // string stream not in the file i/o slides, hope this is cool
        istringstream lineStream(line);
        string accountID, accountPIN;
        double accountBalance;

        if (lineStream >> accountID >> accountPIN >> accountBalance) {
            Account newAccount(accountID, accountPIN, accountBalance);
            allAccounts.push_back(newAccount);
        }
    }
}