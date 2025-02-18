#include "Faculty.h"
#include <iostream>

void Faculty::PrintFacultyInfo() const {
    cout << "FACULTY INFO" << endl;
    cout << email << endl;
    cout << department << endl;
    cout << "Office: " << office << " Office Phone: " << officePhone << endl;
}
void Faculty::PrintPersonalInfo() const {
    cout << "F-A-C-U-L-T-Y" << endl << "--------------" << endl;
    Person::PrintPersonalInfo();
    PrintFacultyInfo();
}