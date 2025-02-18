#pragma once
#include "Account.h"
#include "Bank.h"
#define ATM_H

class ATM {

protected:
    Bank assignedBank;

public:
    ATM(Bank bank);
    int start();
    void transactions( Account & account );
};