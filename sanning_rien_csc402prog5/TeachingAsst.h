#pragma once
#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include <string>

class TeachingAsst : public Student, public Faculty {

protected:
    int courseLoad;

public:
    TeachingAsst() {
        courseLoad = 0;
    };

    TeachingAsst(
        // person
        string firstname, string lastname, string streetaddress,
        string city, string state, string zipcode,
        string phone, int age,
        // student
        string classRank, float gpa, string major,
        string minor, int credits,
        // faculty
        string department, string office, string officePhone,
        string email,
        // teaching assistant
        int courseLoad
    ) :
        Student::Person(
            firstname, lastname, streetaddress,
            city, state, zipcode,
            phone, age
        ),
        Student(
            classRank, gpa, major, minor,
            credits
        ),
        Faculty(
            firstname, lastname, streetaddress,
            city, state, zipcode,
            phone, age, department,
            office, officePhone, email
        )
    {
        this->courseLoad = courseLoad;
    }

    void PrintPersonalInfo() const;
};