// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July, 16 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#include <iostream>

#include "Truck.h"
#include "cstring.h"
using namespace std;

namespace sdds {
    Truck::Truck(const char* licensePlate, int year, double capacity, const char* address) : MotorVehicle(licensePlate, year), t_capacity(capacity), t_currentCargo(0.0) {
    }

    Truck::~Truck(){
        
    }

    bool Truck::addCargo(double cargo) {
        bool changed = false;
        if (cargo <= (t_capacity - t_currentCargo)) {
            t_currentCargo += cargo;
            changed = true;
        } 
        return changed;
    }

    bool Truck::unloadCargo() {
        bool changed = false;
        if (t_currentCargo > 0.0) {
            t_currentCargo = 0.0;
            changed = true;
        }
        return changed;
    }

    ostream& Truck::write(ostream& os)const {
        MotorVehicle::write(os);
        os << " | " << t_currentCargo << '/' << t_capacity;
        
        return os;
    }

    istream& Truck::read(istream& in) {
        MotorVehicle::read(in);
        cout << "Capacity: ";
        in >> t_capacity;
        cout << "Cargo: ";
        in >> t_currentCargo;

        return in;
    }

    ostream& operator<<(ostream& os, const Truck& truck) {
        return truck.write(os);
    }

    istream& operator>>(istream& in, Truck& truck) {
        return truck.read(in);
    }
}