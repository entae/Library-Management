// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: Aug 2, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.


#include <iostream>
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
                m_author = new char[ut.strLen(book.m_author) + 1];
                ut.strCpy(m_author, book.m_author);
            }
            else {
                m_author = nullptr;
            }
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
            ostr << ' ' << ostr.width(SDDS_AUTHOR_WIDTH) << left;
            if (ut.strLen(m_author) > SDDS_AUTHOR_WIDTH) {
                for (int i = 0; i < SDDS_AUTHOR_WIDTH; ++ i) {
                    ostr << m_author[i];
                }
            }
            else {
                ostr << m_author;
            }
            ostr << " |";
        }
        else {
            ostr << '\t';
            if (ut.strLen(m_author) > SDDS_AUTHOR_WIDTH) {
                for (int i = 0; i < SDDS_AUTHOR_WIDTH; ++ i) {
                    ostr << m_author[i];
                }
            }
            else {
                ostr << m_author;
            }
        }
        return ostr;
    }

    std::istream& Book::read(std::istream& istr){
        Publication::read(istr);

        char tempName[256]{};
        delete[] m_author;
        m_author = nullptr;

        if (conIO(istr)) {
            istr.ignore(1000,'\n');
            cout << "Author: ";
            istr.getline(tempName, 256);
        }
        else {
            istr.ignore(1000,'\t');
            istr.getline(tempName, 256, '\t');
        }
        if (istr) {
            m_author = new char[ut.strLen(tempName) + 1];
            ut.strCpy(m_author, tempName);
        }
        return istr;
    }

    void Book::set(int member_id){
        Publication::set(member_id);
        resetDate();
    }

    Book::operator bool()const{
        return (m_author && m_author[0] != '\0' && Publication::operator bool());
    }
}