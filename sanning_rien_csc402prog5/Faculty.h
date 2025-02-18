#pragma once
#include "Person.h"
#include <string>

class Faculty : virtual public Person {
    protected:
        string department;
        string office;
        string officePhone;
        string email;

    public:
        Faculty() {
            department = "NONE";
            office = "NONE";
            officePhone = "NONE";
            email = "NONE";
        };

        Faculty(
            string firstname, string lastname, string streetaddress,
            string city, string state, string zipcode,
            string phone, int age, string department,
            string office, string officePhone, string email
            ) : Person(
                firstname, lastname, streetaddress,
                city, state, zipcode,
                phone, age
            ) {
                    this->department = department;
                    this->office = office;
                    this->officePhone = officePhone;
                    this->email = email;
        };

        Faculty(string department, string office, string officePhone, string email) {
            this->department = department;
            this->office = office;
            this->officePhone = officePhone;
            this->email = email;
        }

        void PrintPersonalInfo() const override;

        void PrintFacultyInfo() const;
};