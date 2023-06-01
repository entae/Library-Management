// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: 
// I have done all the coding by myself 
// and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;
namespace sdds {
    void Food::display()const {
        if
            cout << "| ";
            cout.width(20);
            cout.fill('.');
            cout << left << m_itemName << " | ";
            
            cout.width(7);
            cout.precision(2);
            cout.setf(ios::fixed);
            cout.setf(ios::right);
            cout.fill(' ');
            cout << m_price << " | ";
            cout.unsetf(ios::right);
            
            cout << (m_taxed ? "Yes" : "No ") << " |" << endl;
        } else {
            cout << "| ";
            line(20,'x');
            cout << " | ";
            line(7,'x');
            cout << " | ";
            cout << "xxx |" << endl;
    }
}