#include <iostream>
#include <fstream>
#include <sstream>
#include "../includes/patientRecords.hpp"
#include "../includes/patient.hpp"
using namespace std;

void displayPatientData(Patient *&patientArray, int &size)
{
    if (size == 0)
    {
        cout << "\nNo data to display ❌\n";
        return;
    }
    for (int i = 0; i < size; i++)
    {
        cout << "\nName: " << patientArray[i].name << "\n"
             << "Middle name: " << patientArray[i].middleName << "\n"
             << "Surname: " << patientArray[i].surname << "\n"
             << "Sex: " << patientArray[i].sex << "\n"
             << "Mother maiden name: " << patientArray[i].motherMaidenName << "\n"
             << "Phone number: " << patientArray[i].phoneNumber << "\n"
             << "Date of birth: "
             << patientArray[i].dayOfBirth << "/"
             << patientArray[i].monthOfBirth << "/"
             << patientArray[i].yearOfBirth << "\n"
             << "City of birth: " << patientArray[i].cityOfBirth << "\n"
             << "Social security number: " << patientArray[i].socialSecurityNumber << "\n"
             << "Insurance number: " << patientArray[i].insuranceNumber << "\n"
             << "Medical record: ";
        for (int j = 0; j < 20; j++)
        {
            cout << patientArray[i].medicalRecord[j] << " ";
        }
        cout << "\nCurrent medications: ";
        for (int j = 0; j < 20; j++)
        {
            cout << patientArray[i].currentMedications[j] << " ";
        }
        cout << "\nAllergies: ";
        for (int j = 0; j < 20; j++)
        {
            cout << patientArray[i].allergies[j] << " ";
        }
        cout << "\n----------------------------------------\n";
    }
}
void addPatientData(Patient *&patientArray, int &size)
{
    Patient *patientArrayTemp = new Patient[size + 1];

    for (int i = 0; i < size; ++i)
    {
        patientArrayTemp[i] = patientArray[i];
    }

    for (int i = size; i < size + 1; ++i)
    {
        cout << "\nEnter first name: ";
        cin >> patientArrayTemp[i].name;

        cout << "Enter middle name: ";
        cin >> patientArrayTemp[i].middleName;

        // cout << "Enter surname: ";
        // cin >> patientArrayTemp[i].surname;

        // cout << "Enter mother's maiden name: ";
        // cin >> patientArrayTemp[i].motherMaidenName;

        // cout << "Enter phone number: ";
        // cin >> patientArrayTemp[i].phoneNumber;

        // cout << "Enter day of birth: ";
        // cin >> patientArrayTemp[i].dayOfBirth;

        // cout << "Enter month of birth: ";
        // cin >> patientArrayTemp[i].monthOfBirth;

        // cout << "Enter year of birth: ";
        // cin >> patientArrayTemp[i].yearOfBirth;

        // cout << "Enter city of birth: ";
        // cin >> patientArrayTemp[i].cityOfBirth;

        // cout << "Enter social security number: ";
        // cin >> patientArrayTemp[i].socialSecurityNumber;

        // cout << "Enter insurance number: ";
        // cin >> patientArrayTemp[i].insuranceNumber;

        // int numOfMedRecEntr = 0;
        // cout << "How many medical record entries do you want to enter?: ";
        // cin >> numOfMedRecEntr;
        // for (int j = 0; j < numOfMedRecEntr; j++)
        // {
        //     cout << "Enter medical record entry [" << j + 1 << "]: ";
        //     cin >> patientArrayTemp[i].medicalRecord[j];
        // }

        // int numOfMedsEntr = 0;
        // cout << "How many medication does the patient take?: ";
        // cin >> numOfMedsEntr;
        // for (int j = 0; j < numOfMedsEntr; j++)
        // {
        //     cout << "Enter current medication [" << j + 1 << "]: ";
        //     cin >> patientArrayTemp[i].currentMedications[j];
        // }

        // int numOfAllergyEntr = 0;
        // cout << "How many allergies does the patient have?: ";
        // cin >> numOfAllergyEntr;
        // for (int j = 0; j < numOfAllergyEntr; j++)
        // {
        //     cout << "Enter allergy [" << j + 1 << "]: ";
        //     cin >> patientArrayTemp[i].allergies[j];
        // }
    }
    delete[] patientArray;
    patientArray = patientArrayTemp;
    size += 1;
    savePatientDataToAFile(patientArray, size);
}
void deletePatientData(Patient *&patientArray, int &size)
{
    int index;
    cout << "Enter the index of the patient you want to delete: ";
    cin >> index;

    if (index < 0 || index >= size)
    {
        cout << "\nInvalid index ❌\n";
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
    cout << "\nThe patient data was deleted successfully ✅\n";
    savePatientDataToAFile(patientArray, size);
}
void savePatientDataToAFile(Patient *&patientArray, int &size)
{
    /*
    - the program goes through every patient in the patientArray and
      for each saves their data to a file
    */
    if (patientArray == NULL || size == 0)
    {
        cout << "\nNo data to save ❌\n";
        return;
    }

    fstream file("patientDataBase.csv", ios::out);
    if (!file)
    {
        cout << "\nCan't find the save file ❌\n";
        return;
    }

    for (int i = 0; i < size; i++)
    {
        file << size << ','
             << patientArray[i].name << ','
             << patientArray[i].middleName << ','
             << patientArray[i].surname << ','
             << patientArray[i].motherMaidenName << ','
             << patientArray[i].phoneNumber << ','
             << patientArray[i].dayOfBirth << ','
             << patientArray[i].monthOfBirth << ','
             << patientArray[i].yearOfBirth << ','
             << patientArray[i].cityOfBirth << ','
             << patientArray[i].socialSecurityNumber << ','
             << patientArray[i].insuranceNumber << ','
             << "medical record,";
        for (int j = 0; j < 20; j++)
        {
            file << patientArray[i].medicalRecord[j] << ',';
        }
        file << "current medications,";
        for (int j = 0; j < 20; j++)
        {
            file << patientArray[i].currentMedications[j] << ',';
        }
        file << "allergies,";
        for (int j = 0; j < 20; j++)
        {
            file << patientArray[i].allergies[j] << ',';
        }
        file << "new patient\n";
    }
    file.close();
    cout << "\nThe patient data was saved successfully ✅\n";
}
void loadPatientDataFromAFile(Patient *&patientArray)
{
    /*
    the program goes through every patient saved in a file and loads their data into an array
    */
    fstream file("patientDataBase.csv", ios::out);
    if (!file)
    {
        cout << "\nCan't find the load file ❌\n";
        return;
    }
    string line;
    getline(file, line, ',');
    int size;
    stringstream(line) >> size;
    for (int i = 0; i < size; i++)
    {
        string line;
        getline(file, line, ',');
    }
    cout << "\nThe patient data was loaded successfully ✅\n";
}