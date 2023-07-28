// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July , 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <cstring>
#include "Publication.h"
#include "Date.h"
#include "Utils.h"

using namespace std;
namespace sdds {

    //double check if Date object m_date can be reallocated
    Publication::Publication(const Publication& issue) : 
        m_membership(issue.m_membership), 
        m_libRef(issue.m_libRef), 
        m_date(issue.m_date) {
            if (issue) {
                ut.strCpy(m_title, issue.m_title);
                ut.strCpy(m_shelfId, issue.m_shelfId);
            }
    }
    //double check that object does not need to be set to a safe state if reallocation is invalid
    Publication& Publication::operator=(const Publication& issue) {
        if (this != &issue) {
            m_membership = issue.m_membership;
            m_libRef = issue.m_libRef;
            m_date = issue.m_date;
            ut.strCpy(m_title, issue.m_title);
            ut.strCpy(m_shelfId, issue.m_shelfId);
        }
        return *this;
    }

//Modifiers:
    void Publication::set(int member_id) {
        if (member_id >= 10000) {
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
    //may not need to validate instance
    char Publication::type()const {
        char letter{};
        if (*this) {
            letter = 'P';
        }
        return letter;
    }

    bool Publication::onLoan() const{
        bool checkedout = false;
        if (m_membership > 9999 && m_membership < 100000) {
            checkedout = true;
        }
        return checkedout;
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
            ostr << "| " << m_shelfId << " | ";
            ostr.width(SDDS_TITLE_WIDTH);
            ostr.fill('.');
            ostr << left << m_title << " | ";
            if (m_membership > 9999 && m_membership < 100000) {
                ostr << m_membership;
            } else {
                ostr << " N/A ";
            }
            ostr << " | " << m_date << " |";
        }
        else {
            ostr << type() << '\t' 
                << m_libRef << '\t'
                << m_shelfId << '\t'
                << m_title << '\t'
                << m_membership << '\t'
                << m_date;
        }
        return ostr;
    }

    istream &Publication::read(istream& istr) {
        m_title[0] = '\0';
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_date = Date();

        if (conIO(istr)) {
            cout << "Shelf No: ";
            istr.get(m_shelfId, SDDS_SHELF_ID_LEN + 1);
            istr.ignore(1000,'\n');
            if (ut.strLen(m_shelfId) != SDDS_SHELF_ID_LEN) {
                istr.setstate(ios::failbit);
            }
            cout << "Title: ";
            istr.getline(m_title, SDDS_TITLE_WIDTH + 1);
            cout << "Date: ";
            istr >> m_date;
        }
        else {
            istr >> m_libRef;
            istr.ignore();
            istr.get(m_shelfId, 5, '\t');
            istr.ignore();
            istr.getline(m_title, sizeof(m_title), '\t');
            istr.ignore();
            istr >> m_membership;
            istr.ignore();
            istr >> m_date;
        }
        //Either way if the date is in an invalid state set the istr to a fail state manually
        if(!m_date) {
            istr.setstate(ios::failbit);
        }
        return istr;
    }

    Publication::operator bool()const {
        return m_title[0] != '\0' && m_shelfId[0] != '\0';
    }

}
