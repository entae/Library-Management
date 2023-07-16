// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July, 16 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "cstring.h"
#include "MotorVehicle.h"
using namespace std; 

namespace sdds {
    //constructor
    MotorVehicle::MotorVehicle(const char* licensePlate, int year) {
        strnCpy(m_licensePlate, licensePlate, 8);
        m_licensePlate[8] = '\0';
        strnCpy(m_address, "Factory", 63);
        m_address[63] = '\0';
        m_year = year;
    }

    MotorVehicle::~MotorVehicle() {

    }

    void MotorVehicle::moveTo(const char* address) {
        if (strCmp(m_address, address) != 0) {
            //license plate
            cout << "|" << right;
            cout.width(8);
            cout << m_licensePlate << "| |";
            
            //current address
            cout.width(20);
            cout << m_address << " ---> ";

            //new address
            cout << left;
            cout.width(20);
            cout << address << "|" << endl;
            strnCpy(m_address, address, 63);
            m_address[63] = '\0';
        }
    }

    ostream& MotorVehicle::write(ostream& os)const {
        return os << "| " << m_year << " | " << m_licensePlate << " | " << m_address;
    }

    istream& MotorVehicle::read(istream& in) {
        cout << "Built year: ";
        in >> m_year; 
        cout << "License plate: ";
        in >> m_licensePlate;
        cout << "Current location: ";
        in.ignore();
        in.getline(m_address, 64);

        return in;
    }
    //helper functions
    ostream& operator<<(ostream& os, const MotorVehicle& vehicle){
        return vehicle.write(os);
    }

    istream& operator>>(istream& in, MotorVehicle& vehicle) {
        return vehicle.read(in);
    }
}