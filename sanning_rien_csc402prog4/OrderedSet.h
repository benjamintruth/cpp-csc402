#pragma once
#include "MySet.h"

class OrderedSet : public MySet{
    public:
        OrderedSet() = default;
        OrderedSet(MySet S);
        void SortSet();
    // overrides
    bool AddElt(int x) {
        bool AddedSuccessfully = MySet::AddElt(x);
        if(!AddedSuccessfully) {
            // add failed
            return false;
        }
        // sort and return green flag
        SortSet();
        return true;
    }

    OrderedSet Union(OrderedSet OS) {
        MySet UnionSet = MySet::Union(OS);
        OrderedSet temp = OrderedSet(UnionSet);
        return temp;
    }

    OrderedSet Intersection(OrderedSet OS) {
        MySet IntersectionSet = MySet::Intersection(OS);
        OrderedSet temp = OrderedSet(IntersectionSet);
        return temp;
    }

    OrderedSet Difference(OrderedSet OS) {
        MySet DifferenceSet = MySet::Difference(OS);
        OrderedSet temp = OrderedSet(DifferenceSet);
        return temp;
    }

    // operator overload
    friend ostream& operator<< (ostream& ost, OrderedSet& OS);
};


