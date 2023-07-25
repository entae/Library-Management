// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 24, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <cstring>
#include "Line.h"

using namespace std;
namespace sdds {

    Line::Line() : LblShape() {
        m_length = 0;
    } 

    Line::Line(const char* label, int length) : LblShape(label), m_length(length) {}

    void Line::getSpecs(istream& is) {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(10000, '\n');
    }

    void Line::draw(ostream& os)const {
        if (m_length > 0 && label()) {
            os << label() << endl;
            
            for (int i = 0; i < m_length; ++i) {
                os << '=';
            }
        }
    }
}