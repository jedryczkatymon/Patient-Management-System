#include <iostream>
#include <fstream>
#include <string>
#include "includes/patient.hpp"
#include "includes/patientRecords.hpp"
#include "includes/utils.hpp"
using namespace std;

int main()
{
    clearTerminal();
    Patient *patientArray = NULL;
    int size = 0;
    loadPatientDataFromAFile(patientArray, size);
    int choice;
    do
    {
        cout << "\nPatient Management System:\n";
        cout << "1. Display patients\n";
        cout << "2. Add patient\n";
        cout << "3. Delete patient\n";
        cout << "4. Exit\n";
        cout << "\nWhat do you want to do? (pick a number corresponding to a function): ";
        cin >> choice;
        clearTerminal();
        switch (choice)
        {
        case 1:
            displayPatientData(patientArray, size);
            break;
        case 2:
            addPatientData(patientArray, size);
            break;
        case 3:
            deletePatientData(patientArray, size);
            break;
        case 4:
            cout << "Exiting program...\n";
            exit(0);
        default:
            cout << "\nInvalid code ❌\n";
        }
    } while (choice != 8);
}