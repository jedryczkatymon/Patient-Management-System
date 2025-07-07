#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <algorithm>
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

        cout << "Enter surname: ";
        cin >> patientArrayTemp[i].surname;

        cout << "Enter mother's maiden name: ";
        cin >> patientArrayTemp[i].motherMaidenName;

        cout << "Enter sex: ";
        cin >> patientArrayTemp[i].sex;

        cout << "Enter phone number: ";
        cin >> patientArrayTemp[i].phoneNumber;

        cout << "Enter day of birth: ";
        cin >> patientArrayTemp[i].dayOfBirth;

        cout << "Enter month of birth: ";
        cin >> patientArrayTemp[i].monthOfBirth;

        cout << "Enter year of birth: ";
        cin >> patientArrayTemp[i].yearOfBirth;

        cout << "Enter city of birth: ";
        cin >> patientArrayTemp[i].cityOfBirth;

        cout << "Enter social security number: ";
        cin >> patientArrayTemp[i].socialSecurityNumber;

        cout << "Enter insurance number: ";
        cin >> patientArrayTemp[i].insuranceNumber;

        int numOfMedRecEntr = 0;
        cout << "How many medical record entries do you want to enter?: ";
        cin >> numOfMedRecEntr;
        for (int j = 0; j < numOfMedRecEntr; j++)
        {
            cout << "Enter medical record entry [" << j + 1 << "]: ";
            cin >> patientArrayTemp[i].medicalRecord[j];
        }

        int numOfMedsEntr = 0;
        cout << "How many medication does the patient take?: ";
        cin >> numOfMedsEntr;
        for (int j = 0; j < numOfMedsEntr; j++)
        {
            cout << "Enter current medication [" << j + 1 << "]: ";
            cin >> patientArrayTemp[i].currentMedications[j];
        }

        int numOfAllergyEntr = 0;
        cout << "How many allergies does the patient have?: ";
        cin >> numOfAllergyEntr;
        for (int j = 0; j < numOfAllergyEntr; j++)
        {
            cout << "Enter allergy [" << j + 1 << "]: ";
            cin >> patientArrayTemp[i].allergies[j];
        }
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
    if (patientArray == nullptr || size == 0)
    {
        cout << "\nNo data to save ❌\n";
        return;
    }

    string filePath = __FILE__;
    filePath.replace(filePath.find("patientRecords.cpp"), sizeof("patientRecords.cpp"), "config.txt");
    fstream config(filePath, ios::in);
    if (!config)
    {
        cout << "\nCan't find the config.txt ❌\n";
        return;
    }
    string csvPath;
    getline(config, csvPath);
    if (csvPath.empty())
    {
        cout << "\nconfig.txt is empty ❌\n";
        config.close();
        return;
    }
    config.close();

    fstream file(csvPath, ios::out | ios::trunc);
    if (!file)
    {
        cout << "\nCan't open the patientDataBase.csv file ❌\n";
        return;
    }

    for (int i = 0; i < size; i++)
    {
        file << patientArray[i].name << ','
             << patientArray[i].middleName << ','
             << patientArray[i].surname << ','
             << patientArray[i].motherMaidenName << ','
             << patientArray[i].sex << ','
             << patientArray[i].phoneNumber << ','
             << patientArray[i].dayOfBirth << ','
             << patientArray[i].monthOfBirth << ','
             << patientArray[i].yearOfBirth << ','
             << patientArray[i].cityOfBirth << ','
             << patientArray[i].socialSecurityNumber << ','
             << patientArray[i].insuranceNumber;

        for (int j = 0; j < 20; j++)
        {
            if (!patientArray[i].medicalRecord[j].empty())
                file << ",m_" << patientArray[i].medicalRecord[j];
        }
        for (int j = 0; j < 20; j++)
        {
            if (!patientArray[i].currentMedications[j].empty())
                file << ",c_" << patientArray[i].currentMedications[j];
        }
        for (int j = 0; j < 20; j++)
        {
            if (!patientArray[i].allergies[j].empty())
                file << ",a_" << patientArray[i].allergies[j];
        }
        file << '\n';
    }
    file.close();
    cout << "\nThe patient data was saved successfully ✅\n";
}
void loadPatientDataFromAFile(Patient *&patientArray, int &size)
{
    string filePath = __FILE__;
    filePath.replace(filePath.find("patientRecords.cpp"), sizeof("patientRecords.cpp"), "config.txt");
    fstream config(filePath, ios::in);
    if (!config)
    {
        cout << "\nCan't find the config.txt ❌\n";
        return;
    }
    string csvPath;
    getline(config, csvPath);
    if (csvPath.empty())
    {
        cout << "\nconfig.txt is empty ❌\n";
        config.close();
        return;
    }
    config.close();

    fstream file(csvPath, ios::in);
    if (!file)
    {
        cout << "\nCan't find the patientDataBase.csv file ❌\n";
        return;
    }
    cout << "\nLoading patient data from the file...\n";
    string line;
    size = 0;
    while (getline(file, line))
    {
        if (line.empty())
            continue;
        stringstream ss(line);
        string field;
        Patient patient;
        int fieldIdx = 0;
        int medRecIdx = 0, medIdx = 0, allergyIdx = 0;
        while (getline(ss, field, ','))
        {
            if (field.empty())
                continue;
            if (field.rfind("m_", 0) == 0 && medRecIdx < 20)
            {
                patient.medicalRecord[medRecIdx++] = field.substr(2) + ", ";
            }
            else if (field.rfind("c_", 0) == 0 && medIdx < 20)
            {
                patient.currentMedications[medIdx++] = field.substr(2) + ", ";
            }
            else if (field.rfind("a_", 0) == 0 && allergyIdx < 20)
            {
                patient.allergies[allergyIdx++] = field.substr(2) + ", ";
            }
            else
            {
                switch (fieldIdx)
                {
                case 0:
                    patient.name = field;
                    break;
                case 1:
                    patient.middleName = field;
                    break;
                case 2:
                    patient.surname = field;
                    break;
                case 3:
                    patient.motherMaidenName = field;
                    break;
                case 4:
                    patient.sex = field;
                    break;
                case 5:
                    patient.phoneNumber = field;
                    break;
                case 6:
                    try
                    {
                        patient.dayOfBirth = !field.empty() ? stoi(field) : 0;
                    }
                    catch (const std::invalid_argument &)
                    {
                        patient.dayOfBirth = 0;
                    }
                    break;
                case 7:
                    try
                    {
                        patient.monthOfBirth = !field.empty() ? stoi(field) : 0;
                    }
                    catch (const std::invalid_argument &)
                    {
                        patient.monthOfBirth = 0;
                    }
                    break;
                case 8:
                    try
                    {
                        patient.yearOfBirth = !field.empty() ? stoi(field) : 0;
                    }
                    catch (const std::invalid_argument &)
                    {
                        patient.yearOfBirth = 0;
                    }
                    break;
                case 9:
                    patient.cityOfBirth = field;
                    break;
                case 10:
                    patient.socialSecurityNumber = field;
                    break;
                case 11:
                    patient.insuranceNumber = field;
                    break;
                default:
                    break;
                }
                fieldIdx++;
            }
        }

        Patient *patientArrayTemp = new Patient[size + 1];
        for (int i = 0; i < size; ++i)
            patientArrayTemp[i] = patientArray[i];
        patientArrayTemp[size] = patient;
        delete[] patientArray;
        patientArray = patientArrayTemp;
        size++;
    }
    file.close();
    cout << "\nThe patient data was loaded successfully ✅\n";
}
