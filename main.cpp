#include <iostream>
#include <fstream>
#include <string>
#include "includes/patient.hpp"
#include "includes/patientRecords.hpp"
using namespace std;

int main()
{
    Patient *patientArray = NULL;
    int size = 0;
    int choice;
    do
    {
        cout << "\nPatient Management System:\n";
        cout << "1. Add patient\n";
        cout << "2. Delete patient\n";
        cout << "What do you want to do? (pick a number corresponding to a function): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addPatient(patientArray, size);
            break;
        case 2:
            deletePatient(patientArray, size);
            break;
        default:
            cout << "Invalid code\n";
        }
    } while (choice != 8);
}