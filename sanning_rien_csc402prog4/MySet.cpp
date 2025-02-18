#include "MySet.h"

MySet::MySet() {
    this->size = 0;
}

bool MySet::IsEmpty() const {
    return this->elts.size() == 0;
}

bool MySet::IsFound(int x) const {
    for (auto it = elts.begin(); it != elts.end(); ++it) {
        if(x == *it) {
            return true;
        }
    }
    return false;
}

bool MySet::AddElt(int x) {
    if (IsFound(x)) {
        return false;
    }
    // you can probably smell the python on me with this line
    this->size += 1;
    this->elts.push_back(x);
    return true;
}

bool MySet::DeleteElt(int x) {
    for (auto it = this->elts.begin(); it != this->elts.end(); ++it) {
        if (*it == x) {
            this->elts.erase(it);
            this->size -= 1;
            return true;
        }
    }
    return false;
}

vector<int> &MySet::GetElts() {
    return this->elts;
}

int MySet::GetSize() {
    return this->size;
}

MySet MySet::Union(MySet &S) {
    MySet UnionSet;
    // add in the internal set
    for (auto it = this->elts.begin(); it != this->elts.end(); ++it) {
        UnionSet.AddElt(*it);
    }
    // add in the target set, the AddElt should handle duplicates
    for (auto it = S.GetElts().begin(); it != S.GetElts().end(); ++it) {
        UnionSet.AddElt(*it);
    }
    return UnionSet;
}

MySet MySet::Intersection(MySet &S) {
    MySet IntersectionSet;
    for (auto it = this->elts.begin(); it != this->elts.end(); ++it) {
        // check if given item is contained in target array, then push if so
        if (S.IsFound(*it)) {
            IntersectionSet.AddElt(*it);
        }
    }
    return IntersectionSet;
}

MySet MySet::Difference(MySet &S) {
    MySet DifferenceSet;
    for (auto it = this->elts.begin(); it != this->elts.end(); ++it) {
        // check if given item is NOT contained in target array, then push if so
        if (!S.IsFound(*it)) {
            DifferenceSet.AddElt(*it);
        }
    }
    return DifferenceSet;
}




