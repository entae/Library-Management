// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 6, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"

using namespace std;
namespace sdds {
    //Returns the address held in the m_value attribute.
    Line::operator const char* () const {
        return (const char*)m_value;
    }

    //Dynamically allocates memory in m_value and copies the Cstring pointed by lineContent into it
    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = nullptr;
        if (lineValue != nullptr) {
            m_value = new char[strLen(lineValue) + 1];
            strCpy(m_value, lineValue);
        }
        return *this;
    }

    //Initializes the m_value attribute to nullptr
    Line::Line() {
        m_value = nullptr;
    }

    //Makes sure all the allocated memory is freed.
    Line::~Line() {
        delete[] m_value;
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {
        delete[] m_filename;
        if (!isCopy) {
            m_filename = new char[strLen(fname)+1];
            strCpy(m_filename, fname); 
        } else {
            m_filename = new char[strLen(fname)+3];
            strCpy(m_filename, "C_");
            strCat(m_filename, fname);
        }
    }

    void TextFile::setNoOfLines() {
        char ch;
    
        ifstream readFile(m_filename);
        m_noOfLines = 0;

        while (readFile.get(ch)) {
            if (ch == '\n') {
                m_noOfLines++;
            }
        }
        m_noOfLines++;
        if (m_noOfLines == 0) {
            delete[] m_filename;
            m_filename = nullptr;
            setEmpty();
        }
    }

    void TextFile::loadText() {
        if (m_filename != nullptr) {
            delete[] m_textLines;
            m_textLines = nullptr;

            ifstream loadFile(m_filename);
            if (loadFile.is_open()) {
                string line;
                m_noOfLines = 0;

                while (getline(loadFile, line)) {
                    m_noOfLines++;
                }

                if (m_noOfLines > 0) {
                    m_textLines = new Line[m_noOfLines];

                    loadFile.clear();
                    loadFile.seekg(0);

                    for (unsigned int i = 0; i < m_noOfLines; i++) {
                        getline(loadFile, line);
                        m_textLines[i] = line.c_str();
                    }
                }
            }
            loadFile.close();
        }
    }

    //Saves the content of the TextFile under a new name
    void TextFile::saveAs(const char *fileName)const {
        if (fileName != nullptr) {
            ofstream newFile(fileName);
            if (newFile.is_open()) {
               for (unsigned int i = 0; i < m_noOfLines; i++) {
                newFile << m_textLines[i] << endl;
               }
               newFile.close();
            } else {
                cerr << "saveAs: Error opening file" << fileName << endl;
            }
        } else {
            cerr << "saveAs: Invalid fileName" << endl;
        }
    }

    //deletes the m_textLines dynamic array and sets it to nullptr
    //deletes the m_filename dynamic Cstring and sets it to nullptr
    //sets m_noOfLines to zero
    void TextFile::setEmpty() {
        delete[] m_textLines;
        delete[] m_filename;
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
    }

//public:
    TextFile::TextFile(unsigned pageSize) {
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
        m_pageSize = pageSize;
    }

    TextFile::TextFile(const char* filename, unsigned pageSize) {
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
        m_pageSize = pageSize;
        if (filename[0] != '\0') {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
    }

    //copy constructor
    TextFile::TextFile(const TextFile& source) {
        m_pageSize = source.m_pageSize;
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
        if (source.m_filename[0] != '\0') {
            m_filename = new char[strLen(source.m_filename) + 1];
            setFilename(source.m_filename, true);
            source.saveAs(m_filename);
            setNoOfLines();
            loadText();
        } 
    }
    
    //assignment constructor
    TextFile& TextFile::operator=(const TextFile& source) {
        if (*this && source && (this != &source)) {
            delete[] m_textLines;
            m_textLines = nullptr;
            source.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
        return *this;
    }

    TextFile::~TextFile() {
        delete[] m_textLines;
        delete[] m_filename;
    }

    ostream& TextFile::view(ostream& ostr)const {
        if (*this) {
            int i;
            ostr << m_filename << endl;
            for (i = 0; i < strLen(m_filename); i++) {
                ostr << '=';
            }
            ostr << endl;
            for (i = 0; i < m_noOfLines; i++) {
                ostr << m_textLines[i] << endl;
                
                if ((i+1) % m_pageSize == 0) {
                    ostr << "Hit ENTER to continue...";
                    ostr.flush();
                    string input;
                    getline(cin, input);
                }
            }
        }
        return ostr;
    }

    istream& TextFile::getFile(istream& istr) {
        string filename, line;
        getline(istr, filename);
        setFilename(filename.c_str());
        loadText(); 
        istr.clear();

        return istr;
    }

    TextFile::operator bool()const {
        return m_textLines != nullptr && m_filename != nullptr && m_noOfLines > 0;
    }

    unsigned TextFile::lines()const {
        return m_noOfLines;
    }

    const char* TextFile::name()const {
        return m_filename;

    }

    const char* TextFile::operator[](unsigned index)const {
        const char* value = nullptr;
        if ((int)m_noOfLines > 0) {
            value = m_textLines[index % (int)m_noOfLines];
        }
        return value;
    }

//Helper Functions
    ostream& operator<<(ostream& ostr, const TextFile& text) {
        text.view(ostr);
        return ostr;
    }

    istream& operator>>(istream& istr, TextFile& text) {
        text.getFile(istr);
        return istr;
    }

}