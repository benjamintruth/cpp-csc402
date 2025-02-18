#include "myStack.h"
#include <iostream>
using namespace std;

vector<Employee>& myStack::getElts() {
    return elts;
}

void myStack::push(Employee emp) {
    elts.push_back(emp);
}

Employee myStack::pop() {
    if (!isEmpty()) {
        Employee topEmployee = elts.back();
        elts.pop_back();
        Employee emp = topEmployee;
        return emp;
    }
    cout << "ERROR - STACK IS EMPTY";
    exit(1);
}

bool myStack::isEmpty() {
    return elts.empty();
}

void myStack::printStack() {
    if (isEmpty()) {
        cout << "ERROR - STACK IS EMPTY" << endl;
        return;
    }
    for (auto it = elts.rbegin(); it != elts.rend(); ++it) {
        cout << *it;
    }
}