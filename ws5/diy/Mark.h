// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: Jun 13, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>
namespace sdds {
    class Mark {
        //must be between 0-100 inclusive
        //  0 <= mark <  50 = F; 0.0
        // 50 <= mark <  60 = D; 1.0
        // 60 <= mark <  70 = C; 2.0
        // 70 <= mark <  80 = B; 3.0
        // 80 <= mark <=100 = A; 4.0
        int m_mark;
    public:
        //value of mark is zero
        Mark();
        //set the value of the mark to num
        Mark(int num);
        //returns true if the value of mark is valid
        operator bool()const;
        //mark can be casted to an int type
        //result would be value of the mark
        //or zero if mark is invalid
        operator int()const;
        //An integer can be added to the value of the mark using += operator; 
        //if the mark is invalid, the action is omitted. 
        //Reference of the mark is returned after the operation.
        int operator +=(int num);
        //Mark can be set to an integer using the assignment operator. 
        //If the mark is in an invalid state, the invalid value can be corrected by the assignment. 
        //Reference of the mark is returned after the operation.
        Mark& operator =(int num);
        //Mark can be casted to a double, the result would be 
        //the GPA equivalent of the integer value.
        //Casting an invalid mark will result in a zero value.
        operator double()const;
        //Mark can be casted to a character (char type), 
        //the result would be the grade letter value of the mark. 
        //See the table of mark values above. 
        //Casting an invalid mark will result in an 'X' value.
        operator char()const;
    };
    //Mark can be added to an integer, 
    //returning the integer after the operation. 
    //Invalid marks will not add any value to the integer.
    int operator+=(int& num, const Mark& mark);
}

#endif //!SDDS_MARK_H