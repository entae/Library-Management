// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 28, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Lib.h"

using namespace std;
namespace sdds{
     std::ostream& operator<<(std::ostream& ostr, const Streamable& stream) {
        if (stream) {
            stream.write(ostr);
        }
        return ostr;
    }

     std::istream& operator>>(std::istream& istr, Streamable& stream) {
        return stream.read(istr);
    }
}