#include <iostream>
#include <fstream>
#include "Bank.h"
#include "ATM.h"

int main() {
    ifstream inf;
    Bank bk;

    // get accounts file
    string input_filepath;
    cout << "Please enter account information filepath: ";
    cin >> input_filepath;
    inf.open(input_filepath);
    if(!inf) {
        cerr << "Error opening file " << input_filepath << endl;
        exit(-1);
    }

    bk.loadAccounts(inf);

    ATM ATM(bk);
    ATM.start();

    return 0;
}
