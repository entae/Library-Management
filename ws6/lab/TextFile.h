// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 6, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>
namespace sdds {
    //encapsulates a single line of a text file
    class Line {
        char* m_value{ nullptr };

        operator const char* ()const;
        Line();
        Line& operator=(const char*);
        ~Line();
        friend class TextFile;
        // copy and copy assignment prevention goes here
        Line(const Line& source) = delete;
        Line& operator=(const Line& source) = delete;
    };
   
    //encapsulates a text file on the hard drive 
    //and it is a dynamic array of Lines
    //an instance of Line class should not be able to exist outside of a TextFile class
    class TextFile {
        //A pointer to hold the dynamic array of Lines. This attribute should be initialized to nullptr
        Line* m_textLines;
        //pointer to hold the dynamic Cstring holding the name of the file. This attribute should be initialized to nullptr
        char* m_filename;
        //unsigned int to be set to the number of lines in the file
        unsigned m_noOfLines;
        //page size is the number of lines that should be displayed on the screen before the display is paused. After these lines are displayed, the user must hit enter for the next page to appear.
        unsigned m_pageSize;

        void setFilename(const char* fname, bool isCopy = false);
        void setNoOfLines();
        void loadText();
        void saveAs(const char *fileName)const;
        void setEmpty();
    public:
        TextFile(unsigned pageSize = 15);
        TextFile(const char* filename, unsigned pageSize = 15);
        TextFile(const TextFile& source);
        TextFile& operator=(const TextFile& source);
        ~TextFile();
        std::ostream& view(std::ostream& ostr)const;
        std::istream& getFile(std::istream& istr);
        operator bool()const;
        unsigned lines()const;
        const char* name()const;
        const char* operator[](unsigned index)const;
    };
    std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
    std::istream& operator>>(std::istream& istr, TextFile& text);

}
#endif // !SDDS_TEXTFILE_H__