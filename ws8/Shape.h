// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 24, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

/*Shape; encapsulates a shape that can be drawn on the screen
(An interface, that is an abstract base class with only pure virtual functions)*/

#ifndef NAMESPACE_SHAPE_H
#define NAMESPACE_SHAPE_H

#include<iostream>

namespace sdds {
    class Shape {
    public:
        //Returns void and receives a reference to ostream as an argument. This pure virtual function can not modify the current object.
        virtual void draw(std::ostream& os)const =0;

        //Returns void and receives a reference to istream as an argument.
        virtual void getSpecs(std::istream& is) =0;

        virtual ~Shape() {};
    };

    //Overload the insertion and extraction operators (using draw and getSpecs functions) so any shape object can be written or read using ostream and istream.
    std::ostream& operator<<(std::ostream& os, const Shape& shape);

    std::istream& operator>>(std::istream& is, Shape& shape);
}

#endif // !NAMESPACE_SHAPE_H