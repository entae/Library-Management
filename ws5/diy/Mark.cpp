// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: Jun 13, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Mark.h"
namespace sdds {
    Mark::Mark() {
        m_mark = 0;
    }

    Mark::Mark(int num) {
        if(num >= 0 && num <= 100) {
            m_mark = num;
        } else {
            m_mark = 0;
        }
    }

    Mark::operator bool()const {
        return m_mark >= 0 && m_mark <=100;
    }

    Mark::operator int()const {
        return (*this) ? m_mark : 0;
    }

    int Mark::operator +=(int num) {
        if (*this) {
            m_mark += num;
        }
        return *this;
    }

    Mark& Mark::operator =(int num) {
        m_mark = num;
        return *this;
    }

    Mark::operator double()const {
        double dbl = 0.0;
        if (*this) {
            m_mark < 50 ? dbl = 0.0 :
            m_mark < 60 ? dbl = 1.0 :
            m_mark < 70 ? dbl = 2.0 :
            m_mark < 80 ? dbl = 3.0 : 
            dbl = 4.0;
        }
        return dbl;
    }

    Mark::operator char()const {
        char grade = 'X';
        if (*this) {
            m_mark < 50 ? grade = 'F' :
            m_mark < 60 ? grade = 'D':
            m_mark < 70 ? grade = 'C' :
            m_mark < 80 ? grade = 'B' : 
            grade = 'A';
        } 
        return grade;
    }

    //Helper Function
    int operator+=(int& num, const Mark& mark){
        if (mark.operator bool()) {
            num += (int)mark;
        }
        return num;
    }

}
