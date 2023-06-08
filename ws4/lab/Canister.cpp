// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: Jun 8, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {

    void Canister::setToDefault() {
        m_contentName = nullptr;
        m_diameter =  10.0;     // in centimeters 
        m_height = 13.0;        // in centimeters
        m_contentVolume = 0.0;  // in CCs
        m_usable = true;
    }

    void Canister::setName(const char *Cstr) {
        if (Cstr && m_usable) {
            delete[] m_contentName; // Delete the current content name if it exists
            m_contentName = new char[strLen(Cstr) + 1];
            strCpy(m_contentName, Cstr);
        }
    }

    bool Canister::isEmpty()const {
        return (m_contentVolume < 0.00001);
    }

    //compares and checks m_contentNames; 
    //returns true if names are the same
    bool Canister::hasSameContent(const Canister& C)const {
        return m_contentName && C.m_contentName && 
        (strCmp(m_contentName, C.m_contentName) == 0);
    }
    
    Canister::Canister() {
        setToDefault();
    }

    Canister::Canister(const char* contentName) {
        setToDefault();
        setName(contentName);
    }

    Canister::Canister(double height, double diameter, const char* contentName) {
        setToDefault();
        // if argument values are within range, set the height and diameter to the argument
        if ( (height >=10 && height <= 40) && (diameter >= 10 && diameter <= 30) ) {
                m_height = height;
                m_diameter = diameter;
                m_contentVolume = 0.0;
                setName(contentName);
        } else {
            m_usable = false;
        }
    }

    Canister::~Canister() {
        delete m_contentName;
        m_contentName = nullptr;
    }
    
    Canister& Canister::setContent(const char* contentName) {
        if (contentName == nullptr) {
            m_usable = false;       //canister is unusable is the contentName is null
        } else if (isEmpty()) {
            setName(contentName);   //if canister is empty, it will set the name to contentName
        } else if (!strCmp(m_contentName, contentName)) {
            m_usable = false;       //canister is unusable if the names are not the same
        }
        return *this;
    }

    Canister& Canister::pour(double quantity) {
        if(m_usable && quantity && (quantity + volume()) <= capacity()) {
            m_contentVolume += quantity;
        } else {
            m_usable = false;
        }
        return *this;
    }

    Canister& Canister::pour(Canister& C) {
        if (C.isEmpty()) {
            clear();
            setName(C.m_contentName);
        }
        else {
            setContent(C.m_contentName);
        }
        if ( C.volume() > (capacity() - volume() )) {
            C.m_contentVolume -= (capacity() - volume() );
            m_contentVolume = capacity();
        } else {
            pour(C.m_contentVolume);
            C.m_contentVolume = 0.0;
        }
        return *this;
    }

    double Canister::volume()const {
        return m_contentVolume;
    }

    std::ostream& Canister::display()const {
        cout.precision(1);
        cout.setf(ios::fixed);
        cout.width(7);
        cout << capacity() << "cc (" << m_height << 'x' << m_diameter << ") Canister";
        if (!m_usable) {
            cout << " of Unusable content, discard!";
        } else if (m_contentName) {
            cout << " of ";
            cout.width(7);
            cout << m_contentVolume << "cc   " << m_contentName;
        }

        return cout;
    }

    double Canister::capacity()const {
        const double pi = 3.14159265;

        return pi * (m_height - 0.267) * (m_diameter/2) * (m_diameter/2);
    }

    void Canister::clear() {
        delete[] m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }

}