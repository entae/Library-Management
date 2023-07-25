// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 24, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <cstring>

#include "LblShape.h"

using namespace std;
namespace sdds {
    const char* LblShape::label()const {
        return m_label;
    }

    //constructors
    LblShape::LblShape() : m_label(nullptr) {}

    LblShape::LblShape(const char* label) {
        m_label = new char[strlen(label) +1];
        strcpy(m_label, label);
    }

    //destructor
    LblShape::~LblShape() {
        delete[] m_label;
    }

    //overriding Shape's pure virtual function getSpecs
    void LblShape::getSpecs(istream& is) {
        char temp[1000];
        is.get(temp, 1000, ',');
        is.ignore();
        delete[] m_label;
        m_label = new char[strlen(temp) + 1];
        strcpy(m_label, temp);
    }

}