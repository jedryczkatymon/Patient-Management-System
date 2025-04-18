cmake_minimum_required(VERSION 3.10.0)
project(PATIENT-MANAGEMENT-SYSTEM VERSION 0.1.0 LANGUAGES C CXX)

add_executable(PATIENT-MANAGEMENT-SYSTEM main.cpp src/patientRecords.cpp utils/utils.cpp)

include(CTest)
enable_testing()