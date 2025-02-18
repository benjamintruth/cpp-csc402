#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include "TeachingAsst.h"
using namespace std;

void printAll(const vector<Person*>& people) {
    for (auto it = people.begin(); it != people.end(); ++it) {
        // was slamming my head over this one a bit...
        // needed to wrap in parens so that the iterator is dereferenced before calling the print method
        // I also see that this was in the psuedocode you provided that I ignored because I thought I understood the assignment
        // my foolhardiness costs me yet again
        (*it)->PrintPersonalInfo();
        cout << endl << endl;
    }
}

int main() {
    // init
    vector<Person*> people;
    string filename;
    // get filename
    cout << "Enter the file path: ";
    cin >> filename;

    // attempt open
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // as mentioned above, my main doesn't follow the psuedocode but does fulfil the requirements of the assignment ( I think )
    // hopefully the way I did things is okay
    string type;
    while (inFile >> type) {
        if (type == "S") {
            // init
            string firstname, lastname, streetaddress, city, state, zipcode, major, minor, classRank, phone;
            int age, credits;
            float gpa;
            // read
            inFile >> firstname >> lastname >> streetaddress >> city >> state;
            inFile >> zipcode >> phone >> age >> classRank >> gpa >> major >> minor >> credits;
            // push
            people.push_back(new Student(firstname, lastname, streetaddress, city, state, zipcode, phone, age, classRank, gpa, major, minor, credits));
        }
        else if (type == "F") {
            // init
            string firstname, lastname, streetaddress, city, state, zipcode, phone, department, office, email, officePhone;
            int age;
            // read
            inFile >> firstname >> lastname >> streetaddress >> city >> state;
            inFile >> zipcode >> phone >> age >> department >> office >> email >> officePhone;
            // push
            people.push_back( new Faculty(firstname, lastname, streetaddress, city, state, zipcode, phone, age, department, office, officePhone, email));
        }
        else if (type == "T") {
            // init
            string firstname, lastname, streetaddress, city, state, zipcode, phone, major, minor, department, office, email, officePhone;
            int age, credits, courseLoad;
            float gpa;
            string classRank;
            // read
            inFile >> firstname >> lastname >> streetaddress >> city >> state;
            inFile >> zipcode >> phone >> age >> classRank >> gpa >> major >> minor >> credits;
            inFile >> department >> office >> email >> officePhone >> courseLoad;
            // push
            people.push_back(new TeachingAsst(firstname, lastname, streetaddress, city, state, zipcode, phone, age, classRank, gpa, major, minor, credits, department, office, officePhone, email, courseLoad));
        }
    }

    // kill file
    inFile.close();

    // print : )
    printAll(people);

    return 0;
}
