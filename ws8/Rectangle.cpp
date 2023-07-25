// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 24, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <cstring>
#include "Rectangle.h"

using namespace std;
namespace sdds {

    Rectangle::Rectangle() : LblShape() {}

    Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label), m_width(width), m_height(height) {

        if (m_height < 3 || m_width < (strlen(LblShape::label()) +2)) {
            m_width = 0;
            m_height = 0;
        }
    }

    void Rectangle::getSpecs(istream& is) {
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore();
        is >> m_height;
        is.ignore(10000,'\n');
    }

    void Rectangle::draw(ostream& os)const {
        if (m_width > 0 && m_height > 0) {
            //first line
            os << '+';
            for (int i = 0; i < m_width - 2; i++) {
                os << '-';
            }
            os << '+' << endl;

            //second line
            os << '|';
            os.width(m_width - 2);
            os.setf(ios::left);
            os << LblShape::label() << '|';
            os.unsetf(ios::left);
            os << endl;

            //remaining lines
            for (int i = 0; i < m_height - 3; i++) {
                os << '|';
                os.width(m_width - 2);
                os << ' ' << '|' << endl;
            }

            //last line
            os << '+';
            for (int i = 0; i < m_width -2; ++i) {
                os << '-';
            }
            os << '+';
        }
    }

}