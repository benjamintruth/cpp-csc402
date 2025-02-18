#include "Person.h"
#include <iostream>
using namespace std;

void Person::PrintPersonalInfo() const {
    cout << "PERSONAL INFO" << endl
    << this->lastname << ", " << this->firstname << endl
    << streetaddress << endl
    << city << ", " << state << " " << zipcode << endl
    << phone << "  AGE: " << age << endl;
}