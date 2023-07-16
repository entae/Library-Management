// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July, 16 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TRUCK_H_
#define SDDS_TRUCK_H_

#include "MotorVehicle.h"

namespace sdds {
    class Truck : public MotorVehicle {
        //attributes are in kg
        double t_capacity;
        double t_currentCargo;
    public:
        //constructor
        Truck(const char* licensePlate, int year, double capacity, const char* address);
        virtual ~Truck();
        bool addCargo(double cargo);
        bool unloadCargo();
        std::ostream& write(std::ostream& os)const;
        std::istream& read(std::istream& in);
    };
    std::ostream& operator<<(std::ostream& os, const Truck& truck);
    std::istream& operator>>(std::istream& in, Truck& truck);
}

#endif // !SDDS_TRUCK_H_