#include "TeachingAsst.h"
#include <iostream>

void TeachingAsst::PrintPersonalInfo() const {
  cout << "T-E-A-C-H-I-N-G-A-S-S-I-S-T-A-N-T" << endl;
  cout << "-----------------------------------" << endl;
  Person::PrintPersonalInfo();
  Student::PrintStudentInfo();
  Faculty::PrintFacultyInfo();
  cout << "TEACHING ASSISTANT INFO" << endl;
  cout << "Course Load: " << courseLoad << endl;
}