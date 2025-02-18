#pragma once
#include <string>
using namespace std;

class Employee {
    protected:
        string firstName;
        string lastName;
        string socsecnum;
        string deptNum;
        double wage;

    public:
        Employee();

        Employee(const string& firstName, const string& lastName, const string& socsecnum,
                 const string& deptNum, double wage);

        void setFirstName(const string& firstName);
        void setLastName(const string& lastName);
        void setSocSecNum(const string& socsecnum);
        void setDeptNum(const string& deptNum);
        void setWage(double wage);

        string getFirstName() const;
        string getLastName() const;
        string getSocSecNum() const;
        string getDeptNum() const;
        double getWage() const;

        // member function less than operator overload
        bool operator<(const Employee& other) const {
            if (deptNum < other.deptNum) {
                return true;
            }
            if (deptNum == other.deptNum) {
                if (lastName == other.lastName) {
                    return firstName < other.firstName;
                }
                return lastName < other.lastName;
            }
            // if this department number if larger than the target comparison employee
            return false;
        };


        // left shift operator overload in main.cpp
        friend ostream& operator<<(ostream& out, Employee& E);
};