#include <iostream>
#include <string>
using namespace std;

class Patient
{
public:
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

Patient addPatient(Patient *patientArray)
{
    int numOfPatientsEntr = 0;
    cout << "How many patients do you want do enter? ";
    cin >> numOfPatientsEntr;
    for (int i = 0; i < numOfPatientsEntr; i++)
    {
        cout << "Enter first name: ";
        cin >> patientArray[i].name;

        cout << "Enter middle name: ";
        cin >> patientArray[i].middleName;

        cout << "Enter surname: ";
        cin >> patientArray[i].surname;

        cout << "Enter mother's maiden name: ";
        cin >> patientArray[i].motherMaidenName;

        cout << "Enter phone number: ";
        cin >> patientArray[i].phoneNumber;

        cout << "Enter day of birth: ";
        cin >> patientArray[i].dayOfBirth;

        cout << "Enter month of birth: ";
        cin >> patientArray[i].monthOfBirth;

        cout << "Enter year of birth: ";
        cin >> patientArray[i].yearOfBirth;

        cout << "Enter city of birth: ";
        cin >> patientArray[i].cityOfBirth;

        cout << "Enter social security number: ";
        cin >> patientArray[i].socialSecurityNumber;

        cout << "Enter insurance number: ";
        cin >> patientArray[i].insuranceNumber;

        int numOfMedRecEntr = 0;
        cout << "How many medical record entries do you want to enter?: ";
        cin >> numOfMedRecEntr;
        for (int j = 0; j < numOfMedRecEntr; j++)
        {
            cout << "Enter medical record entry [" << j + 1 << "]: ";
            cin >> patientArray[i].medicalRecord[j];
        }

        int numOfMedsEntr = 0;
        cout << "How many medication does the patient take?: ";
        cin >> numOfMedsEntr;
        for (int j = 0; j < numOfMedsEntr; j++)
        {
            cout << "Enter current medication [" << j + 1 << "]: ";
            cin >> patientArray[i].currentMedications[j];
        }

        int numOfAllergyEntr = 0;
        cout << "How many allergies does the patient have?: ";
        cin >> numOfAllergyEntr;
        for (int j = 0; j < numOfAllergyEntr; j++)
        {
            cout << "Enter allergy [" << j + 1 << "]: ";
            cin >> patientArray[i].allergies[j];
        }

        cout << "The patient data was entered successfully!" << endl;
    }
    numOfPatientsEntr--;
    return *patientArray;
}

int main()
{
    Patient *patientArray = new Patient[50];
    int choice;
    do
    {
        cout << "\nPatient Management System:\n";
        cout << "1. Add patient\n";
        cout << "What do you want to do? (pick a number corresponding to a function): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addPatient(patientArray);
            break;
        default:
            cout << "Invalid code\n";
        }
    } while (choice != 8);
    
}