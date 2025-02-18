#pragma once
#include "Employee.h"
#include <vector>
using namespace std;

class myQueue {
protected:
    vector<Employee> elts;
public:
    vector<Employee>& getElts();
    void enqueue(Employee);
    Employee dequeue();
    bool isEmpty();
    void printQueue();

    // operator overload on addition
    myQueue operator+(const myQueue& other){
        myQueue temp;
        for (auto& emp : elts) {
            temp.enqueue(emp);
        }
        for (auto& emp : other.elts) {
            temp.enqueue(emp);
        }
        return temp;
    };
};
