#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <set>
#include <forward_list>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

void partA() {
    string filename;
    priority_queue<double> pq;

    cout << "Please enter a path for the part A input file: " << endl;
    cin >> filename;
    ifstream infile(filename);
    if (!infile) {
        cout << "Error opening file!" << endl;
        return;
    }

    cout << "PART A. - HEAP SORT" << endl;

    double value;
    while (infile >> value) {
        pq.push(value);
    }

    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }

    infile.close();
}

void partB() {
    string filename;
    set<int> s;
    multiset<int> ms;

    cout << "Please enter a path for the part B input file: " << endl;
    cin >> filename;
    ifstream infile(filename);
    if (!infile) {
        cout << "Error opening file!" << endl;
        return;
    }

    cout << "PART B. Sets and Multisets " << endl;

    int value;
    while (infile >> value) {
        s.insert(value);
        ms.insert(value);
    }

    for (int i = 1; i <= 20; ++i) {
        cout << "Count of Set " << i << " is: " << s.count(i)
        << "  Count of Multiset " << i << " is: " << ms.count(i) << endl;
    }

    infile.close();
}

void partC() {
    string filename;
    forward_list<int> fl;

    cout << "Please enter a path for the part C input file: " << endl;
    cin >> filename;

    ifstream infile(filename);

    if (!infile) {
        cout << "Error opening file!" << endl;
        return;
    }

    cout << "PART C. Forward Lists" << endl;

    cout << "Initial Forward List Contents" << endl;
    int value;
    while (infile >> value) {
        fl.push_front(value);
    }

    for (auto it = fl.begin(); it != fl.end(); ++it) {
        cout << *it << endl;
    }

    fl.remove_if([](int x) { return x % 5 == 0; });

    cout << "After Removing multiples of 5" << endl;
    for (auto it = fl.begin(); it != fl.end(); ++it) {
        cout << *it << endl;
    }

    fl.remove(99);
    fl.sort();

    cout << "After Removing all instance of 99 and SORTING" << endl;
    for (auto it = fl.begin(); it != fl.end(); ++it) {
        cout << *it << endl;
    }

    infile.close();
}

void partD() {
    string filename;
    map<string, int> m;
    multimap<string, int> mm;

    cout << "Please enter a path for the part D input file: " << endl;
    cin >> filename;

    ifstream infile(filename);

    if (!infile) {
        cout << "Error opening file!" << endl;
        return;
    }

    cout << "PART D. Maps and Multimaps " << endl;

    string key;
    int value;
    while (infile >> key >> value) {
        auto p = make_pair(key, value);
        m.insert(p);
        mm.insert(p);
    }

    cout << "MAP Contents" << endl;
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << "  " << it->second << endl;
    }

    cout << "MULTIMAP Contents" << endl;
    for (auto it = mm.begin(); it != mm.end(); ++it) {
        cout << it->first << "  " << it->second << endl;
    }

    infile.close();
}

// just doing this in main to keep it simple
class myClass {
public:
    string ID;
    int DEPT;

    myClass() {
        ID = "";
        DEPT = 0;
    }

    myClass(string IDin, int DEPTin) {
        this->ID = IDin;
        this->DEPT = DEPTin;
    }

    bool operator<(const myClass& other) const {
        if (ID == other.ID) {
            return DEPT < other.DEPT;
        }
        return ID < other.ID;
    }

    bool operator==(const myClass& other) const {
        return ID == other.ID && DEPT == other.DEPT;
    }
};

void partE() {
    string filename;
    list<myClass> myList;

    cout << "Please enter a path for the part E input file: " << endl;
    cin >> filename;

    ifstream infile(filename);

    if (!infile) {
        cout << "Error opening file!" << endl;
        return;
    }

    cout << "PART E. LISTS of user-defined objects" << endl;

    string id;
    int dept;
    while (infile >> id >> dept) {
        myClass obj(id, dept);
        myList.push_back(obj);
    }

    myList.sort();

    cout << "SORTED List" << endl;
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        cout << it->ID << "  " << it->DEPT << endl;
    }

    myList.unique();

    cout << "List WITHOUT DUPLICATES" << endl;
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        cout << it->ID << "  " << it->DEPT << endl;
    }

    infile.close();
}

int main() {
    partA();
    partB();
    partC();
    partD();
    partE();
    // finn - thanks for an amazing class, Doc
    return 0;
}