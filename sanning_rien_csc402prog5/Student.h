#pragma once
#include "Person.h"
#include <string>

class Student : virtual public Person {
    protected:
        string classRank;
        float gpa;
        string major;
        string minor;
        int credits;

    public:
        Student() {
            classRank = "None";
            gpa = 0.0;
            major = "NONE";
            minor = "NONE";
            credits = 0;
        };

        Student(
            string firstname, string lastname, string streetaddress,
            string city, string state, string zipcode,
            string phone, int age, string classRank,
            float gpa, string major, string minor,
            int credits ) : Person(
                firstname, lastname, streetaddress,
                city, state, zipcode,
                phone, age
        ) {
                this->classRank = classRank;
                this->gpa = gpa;
                this->major = major;
                this->minor = minor;
                this->credits = credits;
        };

        Student( string classRank, float gpa, string major,
            string minor, int credits ) {
                this->classRank = classRank;
                this->gpa = gpa;
                this->major = major;
                this->minor = minor;
                this->credits = credits;
        };

        void PrintPersonalInfo() const override;

        void PrintStudentInfo() const;
};