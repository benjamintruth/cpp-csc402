#pragma once
#include "Employee.h"
#include <vector>
using namespace std;

class myStack {
    protected:
        vector<Employee> elts;
    public:
        vector<Employee> & getElts();
        void push(Employee);
        Employee pop();
        bool isEmpty();
        void printStack();

        // operator overload on addition
        myStack operator+(const myStack& other) {
            myStack temp;
            for (auto it = elts.rbegin(); it != elts.rend(); ++it) {
                temp.push(*it);
            }
            for (auto it = other.elts.rbegin(); it != other.elts.rend(); ++it) {
                temp.push(*it);
            }
            return temp;
        };
};