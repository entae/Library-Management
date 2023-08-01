// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: Aug 2, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include <iostream>
#include "Publication.h"

namespace sdds {
    class Book : public Publication {
        char* m_author{nullptr};
    public: 
        //constructor
        Book();
        //Rule of 3
        Book(const Book& book);
        Book& operator=(const Book& book);
        virtual ~Book();

        //methods
        virtual char type()const;
        virtual std::ostream& write(std::ostream& ostr)const;
        virtual std::istream& read(std::istream& istr);
        virtual void set(int member_id);
        virtual operator bool()const;
    };

}

#endif // !SDDS_BOOK_H__