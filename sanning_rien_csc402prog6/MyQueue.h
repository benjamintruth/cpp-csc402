#pragma once
#include <vector>
using namespace std;

template <typename T>
class MyQueue {

protected:
    vector<T> elements;

public:
    MyQueue() = default;
    void Enqueue(T item);
    T Dequeue();
    void DequeuePrint();
};