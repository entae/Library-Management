/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version 
// Date	
// Author	
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: In Tae Chung,  Date: July 15, 2023     Reason
// 128 958 220 ; itchung@myseneca.ca
//The following code in the module Utils is code provided by my professor Fardad Soleimanloo
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>
namespace sdds {
    class Utils {
    public:
        void strCpy(char* des, const char* src);

        int strLen(const char* s);

        const char* strstr(const char* str, const char* find)const;

        void reAloCpy( char*& des, const char* src );

        void aloCpy( char*& des, const char* src );
    };
    extern Utils ut;

}
#endif // SDDS_UTILS_H__