#pragma once
#include <string>
using namespace std;

class Person {
    protected:
        string firstname;
        string lastname;
        string streetaddress;
        string city;
        string state;
        string zipcode;
        string phone;
        int age;

    public:
        Person() {
            firstname = "FIRST";
            lastname = "LAST";
            streetaddress = "NONE";
            city = "NONE";
            state = "NONE";
            zipcode = "00000";
            phone = "000-000-0000";
            age = 0;
        };

        Person(string firstname, string lastname, string streetaddress, string city, string state, string zipcode, string phone, int age){
            this->firstname = firstname;
            this->lastname = lastname;
            this->streetaddress = streetaddress;
            this->city = city;
            this->state = state;
            this->zipcode = zipcode;
            this->phone = phone;
            this->age = age;
        };

        virtual void PrintPersonalInfo() const;
};