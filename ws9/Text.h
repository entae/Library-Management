// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 31, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#include <iostream>

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
namespace sdds {
    class Text {
        //home name of file dynamically
        char* m_filename{};
        //context of text file dynamically
        char* m_content{};
        //returns length(size) of file on disk. 
        //else, returns zero if file is null/empty
        int getFileLength()const; //code provided in Text.cpp
    protected:
        //provides read-only access to the content of the text for derived classes
        const char& operator[](int index)const;
    public:
        Text(const char* filename=nullptr);
        //implemented Rule of 3 here:
        Text(const Text& text);
        Text& operator=(const Text& text);
        virtual ~Text();

        //read current content then allocate memory to size of the file on disk (getFileLength) + 1.
        //then read the content of file char by char into newly alloc'd memory and terminates it with a null byte at end
        void read();
        //insert content of Text class into ostream if m_content not null
        virtual void write(std::ostream& os)const;

        //further implemented functions:
        
        //method to set the object to an empty state
        virtual void setEmpty();
        //conversion operator to check if the object is valid
        virtual operator bool()const;
    };
    //prototype of insertion overload into ostream here:
    std::ostream& operator<<(std::ostream& os, const Text& source);
}
#endif // !SDDS_PERSON_H__

//*if anything goes wrong in setting up the class or reading a file, it will be set to an empty state