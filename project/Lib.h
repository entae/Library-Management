// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July , 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LIB_H__
#define SDDS_LIB_H__
#include <iostream>

namespace sdds {
    const int SDDS_MAX_LOAN_DAYS = 15; 
     // maximum number of day a publication can be borrowed with no penalty
    const int SDDS_TITLE_WIDTH = 30;
    // The width in which the title of a publication should be printed on the console
    const int SDDS_AUTHOR_WIDTH = 15;
    // The width in which the author name of a book should be printed on the console
    const int SDDS_SHELF_ID_LEN = 4;
   // The width in which the shelf id of a publication should be printed on the console
    const int SDDS_LIBRARY_CAPACITY = 5000;
   // Maximum number of publications the library can hold.

   //An Interface is an abstract base class with only pure virtual functions.
    class Streamable {
    public:
        virtual std::ostream& write(std::ostream& ostr)const = 0;

        virtual std::istream& read(std::istream& istr) = 0;

        virtual bool conIO(std::ios& io)const = 0;

        virtual operator bool()const = 0;

        virtual ~Streamable() {};
    };

    std::ostream& operator<<(std::ostream& os, const Streamable& stream);

    std::istream& operator>>(std::istream& is, Streamable& stream);
}

//This will make the global variables added to Date.cpp, truly global for any code including "Date.h".
//    extern const int SDDS_MAX_LOAN_DAYS;
//    extern const int SDDS_TITLE_WIDTH;
//    extern const int SDDS_AUTHOR_WIDTH;
//    extern const int SDDS_SHELF_ID_LEN;
//    extern const int SDDS_LIBRARY_CAPACITY;

#endif // !SDDS_LIB_H__