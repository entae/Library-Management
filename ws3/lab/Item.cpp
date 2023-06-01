// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: Jun 1, 2023
// I have done all the coding by myself 
// and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "cstring.h"
#include "Item.h"
#define TAX_RATE 0.13
using namespace std;
namespace sdds {
    
    //This function sets the itemName member Cstring variable 
    //to the Cstring in the name argument up to 20 characters.
        void Item::setName(const char* name){
            strnCpy(m_itemName, name, 20);
            m_itemName[20] = '\0';
        }

    //Sets the Item to a recognizable safe Empty State. 
        void Item::setEmpty(){
            m_itemName[0] = '\0';
            m_price = 0.0;
            m_taxed = false;
        }
    //If price is less than 0 or name is null, 
    //then the Item is set to a recognizable invalid empty state (safe empty state).
        void Item::set(const char* name, double price, bool taxed){
            if (name != nullptr) {
                setName(name);
            } else {
                setName("");
            }
            if (price > 0) {
                m_price = price;
            } else {
                m_price = 0.0;
            }
            m_taxed = taxed;
        }
    //Prints an item in specified format.
    //line()
        void Item::display()const {
            if (isValid()) {
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
    //Returns true if the Item is not set to an empty state (As done in setEmpty function) .
        bool Item::isValid()const {
            return m_itemName[0] != '\0' && m_price >= 0;
        }
    //Returns the m_price attribute;
        double Item::price()const {
            return m_price;
        }
    //Returns the product of m_price * 0.13 (define a constant double value for this tax rate). 
    //Or it returns 0.0 if the m_taxed is false.
        double Item::tax()const {
            return (m_taxed) ? m_price * TAX_RATE : 0.0;
        }
    
}