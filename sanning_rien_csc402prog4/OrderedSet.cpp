#include "OrderedSet.h"
#include <algorithm>
using namespace std;

OrderedSet::OrderedSet(MySet S) {
    // add all elements
    for (int i = 0; i < S.GetSize(); ++i) {
        AddElt(S.GetElts().at(i));
    }
    // call sort on self
    SortSet();
}

void OrderedSet::SortSet() {
    sort(GetElts().begin(), GetElts().end());
}