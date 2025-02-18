#include "myQueue.h"
#include <iostream>
using namespace std;

vector<Employee>& myQueue::getElts() {
    return elts;
}

void myQueue::enqueue(Employee emp) {
    elts.push_back(emp);
}

Employee myQueue::dequeue() {
    if (!isEmpty()) {
        Employee frontEmployee = elts.front();
        elts.erase(elts.begin());
        return frontEmployee;
    }
    cout << "ERROR - QUEUE is EMPTY";
    exit(1);
}

bool myQueue::isEmpty() {
    return elts.empty();
}

void myQueue::printQueue() {
    if (isEmpty()) {
        cout << "ERROR - QUEUE IS EMPTY" << endl;
        return;
    }
    for (auto it = elts.begin(); it != elts.end(); ++it) {
        cout << *it;
    }
}