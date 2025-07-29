#pragma once
#include "patient.hpp"

void mainMenu();
void displayPatientData(Patient *&patientArray, int &size);
void addPatientData(Patient *&patientArray, int &size);
void deletePatientData(Patient *&patientArray, int &size);
void savePatientDataToAFile(Patient *&patientArray, int &size);
void loadPatientDataFromAFile(Patient *&patientArray, int &size);