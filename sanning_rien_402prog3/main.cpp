#include "Employee.h"
#include "myStack.h"
#include "myQueue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // prompt first filepath
    string filePath1, filePath2;
    cout << "Please enter a path for file #1: ";
    cin >> filePath1;

    // load first file
    ifstream inputFile(filePath1);
    if (!inputFile) {
        cerr << "Error opening file: " << filePath1 << endl;
        exit(1);
    }

    // init first set of data stores
    myStack S1;
    myQueue Q1;

    // reading
    string firstName, lastName, socsecnum, deptNum;
    double wage;
    while (inputFile >> lastName >> firstName >> socsecnum >> deptNum >> wage) {
        Employee empUn = Employee(firstName, lastName, socsecnum, deptNum, wage);
        Employee empDeux = Employee(firstName, lastName, socsecnum, deptNum, wage);
        S1.push(empUn);
        Q1.enqueue(empDeux);
    }

    // init second set of data stores
    myStack S2;
    myQueue Q2;

    // close first input file
    inputFile.close();

    // prompt second file
    cout << "Please enter a path for file #2: ";
    cin >> filePath2;

    // load second file
    ifstream inputFile2(filePath2);
    if (!inputFile2) {
        cerr << "Error opening file: " << filePath2 << endl;
        exit(1);
    }
    while (inputFile2 >> lastName >> firstName >> socsecnum >> deptNum >> wage) {
        // you may notice that the employee class loads firstname, lastname - a trace of a bug in my first draft
        // I was reading in data first name, last name, and then wondering why my sort was broken
        // it's a little bad practice to not create the employee with params in the same order as read but I think
        // this comment allows me to justify it as a learning experience
        Employee empUno = Employee(firstName, lastName, socsecnum, deptNum, wage);
        Employee empDos = Employee(firstName, lastName, socsecnum, deptNum, wage);
        S2.push(empUno);
        Q2.enqueue(empDos);
    }
    inputFile2.close();

    // printing original stores
    cout << "STACK #1" << endl;
    S1.printStack();
    cout << endl << "QUEUE #1" << endl;
    Q1.printQueue();
    cout << endl << "STACK #2" << endl;
    S2.printStack();
    cout << endl << "QUEUE #2" << endl;
    Q2.printQueue();

    // sorting
    sort(S1.getElts().begin(), S1.getElts().end(), less<Employee>());
    sort(Q1.getElts().begin(), Q1.getElts().end(), less<Employee>());
    sort(S2.getElts().begin(), S2.getElts().end(), less<Employee>());
    sort(Q2.getElts().begin(), Q2.getElts().end(), less<Employee>());

    // printing en plus
    cout << endl << "AFTER SORTING ALL VECTORS" << endl;
    cout << endl << "STACK #1" << endl;
    S1.printStack();
    cout << endl << "QUEUE #1" << endl;
    Q1.printQueue();
    cout << endl << "STACK #2" << endl;
    S2.printStack();
    cout << endl << "QUEUE #2" << endl;
    Q2.printQueue();

    // third set
    myStack S3;
    myQueue Q3;
    S3 = S1 + S2;
    Q3 = Q1 + Q2;

    // printing combo containers
    cout << endl << "After overloaded operator +" << endl;
    cout << endl << "STACK #3" << endl;
    S3.printStack();
    cout << endl << "QUEUE #3" << endl;
    Q3.printQueue();

    // sort combos
    sort(S3.getElts().begin(), S3.getElts().end(), less<Employee>());
    sort(Q3.getElts().begin(), Q3.getElts().end(), less<Employee>());

    // print sorted combos
    cout << endl << "After SORTING" << endl;
    cout << endl << "STACK #3" << endl;
    S3.printStack();
    cout << endl << "QUEUE #3" << endl;
    Q3.printQueue();

    // poppin'
    cout << endl << "REMOVING ALL ITEMS FROM S2 and Q2" << endl << "Items POPPED from Stack S2" << endl;
    while (!S2.isEmpty()) {
        auto emp = S2.pop();
        cout << "POPPING " << emp;
    }
    S2.printStack();

    // dairy queen
    cout << endl << "Items DEQUEUED from Queue Q2" << endl;
    while (!Q2.isEmpty()) {
        auto emp = Q2.dequeue();
        cout << "DEQUEUEING " << emp;
    }
    Q2.printQueue();

    cout << endl << "PROGRAM EXECUTION IS COMPLETE" << endl;
    return 0;
}

// employee left shift overload
ostream& operator<<(ostream& out, Employee & E) {
    out << E.lastName << " " << E.firstName << " " << E.socsecnum << " " << E.deptNum << " " << E.wage << endl;;
    return out;
}