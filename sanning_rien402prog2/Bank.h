#pragma once
#define BANK_H
#include <string>
#include <vector>
#include "Account.h"
using namespace std;

class Bank {
    protected:
        vector<Account> allAccounts;
        Account dummyAccount;

    public:
        Account& findAccount( string id, string pin );
        void addAccount( Account & acct );
        void loadAccounts( ifstream & inf );
};

