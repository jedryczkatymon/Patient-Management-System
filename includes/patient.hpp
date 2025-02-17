#pragma once
#include <string>
using namespace std;

struct Patient
{
    string name;
    string middleName;
    string surname;
    string motherMaidenName;
    string phoneNumber;
    int dayOfBirth;
    int monthOfBirth;
    int yearOfBirth;
    string cityOfBirth;
    string socialSecurityNumber;
    string insuranceNumber;
    string medicalRecord[20];
    string currentMedications[20];
    string allergies[20];
};