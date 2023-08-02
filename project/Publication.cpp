// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 28, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Utils.h"
#include "Publication.h"

using namespace std;
namespace sdds {

    Publication::Publication() {
       makeDefault();
    }

    Publication::~Publication() {
        delete[] m_title;
    }

    //double check if Date object m_date can be reallocated
    Publication::Publication(const Publication& issue) {
        *this = issue;
    }
    //double check that object does not need to be set to a safe state if reallocation is invalid
    Publication& Publication::operator=(const Publication& issue) {
        if (this != &issue) {
            if (issue) {
                if (m_title) {
                    delete[] m_title;
                    m_title = nullptr;
                }
                m_title = new char[ut.strLen(issue.m_title) + 1];
                ut.strCpy(m_title, issue.m_title);
                set(issue.m_membership);
                setRef(issue.m_libRef);
                m_date = issue.m_date;
                ut.strCpy(m_shelfId, issue.m_shelfId);
            }
        }
        return *this;
    }

//Modifiers:
    void Publication::makeDefault() {
        if (m_title) {
            delete[] m_title;
        }
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        resetDate();
    }

    void Publication::set(int member_id) {
        if (member_id > 9999 && member_id < 100000) {
            m_membership = member_id;
        } else {
            m_membership = 0;
        }
    }

    void Publication::setRef(int value) {
        m_libRef = value;
    }

    void Publication::resetDate() {
        m_date = Date();
    }

//Queries:
    char Publication::type()const {
        return 'P';
    }

    bool Publication::onLoan() const{
        return (m_membership > 9999 && m_membership < 100000);
    }

    Date Publication::checkoutDate()const {
        return m_date;
    }

    bool Publication::operator==(const char* title)const {
        return strstr(m_title, title ) != nullptr;
    }

    Publication::operator const char* ()const {
        return m_title;
    }

    int Publication::getRef()const {
        return m_libRef;
    }
//Streamable pure virtual functions:
    bool Publication::conIO(ios &io)const {
        return (&io == &cin || &io == &cout);
    }

    ostream& Publication::write(ostream& ostr)const {
        if (conIO(ostr)) {
            ostr << "| ";
            ostr << m_shelfId << " | ";

            ostr.width(SDDS_TITLE_WIDTH);
            ostr.fill('.');
            ostr << left;
            if (m_title) {
                char temp[SDDS_TITLE_WIDTH + 1];
                ut.strncpy(temp, m_title, SDDS_TITLE_WIDTH);
                temp[SDDS_TITLE_WIDTH] = '\0';
                ostr << temp;
            } 
             ostr << " | ";

            if (onLoan()) {
                ostr << m_membership;
            } else {
                ostr << " N/A ";
            }
            ostr << " | " << checkoutDate() << " |";
        }
        else {
            ostr << type() << '\t'
                << m_libRef << '\t'
                << m_shelfId << '\t'
                << m_title << '\t';
                if (onLoan()) {
                    ostr << m_membership;
                }
                else {
                    ostr << " N/A ";
                }
                ostr << '\t' << checkoutDate();
        }
        return ostr;
    }

    istream &Publication::read(istream& istr) {
        //local variables;
        char tempTitle[256]{};
        char tempShelfId[SDDS_SHELF_ID_LEN + 1]{};
        int tempMembership = 0;
        int tempLibRef = -1;
        Date tempDate;

        //clear all attributes to default
        makeDefault();

        // Read all values into local variables
        if (conIO(istr)) {
            cout << "Shelf No: ";
            istr.getline(tempShelfId, SDDS_SHELF_ID_LEN + 1);

            if (ut.strLen(tempShelfId) != SDDS_SHELF_ID_LEN) {
                istr.setstate(ios::failbit);
            }
            cout << "Title: ";
            istr.getline(tempTitle, 256);
            cout << "Date: ";
            istr >> tempDate;
        } 
        else {
            istr >> tempLibRef;
            istr.ignore(1000, '\t');
            istr.getline(tempShelfId, SDDS_SHELF_ID_LEN + 1, '\t');
            istr.getline(tempTitle, 256, '\t');
            istr >> tempMembership;
            istr.ignore(1000, '\t');
            istr >> tempDate;
        }
        //if tempDate is invalid set istr to failstate
        if (!tempDate) {
            istr.setstate(ios::failbit);
        }
        //if istr is not in fail state, read interactively
        else {
            m_title = new char[ut.strLen(tempTitle) + 1];
            ut.strCpy(m_title, tempTitle);
            ut.strCpy(m_shelfId, tempShelfId);
            set(tempMembership);
            setRef(tempLibRef);
            m_date = tempDate;
        }
        return istr;
    }

    Publication::operator bool()const {
        return (m_title && m_title[0] != '\0' && m_shelfId[0] != '\0' && m_date);
    }

}
