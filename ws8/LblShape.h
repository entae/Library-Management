// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 24, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

/*LblShape; encapsulates a shape that can be labelled
(An abstract base class that represents a labelled shape)*/

#ifndef NAMESPACE_LBLSHAPE_H
#define NAMESPACE_LBLSHAPE_H

#include "Shape.h"

namespace sdds {
    class LblShape : public Shape {
        char* m_label{nullptr};

    protected:
        //Add a query called label that returns the unmodifiable value of m_label member variable.
        const char* label()const;

    public:
        LblShape();
        //Allocates memory large enough to hold the incoming Cstring argument pointed by the m_label member variable. Then copies the Cstring argument to the newly allocated memory.
        LblShape(const char* label);
        //destructor; Deletes the memory pointed by m_label member variable.
        virtual ~LblShape();
        //deleted actions
        LblShape(const LblShape& source) = delete;
        LblShape& operator=(const LblShape& source) = delete;
        //Reads a comma-delimited Cstring form istream:
        //Override the Shape::getSpecs pure virtual function to receive a Cstring (a label) from istream up to the ',' character (and then extract and ignore the comma). Afterward, follow the same logic as was done in the one argument constructor; allocate memory large enough to hold the Cstring and copy the Cstring into the newly allocated memory.
        virtual void getSpecs(std::istream& is);
    };

}

#endif // !NAMESPACE_LBLSHAPE_H