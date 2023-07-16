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
// Name: In Tae Chung,  Date: July 14, 2023     Reason
// 128 958 220 ; itchung@myseneca.ca
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Utils.h"
namespace sdds {

    // Copies the source character string into the destination
    void strCpy(char* des, const char* src) {
        int i = 0;
        //
        while (src[i] != '\0') {
            des[i] = src[i];
            i++;
        }
        des[i] = '\0';
    }

    // returns the length of the C-string in characters
    int strLen(const char* s) {
        int len = 0;
        while (s[len] != '\0')
            len++;
        return len;
    }

}