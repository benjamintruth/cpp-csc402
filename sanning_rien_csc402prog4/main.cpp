#include "MySet.h"
#include "OrderedSet.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string filepath1, filepath2, filepath3, filepath4, osfilepath1, osfilepath2, osfilepath3, osfilepath4;
    MySet S1, S2, S3, S4, S5, S6;
    OrderedSet O1, O2, O3, O4, O5, O6;

    // receive first in file
    cout << "Please enter a path for file #1: ";
    cin >> filepath1;
    // load first file
    ifstream inputFile(filepath1);
    if (!inputFile) {
        cerr << "Error opening file: " << filepath1 << endl;
        exit(1);
    }
    // read
    int inputInt;
    while (inputFile >> inputInt) {
        S1.AddElt(inputInt);
    }
    inputFile.close();

    // receive second file
    cout << "Please enter a path for file #2: ";
    cin >> filepath2;
    // load second file
    ifstream inputFile2(filepath2);
    if (!inputFile2) {
        cerr << "Error opening file: " << filepath2 << endl;
        exit(1);
    }
    // read
    while (inputFile2 >> inputInt) {
        S2.AddElt(inputInt);
    }
    inputFile2.close();

    // print first three sets
    cout << "BEFORE OPERATIONS" << endl;
    cout << "MySet S1 Contents: " << endl;
    cout << "----------------" << endl;
    cout << S1;
    cout << "MySet S2 Contents: " << endl;
    cout << "----------------" << endl;
    cout << S2;
    cout << "MySet S3 Contents: " << endl;
    cout << "----------------" << endl;
    cout << S3;

    // print union set
    S3 = S1.Union(S2);
    cout << "After UNION Operation of S1 and S2" << endl;
    cout << "MySet S3 Contents: " << endl;
    cout << "----------------" << endl;
    cout << S3;
    cout << "MySet S1 Contents: " << endl;
    cout << "----------------" << endl;
    cout << S1;
    cout << "MySet S2 Contents: " << endl;
    cout << "----------------" << endl;
    cout << S2;

    // intersection
    S4 = S1.Intersection(S2);
    cout << "After INTERSECTION Operation of S1 and S2" << endl;
    cout << "MySet S4 Contents: " << endl;
    cout << "----------------" << endl;
    cout << S4;
    cout << "MySet S1 Contents: " << endl;
    cout << "----------------" << endl;
    cout << S1;
    cout << "MySet S2 Contents: " << endl;
    cout << "----------------" << endl;
    cout << S2;

    // difference
    S5 = S1.Difference(S2);
    cout << "After Difference Operation of S1 and S2" << endl;
    cout << "MySet S5 Contents: " << endl;
    cout << "----------------" << endl;
    cout << S5;
    cout << "MySet S1 Contents: " << endl;
    cout << "----------------" << endl;
    cout << S1;
    cout << "MySet S2 Contents: " << endl;
    cout << "----------------" << endl;
    cout << S2;

    // equivalence checking
    S6 = S1.Union(S3);
    cout << "S3 and S6 are ";
    if (S6 == S3) {
        cout << "EQUAL" << endl;
    } else {
        cout << "NOT EQUAL" << endl;
    }
    cout << "S1 and S6 are ";
    if (S6 == S1) {
        cout << "EQUAL" << endl;
    } else {
        cout << "NOT EQUAL" << endl;
    }

    // receive third file
    cout << "Please enter a path for file #3: ";
    cin >> filepath3;
    // load third file
    ifstream inputFile3(filepath3);
    if (!inputFile3) {
        cerr << "Error opening file: " << filepath3 << endl;
        exit(1);
    }
    // read
    while (inputFile3 >> inputInt) {
        bool addSucceeded = S1.AddElt(inputInt);
        if (addSucceeded) {
            cout << inputInt << " was successfully added to S1" << endl;
        }
        else {
            cout << inputInt << " ALREADY PRESENT IN S1" << endl;
        }
    }
    inputFile3.close();
    cout << "S1 AFTER ADDITION OF ELEMENTS" << endl;
    cout << "MySet S1 Contents: " << endl;
    cout << "----------------" << endl;
    cout << S1;

    // receive fourth file
    cout << "Please enter a path for file #4: ";
    cin >> filepath4;
    // load third file
    ifstream inputFile4(filepath4);
    if (!inputFile4) {
        cerr << "Error opening file: " << filepath4 << endl;
        exit(1);
    }
    // read
    while (inputFile4 >> inputInt) {
        bool DeleteSucceeded = S1.DeleteElt(inputInt);
        if (DeleteSucceeded) {
            cout << inputInt << " was successfully deleted from S1" << endl;
        }
        else {
            cout << inputInt << " NOT FOUND" << endl;
        }
    }
    inputFile4.close();
    cout << "S1 AFTER DELETION of elements" << endl;
    cout << "MySet S1 Contents: " << endl;
    cout << "----------------" << endl;
    cout << S1;


    // REPEAT FOR ORDERED SETS
    cout << endl << "OUTPUT FOR ORDERED SETS" << endl;

    // receive first in file
    cout << "Please enter a path for file #1: ";
    cin >> osfilepath1;
    // load first file
    ifstream osinputFile(osfilepath1);
    if (!osinputFile) {
        cerr << "Error opening file: " << osfilepath1 << endl;
        exit(1);
    }
    // read
    while (osinputFile >> inputInt) {
        O1.AddElt(inputInt);
    }
    osinputFile.close();

    // receive second file
    cout << "Please enter a path for file #2: ";
    cin >> osfilepath2;
    // load second file
    ifstream osinputFile2(osfilepath2);
    if (!osinputFile2) {
        cerr << "Error opening file: " << osfilepath2 << endl;
        exit(1);
    }
    // read
    while (osinputFile2 >> inputInt) {
        O2.AddElt(inputInt);
    }
    osinputFile2.close();

    // print first three sets
    cout << "BEFORE OPERATIONS:" << endl;
    cout << "OrderedSet OS1 Contents: " << endl;
    cout << "----------------" << endl;
    cout << O1;
    cout << "OrderedSet OS2 Contents: " << endl;
    cout << "----------------" << endl;
    cout << O2;
    cout << "OrderedSet OS3 Contents: " << endl;
    cout << "----------------" << endl;
    cout << O3;

    // print union set
    O3 = O1.Union(O2);
    cout << "After UNION Operation of OS1 and OS2" << endl;
    cout << "OrderedSet OS3 Contents: " << endl;
    cout << "----------------" << endl;
    cout << O3;
    cout << "OrderedSet OS1 Contents: " << endl;
    cout << "----------------" << endl;
    cout << O1;
    cout << "OrderedSet OS2 Contents: " << endl;
    cout << "----------------" << endl;
    cout << O2;

    // intersection
    O4 = O1.Intersection(O2);
    cout << "After INTERSECTION Operation of OS1 and OS2" << endl;
    cout << "OrderedSet OS4 Contents: " << endl;
    cout << "----------------" << endl;
    cout << O4;
    cout << "OrderedSet OS1 Contents: " << endl;
    cout << "----------------" << endl;
    cout << O1;
    cout << "OrderedSet OS2 Contents: " << endl;
    cout << "----------------" << endl;
    cout << O2;

    // difference
    O5 = O1.Difference(O2);
    cout << "After Difference Operation of OS1 and OS2" << endl;
    cout << "OrderedSet OS5 Contents: " << endl;
    cout << "----------------" << endl;
    cout << O5;
    cout << "OrderedSet OS1 Contents: " << endl;
    cout << "----------------" << endl;
    cout << O1;
    cout << "OrderedSet OS2 Contents: " << endl;
    cout << "----------------" << endl;
    cout << O2;

    // DEV: TODO: continue from here

    // equivalence checking
    O6 = O1.Union(O3);
    cout << "OS3 and OS6 are ";
    if (O6 == O3) {
        cout << "EQUAL" << endl;
    } else {
        cout << "NOT EQUAL" << endl;
    }
    cout << "OS1 and OS6 are ";
    if (O6 == O1) {
        cout << "EQUAL" << endl;
    } else {
        cout << "NOT EQUAL" << endl;
    }

    // receive third file
    cout << "Please enter a path for file #3: ";
    cin >> osfilepath3;
    // load third file
    ifstream osinputFile3(filepath3);
    if (!osinputFile3) {
        cerr << "Error opening file: " << osfilepath3 << endl;
        exit(1);
    }
    // read
    while (osinputFile3 >> inputInt) {
        bool addSucceeded = O1.AddElt(inputInt);
        if (addSucceeded) {
            cout << inputInt << " was successfully added to OS1" << endl;
        }
        else {
            cout << inputInt << " ALREADY PRESENT IN OS1" << endl;
        }
    }
    osinputFile3.close();
    cout << "AFTER ADDITION OF ELEMENTS" << endl;
    cout << "OrderedSet OS1 Contents: " << endl;
    cout << "----------------" << endl;
    cout << O1;

    // receive fourth file
    cout << "Please enter a path for file #4: ";
    cin >> osfilepath4;
    // load third file
    ifstream osinputFile4(osfilepath4);
    if (!osinputFile4) {
        cerr << "Error opening file: " << osfilepath4 << endl;
        exit(1);
    }
    // read
    while (osinputFile4 >> inputInt) {
        bool DeleteSucceeded = O1.DeleteElt(inputInt);
        if (DeleteSucceeded) {
            cout << inputInt << " was successfully deleted from OS1" << endl;
        }
        else {
            cout << inputInt << " NOT FOUND" << endl;
        }
    }
    osinputFile4.close();
    cout << "O1 AFTER DELETION of elements" << endl;
    cout << "OrderedSet OS1 Contents: " << endl;
    cout << "----------------" << endl;
    cout << O1;

    cout << "PROGRAM COMPLETE" << endl;
    return 0;
}

ostream& operator<<(ostream& out, MySet &S) {
    if (S.IsEmpty()) {
        out << "Set is EMPTY " << endl;
        return out;
    }
    out << " { ";
    for (auto it = S.GetElts().begin(); it != S.GetElts().end(); ++it) {
        if (next(it) != S.GetElts().end()) {
            out << *it << ", ";
        } else {
            out << *it << " ";
        }

    }
    out << "} " << endl;
    return out;
}

ostream& operator<<(ostream& out, OrderedSet &S) {
    if(S.IsEmpty()) {
        out << "Set is EMPTY " << endl;
        return out;
    }
    out << " { ";
    for (auto it = S.GetElts().begin(); it != S.GetElts().end(); ++it) {
        if (next(it) != S.GetElts().end()) {
            out << *it << ", ";
        } else {
            out << *it << " ";
        }
    }
    out << "} " << endl;
    return out;
}