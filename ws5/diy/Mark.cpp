// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: Jun 15, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Mark.h"
namespace sdds {
    //empty argument constructor
    Mark::Mark() {
        m_mark = 0;
    }

    //create instance with m_mark set as num if num is within range
    Mark::Mark(int num) {
        if(num >= 0 && num <= 100) {
            m_mark = num;
        } else {
            //if num is out of range, set to invalid state
            m_mark = -1;
        }
    }

    //checks if m_mark is within range (valid)
    Mark::operator bool()const {
        return m_mark >= 0 && m_mark <=100;
    }

    //if m_mark is within range (valid), return value of m_mark otherwise, return 0;
    Mark::operator int()const {
        //calls bool overloaded operator onto current instance
        return (*this) ? m_mark : 0;
    }

    //if m_mark is valid, adds num to m_mark, returns instance
    int Mark::operator +=(int num) {
        if (*this) {
                m_mark += num;
            }
        return *this;
    }

    //copies value of num into m_mark
    Mark& Mark::operator =(int num) {
        m_mark = num;
        return *this;
    }

    Mark::operator double()const {
        //returns 0.0 if m_mark is invalid
        double dbl = 0.0;
        //assigns dbl based on value of m_mark
        if (*this) {
            if (m_mark < 50) {
                dbl = 0.0;
            } else if (m_mark < 60) {
                dbl = 1.0;
            } else if (m_mark < 70) {
                dbl = 2.0;
            } else if (m_mark < 80) {
                dbl = 3.0;
            } else {
                dbl = 4.0;
            } 
        }
        return dbl;
    }

    Mark::operator char()const {
        //returns 'X' if m_mark is invalid
        char grade = 'X';
        //returns grade based on value of m_mark
        if (*this) {
            if (m_mark < 50) {
                grade = 'F';
            } else if (m_mark < 60) {
                grade = 'D';
            } else if (m_mark < 70) {
                grade ='C';
            } else if (m_mark < 80) {
                grade = 'B';
            } else {
                grade = 'A';
            } 
        } 
        return grade;
    }

    //Helper Function
    int operator+=(int& num, const Mark& mark){
        //if object instance is valid, adds mark.m_mark to int
        if (mark) {
            //m_value of mark is returned by casting it into an int. The returned int is added to 'num' argument
            num += (int)mark;   
        }
        return num;
    }

}
