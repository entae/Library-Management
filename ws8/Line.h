// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 24, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

/*Line; encapsulates a horizontal line on a screen with the label
(this concrete class draws a labelled line)*/

#ifndef NAMESPACE_LINE_H
#define NAMESPACE_LINE_H

#include "LblShape.h"

namespace sdds {
    class Line : public LblShape {
        int m_length{0};

    public:
        Line();
        //Receives a Cstring and a value for the length of the line. Passes the Cstring to the constructor of the base class and sets the m_length member variable to the value of the second argument.
        Line(const char* label, int length);
        //no destructor implemented in this class

        //This function overrides the draw function of the base class.
        //If the m_length member variable is greater than zero and the label() is not null, this function will first print the label() and then go to the new line. Afterwards it keeps printing the '=' (assignment character) to the value of the m_length member variable.
        //Otherwise, it will take no action.
        virtual void draw(std::ostream& os)const;

        //Reads comma-separated specs of the Line from istream.
        //This function overrides the getSpecs function of the base class as follows.
        //First, it will call the getSpecs function of the base class then it will read the value of the m_length attribute from the istream argument, and then it will ignore The rest of the characters up to and including the newline character '\n'.
        virtual void getSpecs(std::istream& is);
    };
}

#endif // !NAMESPACE_LINE_H