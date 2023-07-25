// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 24, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

/*Rectangle; encapsulates a rectangle on the screen that can be labelled
(this concrete class draws a rectangle with a label inside).*/

#ifndef NAMESPACE_RECTANGLE_H
#define NAMESPACE_RECTANGLE_H

#include "LblShape.h"

namespace sdds {
class Rectangle : public LblShape {
        int m_width{0};
        int m_height{0};
    public:
        Rectangle();
        
        Rectangle(const char* label, int width, int height);
        //no destructor

        virtual void draw(std::ostream& os)const;

        /*Reads comma-separated specs of the Rectangle from istream.
        This function overrides the getSpecs function of the base class as follows.
        First, it will call the getSpecs function of the base class, then it will read two comma-separated values from istream for m_width and m_length and then ignores the rest of the characters up to and including the newline character ('\n').*/
        virtual void getSpecs(std::istream& is);
    };
}

#endif // !NAMESPACE_RECTANGLE_H