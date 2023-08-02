// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: Aug 2, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <cstring>
#include "Book.h"
#include "Utils.h"

using namespace std;
namespace sdds {
    Book::Book() : Publication() {};

    Book::Book(const Book& book):
        Publication(book) {
            //using copy allocator
            *this = book;
    }

    Book &Book::operator=(const Book& book){
        if (this != &book) {
            Publication::operator=(book);
            if (m_author) {
                delete[] m_author;
                m_author = nullptr;
            }

            if(book.m_author) {
                m_author = new char[strlen(book.m_author) + 1];
                strcpy(m_author, book.m_author);
            }
            // else {
            //     m_author = nullptr;
            // }
        }
        return *this;
    }

    Book::~Book(){
        delete[] m_author;
    }

    char Book::type()const{
        return 'B';
    }

    ostream& Book::write(ostream& ostr)const{
        Publication::write(ostr);

        if (conIO(ostr)) {
            char temp[SDDS_AUTHOR_WIDTH + 1]{};
            strncpy(temp, m_author, SDDS_AUTHOR_WIDTH);
            ostr << ' ';
            ostr.width(SDDS_AUTHOR_WIDTH);
            ostr << left;
            ostr.fill(' ');
            ostr << temp;
            ostr << " |";
        }
        else {
            ostr << '\t' << m_author;
        }
        return ostr;
    }

    std::istream& Book::read(std::istream& istr){
        Publication::read(istr);

        char tempName[256]{};
        if (m_author) {
            delete[] m_author;
            m_author = nullptr;
        }

        if (conIO(istr)) {
            istr.ignore(); //1000,'\n'
            cout << "Author: ";
        }
        else {
            istr.ignore(1000,'\t');
        }
        istr.get(tempName, 256);
        
        if (istr) {
            m_author = new char[strlen(tempName) + 1];
            strcpy(m_author, tempName);
            //m_author[strlen(tempName)] = '\0';
        }
        return istr;
    }

    void Book::set(int member_id){
        Publication::set(member_id);
        Publication::resetDate();
    }

    Book::operator bool()const{
        return (m_author && m_author[0] != '\0' && Publication::operator bool());
    }
}