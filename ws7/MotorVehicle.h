// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July, 16 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#ifndef SDDS_MOTORVEHICLE_H_
#define SDDS_MOTORVEHICLE_H_

namespace sdds {
    class MotorVehicle {
        char m_licensePlate[9];
        char m_address[64];
        int m_year;
    public:
        MotorVehicle(const char* licensePlate, int year);
        virtual ~MotorVehicle();
        virtual void moveTo(const char* address);
        std::ostream& write(std::ostream& os)const;
        std::istream& read(std::istream& in);
    };
    //Helper Functions for write & read
    std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle);
    std::istream& operator>>(std::istream& in, MotorVehicle& vehicle);
}

#endif // !SDDS_MOTORVEHICLE_H_