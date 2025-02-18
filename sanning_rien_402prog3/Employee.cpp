#include "Employee.h"

Employee::Employee() {
    setFirstName("");
    setLastName("");
    setSocSecNum("");
    setDeptNum("");
    setWage(0.0);
}

Employee::Employee(
    const string& firstName,
    const string& lastName,
    const string& socsecnum,
    const string& deptNum,
    double wage) {
        setFirstName(firstName);
        setLastName(lastName);
        setSocSecNum(socsecnum);
        setDeptNum(deptNum);
        setWage(wage);
}

void Employee::setFirstName(const string& firstName) {
    this->firstName = firstName;
}

void Employee::setLastName(const string& lastName) {
    this->lastName = lastName;
}

void Employee::setSocSecNum(const string& socsecnum) {
    this->socsecnum = socsecnum;
}

void Employee::setDeptNum(const string& deptNum) {
    this->deptNum = deptNum;
}

void Employee::setWage(double wage) {
    this->wage = wage;
}

// Getters (const)
string Employee::getFirstName() const {
    return firstName;
}

string Employee::getLastName() const {
    return lastName;
}

string Employee::getSocSecNum() const {
    return socsecnum;
}

string Employee::getDeptNum() const {
    return deptNum;
}

double Employee::getWage() const {
    return wage;
}