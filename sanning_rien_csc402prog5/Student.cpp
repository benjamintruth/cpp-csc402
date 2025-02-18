#include "Student.h"
#include <iostream>

void Student::PrintPersonalInfo() const {
    cout << "S-T-U-D-E-N-T" << endl << "--------------" << endl;
    Person::PrintPersonalInfo();
    PrintStudentInfo();
}

void Student::PrintStudentInfo() const {
    cout << "STUDENT INFO" << endl;;
    cout << classRank << "   GPA: " << gpa << endl;
    cout << major << "    " << minor << endl;
    cout << "Total Credits: " << credits << endl;
}