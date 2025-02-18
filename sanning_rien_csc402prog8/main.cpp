#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
#include <ctime>
using namespace std;

int main() {
    // init
    int counter1 = 0;
    atomic<int> counter2(0);
    mutex mtx;
    vector<thread> V;
    int oddcount = 0;
    int evencount = 0;
    srand(time(0));

    // no sync
    for (int i = 0; i < 800; ++i) {
        int x = rand();
        if (x % 2 == 0) {
            ++evencount;
        } else {
            ++oddcount;
        }

        V.emplace_back([&counter1, x]() {
            if (x % 2 == 0) {
                ++counter1;
            } else {
                --counter1;
            }
        });
    }
    for (auto& thread : V) {
        thread.join();
    }
    int total = evencount - oddcount;
    cout << "PART A. NO Synchronization" << endl;
    cout << "# of increments is " << evencount << endl;
    cout << "# of decrements is " << oddcount << endl;
    cout << "Correct value should be " << total << endl;
    cout << "Value of counter is " << counter1 << endl << endl;


    // mutex
    V.clear();
    counter1 = 0;
    evencount = 0;
    oddcount = 0;

    for (int i = 0; i < 200; ++i) {
        int x = rand();
        if (x % 2 == 0) {
            ++evencount;
        } else {
            ++oddcount;
        }

        V.emplace_back([&counter1, &mtx, x]() {
            mtx.lock();
            if (x % 2 == 0) {
                ++counter1;
            } else {
                --counter1;
            }
            mtx.unlock();
        });
    }
    for (auto& t : V) {
        t.join();
    }
    total = evencount - oddcount;
    cout << "PART B. Mutex" << endl;
    cout << "# of increments is " << evencount << endl;
    cout << "# of decrements is " << oddcount << endl;
    cout << "Correct value should be " << total << endl;
    cout << "Value of counter is " << counter1 << endl << endl;

    // atomics
    V.clear();
    evencount = 0;
    oddcount = 0;

    for (int i = 0; i < 200; ++i) {
        int x = rand();
        if (x % 2 == 0) {
            ++evencount;
        } else {
            ++oddcount;
        }

        V.emplace_back([&counter2, x]() {
            // incrementing atomics
            if (x % 2 == 0) {
                ++counter2;
            } else {
                --counter2;
            }
        });
    }
    for (auto& t : V) {
        t.join();
    }
    total = evencount - oddcount;
    cout << "PART C. atomic<int>" << endl;;
    cout << "# of increments is " << evencount << endl;
    cout << "# of decrements is " << oddcount << endl;
    cout << "Correct value should be " << total << endl;
    cout << "Value of counter is " << counter2.load() << endl;

    // fin - really should have gotten this in earlier but a cold got to me
    return 0;
}