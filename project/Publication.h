// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July , 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include "Date.h"
#include "Lib.h"

namespace sdds {
    class Publication : public Streamable {
        char* m_title{}; //assume dynamic array cannot be more than 255 char long
        char m_shelfId[5]{};
        int m_membership{}; //0 = available; 10000 >= checked out by member
        int m_libRef{-1};
        Date m_date{};

    public:
        //constructor //may need to define char strings
        Publication();
        //destructor
        virtual ~Publication();
        //copy constructor
        Publication(const Publication& issue);
        //copy assignment
        Publication& operator=(const Publication& issue);

    //Modifiers:    
        // Sets the membership attribute to either zero or a five-digit integer.
        virtual void set(int member_id);

        // Sets the **libRef** attribute value 
        void setRef(int value);

        // Sets the date to the current date of the system.
        void resetDate();

    //Queries:
        //Returns the character 'P' to identify this object as a "Publication object"
        virtual char type()const;
        
        //Returns true is the publication is checkout (membership is non-zero)
        bool onLoan()const;
        
        //Returns the date attribute
        Date checkoutDate()const; 
        
        //Returns true if the argument title appears anywhere in the title of the publication. Otherwise, it returns false; (use strstr() function in <cstring>)
        bool operator==(const char* title)const;
        
        //Returns the title attribute
        operator const char* ()const;
        
        //Returns the libRef attribute. 
        int getRef()const;
        
    //Streamable pure virtual functions
        bool conIO(std::ios& io)const;

        virtual std::ostream& write(std::ostream& ostr)const;

        virtual std::istream& read(std::istream& istr);

        operator bool()const;
    };
}

#endif // !SDDS_PUBLICATION_H