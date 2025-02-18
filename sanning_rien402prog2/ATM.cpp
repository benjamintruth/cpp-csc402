#include "ATM.h"
#include "Bank.h"
#include "Account.h"
#include <iostream>
using namespace std;

void printStartOptions() {
    cout << "Please enter your command" << endl;
    cout << "Q – quit/exit" << endl;
    cout << "L – login to account" << endl;
}

void printTransactionOptions() {
    cout << endl << "Please enter your selection or Q to quit" << endl;
    cout << "W - withdraw funds" << endl;
    cout << "D - deposit funds" << endl;
    cout << "B - check balance" << endl;
    cout << "Q – quit/exit" << endl;
}

ATM::ATM(Bank bank) {
    assignedBank = bank;
}

void ATM::transactions(Account &account) {
    string userTextInput, userFundsInput;

    while (true) {
        // withdraw
        if (userTextInput == "W") {
            cout << "Please enter amount of withdraw: ";
            cin >> userFundsInput;
            account.Withdraw(stoi(userFundsInput));
        }
        // deposit
        else if (userTextInput == "D") {
            cout << "Please enter amount of deposit: ";
            cin >> userFundsInput;
            account.Deposit(stoi(userFundsInput));
        }
        // balance
        else if (userTextInput == "B") {
            account.printBalance();
        }
        // quit
        else if (userTextInput == "Q") {
            // exit transactions, go back to start
            cout << "Goodbye." << endl;
            start();
            return;
        }
        // bad command
        else {
            cout << "Unrecognized command " << userTextInput << endl;
        }
        // show options and await input
        printTransactionOptions();
        cin >> userTextInput;
    }

}

int ATM::start() {
    bool userSignedIn = false;
    int failedLoginAttempts = 0;
    string inputAccountID, inputAccountPIN, userTextInput;

    // main loop
    while (!userSignedIn) {
        // reading in user input
        // quit
        if (userTextInput == "Q") {
            cout << "Normal Exit" << endl;
            return 0;
        }
        // sign in
        else if (userTextInput == "L") {
            while (failedLoginAttempts <= 2) {
                // attempt login
                cout << "Please enter your Account ID: " << endl;
                cin >> inputAccountID;
                cout << "Please enter your account PIN: " << endl;
                cin >> inputAccountPIN;
                auto targetAccount = assignedBank.findAccount(inputAccountID, inputAccountPIN);
                // check result
                bool searchFailed = false;
                if (targetAccount.getAccountID() == "" and targetAccount.getAccountPIN() == "") {
                    searchFailed = true;
                }
                if (searchFailed) {
                    cout << "Sorry - No Match" << endl;
                    failedLoginAttempts++;
                }
                else {
                    cout << "Account Found" << endl;
                    userSignedIn = true;
                    transactions(targetAccount);
                }
            }
        } else {
            cout << "Unrecognized command " << userTextInput << endl;
        }
        if ( failedLoginAttempts == 3) {
            // exit
            return 1;
        }
        if (!userSignedIn) {
            printStartOptions();
        }
        cin >> userTextInput;
    }
}