#include <iostream>
#include "MyQueue.h"
#include "MyQueue.cpp"
#include <fstream>

using namespace std;

int main()
{
    // inits
    MyQueue<int> intQueue;
    MyQueue<string> stringQueue;
    MyQueue<double> doubleQueue;

    // request inFile
    string inFilename;
    cout << "Please enter a inFile path: ";
    cin >> inFilename;

    // attempt open
    ifstream inFile(inFilename);
    if (!inFile) {
        cerr << "Error opening inFile." << endl;
        return 1;
    }

    // read the ints
    int intEltCount;
    inFile >> intEltCount;
    for (int i = 0; i < intEltCount; ++i) {
        int value;
        inFile >> value;
        intQueue.Enqueue(value);
    }

    // the strings
    int stingEltCount;
    inFile >> stingEltCount;
    for (int i = 0; i < stingEltCount; ++i) {
        string str;
        inFile >> str;
        stringQueue.Enqueue(str);
    }

    // and the dubz
    int doubleEltCount;
    inFile >> doubleEltCount;
    for (int i = 0; i < doubleEltCount; ++i) {
        double dbl;
        inFile >> dbl;
        doubleQueue.Enqueue(dbl);
    }

    // close the file
    inFile.close();

    // print / dequeue
    cout << endl << "Queued Integers" << endl;
    intQueue.DequeuePrint();
    cout << endl << "Queued Strings" << endl;
    stringQueue.DequeuePrint();
    cout << endl << "Queued Doubles" << endl;
    doubleQueue.DequeuePrint();

    // that's all folks
    return 0;
}