#include <iostream>
#include <thread>
#include <condition_variable>
#include <vector>
#include <future>
#include <chrono>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

mutex mtx;
condition_variable cv;
bool allReady = false;

void doStuff(promise<int> P, int loopIndex) {
    cout << "Thread #" << loopIndex + 1 << " is now active" << endl;

    // seed
    srand(time(0) + loopIndex);

    // lock & wait
    unique_lock<mutex> UL(mtx);
    cout << "Thread #" << loopIndex + 1 << " is waiting" << endl;
    while(!allReady) {
        cv.wait(UL);
    }

    // sleep
    int sleepTime = 100 + rand() % 901;
    cout << "Thread #" << loopIndex + 1 << " is preparing to sleep for " << sleepTime << " milliseconds" << endl;
    this_thread::sleep_for(chrono::milliseconds(sleepTime));

    // set value
    int resultValue = 1 + rand() % 100;
    cout << "Thread #" << loopIndex + 1 << " is returning the value " << resultValue << endl;
    P.set_value(resultValue);
}

void runSimulation() {
    unique_lock<mutex> lck(mtx);
    allReady = true;
    cv.notify_all();
};

int main()
{
    // don't go for egyptian cotton numbers
    // I tested this with some very high numbers for funsies on my dual core mac 2013 mac air
    // activity monitor consistently showed the os limits the number of threads to clio at around 100
    int N = 0;
    while (N <= 0) {
        cout << "Please enter an int count of threads to create: ";
        cin >> N;
    }

    vector<thread> V;

    // build threads and start
    for (int i = 0; i < N; i++) {
        promise<int> P;
        future<int> F = P.get_future();
        V.push_back(thread( doStuff, move(P), i ) );
    };
    cout << "READY TO RELEASE THE THREADS" << endl;
    runSimulation();

    // join up
    for (auto& t : V) {
        t.join();
    }
    // finn
    return 0;
}