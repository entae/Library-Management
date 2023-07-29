/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: In Tae Chung,  Date: July 15, 2023     Reason
// 128 958 220 ; itchung@myseneca.ca
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Utils.h"
namespace sdds {
    Utils ut;
    // Copies the source character string into the destination
    void Utils::strCpy(char* des, const char* src) {
        int i = 0;
        //
        while (src[i] != '\0') {
            des[i] = src[i];
            i++;
        }
        des[i] = '\0';
    }

    // returns the length of the C-string in characters
    int Utils::strLen(const char* s) {
        int len = 0;
        if (s != nullptr) { //condition added to avoid nullpointers
            while (s[len] != '\0')
                len++;
        }
        return len;
    }

    void Utils::reAloCpy( char*& des, const char* src ) {
        delete[] des;
        aloCpy( des, src );
    }

    void Utils::aloCpy( char*& des, const char* src ) {
        des = nullptr;
        if ( src ) {
            des = new char[ut.strLen( src ) + 1];
            ut.strCpy( des, src );
        }
    }

}