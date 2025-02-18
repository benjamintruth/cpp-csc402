#pragma once
#include <vector>
using namespace std;

class MySet {
    protected:
        vector<int> elts;
        int size;
    public:
        MySet();
        bool IsEmpty() const;
        bool IsFound(int x) const;
        virtual bool AddElt(int x);
        bool DeleteElt(int x);
        vector<int> & GetElts();
        int GetSize();
        // I think these three and the AddElt are pointlessly virtual... but I didn't notice it before I removed my test code
        // too lazy to check at this point, sadly
        virtual MySet Union(MySet & S);
        virtual MySet Intersection(MySet & S);
        virtual MySet Difference(MySet & S);

        // overloads:

        // equivalence operator overload
        bool operator==(const MySet& S) const {
            for (auto it = elts.begin(); it != elts.end(); ++it) {
                if(!S.IsFound(*it)) {
                    // no match, no equivalence
                    return false;
                }
            }
            // otherwise they are all matching
            return true;
        }

        // friend for output
        friend ostream& operator<<(ostream& out, MySet& S);
};


