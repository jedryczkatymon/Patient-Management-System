#include <iostream>
#include <fstream>
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

void addPatient(Patient *&patientArray, int &size)
{
    int numOfPatientsEntr;
    cout << "How many patients do you want do enter? ";
    cin >> numOfPatientsEntr;
    Patient *patientArrayTemp = new Patient[size + numOfPatientsEntr];

    for (int i = 0; i < size; ++i)
    {
        patientArrayTemp[i] = patientArray[i];
    }

    for (int i = size; i < size + numOfPatientsEntr; ++i)
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
    delete[] patientArray;
    patientArray = patientArrayTemp;
    size += numOfPatientsEntr;
    savePatient(patientArray, size);
}

void deletePatient(Patient *&patientArray, int &size)
{
    int index;
    cout << "Enter the index of the patient you want to delete: ";
    cin >> index;

    if (index < 0 || index >= size)
    {
        cout << "Invalid index.\n";
        return;
    }

    for (int i = index; i < size - 1; ++i)
    {
        patientArray[i] = patientArray[i + 1];
    }

    Patient *patientArrayTemp = new Patient[size - 1];
    for (int i = 0; i < size - 1; ++i)
    {
        patientArrayTemp[i] = patientArray[i];
    }
    delete[] patientArray;
    patientArray = patientArrayTemp;
    --size;
    cout << "The patient data was deleted successfully!\n";
    savePatient(patientArray, size);
}

void savePatient(Patient *&patientArray, int &size)
{
    if (patientArray == NULL || size == 0)
    {
        cout << "No data to save.\n";
        return;
    }

    fstream file("patientDataBase.csv", ios::app | ios::in);
    if (!file)
    {
        cout << "Can't find the save file.\n";
        return;
    }

    for (int i = 0; i < size; i++)
    {
        file << patientArray[i].name << ','
        << patientArray[i].middleName << ','
        << patientArray[i].surname << ','
        << patientArray[i].motherMaidenName << ','
        << patientArray[i].phoneNumber << ','
        << patientArray[i].dayOfBirth << ','
        << patientArray[i].monthOfBirth << ','
        << patientArray[i].yearOfBirth << ','
        << patientArray[i].cityOfBirth << ','
        << patientArray[i].socialSecurityNumber << ','
        << patientArray[i].insuranceNumber << ',';
        for (int j = 0; j < 20; j++)
        {
            file << patientArray[i].medicalRecord[j] << ',';
        }
        for (int j = 0; j < 20; j++)
        {
            file << patientArray[i].currentMedications[j] << ',';
        }
        for (int j = 0; j < 20; j++)
        {
            file << patientArray[i].allergies[j] << ',';
        }
        file << '\n';
    }

    cout << "The patient data was saved successfully!\n";
}

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