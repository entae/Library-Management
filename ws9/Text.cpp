// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 31, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#include <fstream>
#include "Text.h"
#include "cstring.h"

using namespace std;
namespace sdds {
    int Text::getFileLength() const {
        int len = 0;
        ifstream fin(m_filename); //open file stored in m_filename, and alias it with "fin"
        //white file has content, get characters from the file and increment len for each char read
        while (fin) {
            fin.get();
            //(!fin) is a boolean
            //!(!fin) turns value into a int
            len += !!fin;
        }
        //returns total number of characters read
        return len;
    }

    const char& Text::operator[](int index)const {
        //returns char at specific index
        return m_content[index];
    }
    //constructor
    Text::Text(const char* filename) :
        m_filename(nullptr), 
        m_content(nullptr) {
            if (filename) {
                //allocating memory for filename
                m_filename = new char[strLen(filename) + 1];
                //copying filename into m_filename
                strCpy(m_filename, filename);
                //copy content of file into m_content
                read();
            }
    }
    //destructor
    Text::~Text() {
        delete[] m_filename;
        delete[] m_content;
    }
    //copy constructor
    Text::Text(const Text& text) :
        m_filename(nullptr),
        m_content(nullptr) {
            //calling copy assignment operator for deep copy
            *this = text;
        }
    //copy assignment
    Text& Text::operator=(const Text& text) {
        if (this != &text) {
            delete[] m_filename;
            delete[] m_content;

            m_filename = new char[strLen(text.m_filename) + 1];
            strCpy(m_filename, text.m_filename);

            if (text.m_content) {
                m_content = new char[strLen(text.m_content) + 1];
                strCpy(m_content, text.m_content);
            }
            else {
                //if m_content is invalid, set m_content to null
                m_content = nullptr;
            }
        }
        return *this;
    }

    void Text::read() {
        if (m_filename) {
            //open file for reading
            ifstream fin(m_filename);
            if(fin.is_open()) {
                // seek = pointer to end of file
                fin.seekg(0, ios::end);
                //tellg returns position of pointer (eof)
                //give size of file in bytes
                int fileSize = fin.tellg();
                //pointer is back to the beginning of file
                fin.seekg(0, ios::beg);

                delete[] m_content;
                m_content = new char[fileSize + 1];

                int index = 0;
                char ch;
                while (fin.get(ch)) {
                    m_content[index++] = ch;
                }
                m_content[index] = '\0';
            }
            else {
                //sets empty if file cannot be opened
                setEmpty();
            }
        }
        else {
            //sets empty if filename is null
            setEmpty();
        }
    }

    void Text::write(ostream& os)const {
        if (m_content) {
            os << m_content;
        }
    }

    void Text::setEmpty() {
        delete[] m_filename;
        m_filename = nullptr;
        delete[] m_content;
        m_content = nullptr;

    }

    //returns true if filename and content are not null/empty
    Text::operator bool() const {
        return (m_filename && m_content && m_filename[0] != '\0' && m_content[0] != '\0');
    }

    std::ostream &operator<<(std::ostream& os, const Text& source) {
        if (source) {
            source.write(os);
        }
        return os;
    }

}