#include "MyQueue.h"
#include <iostream>
using namespace std;

template<typename T>
void MyQueue<T>::Enqueue(T item) {
    elements.push_back(item);
}

template<typename T>
T MyQueue<T>::Dequeue() {
    auto frontEltValue = elements.front();
    elements.erase(elements.begin());
    return frontEltValue;
}

template<typename T>
void MyQueue<T>::DequeuePrint() {
    while (!elements.empty()) {
        cout << Dequeue() << endl;
    }
}