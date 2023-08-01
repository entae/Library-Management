// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 31, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#include "HtmlText.h"
#include "cstring.h"

using namespace std;
namespace sdds {

    HtmlText::HtmlText(const char* filename, const char* title) :
        Text(filename), m_title(nullptr) {
            if (title) {
                m_title = new char[strLen(title) + 1];
                strCpy(m_title, title);
            }
        }

    HtmlText::HtmlText(const HtmlText& other) : 
        Text(other) {
        if (other.m_title) {
            m_title = new char[strLen(other.m_title) + 1];
            strCpy(m_title, other.m_title);
        }
        else {
            m_title = nullptr;
        }
    }

    HtmlText::~HtmlText() {
        delete[] m_title;
    }

    HtmlText& HtmlText::operator=(const HtmlText& code) {
        if (this != &code) {
            Text::operator=(code);

            delete[] m_title;
            if (code.m_title) {
                m_title = new char[strLen(code.m_title) + 1];
                strCpy(m_title, code.m_title);
            }
            else {
                //if reference has no title, set m_title to null
                m_title = nullptr;
            }
        }
        return *this;
    }


    void HtmlText::write(ostream& os)const {
        os << "<html><head><title>";
        (m_title) ? os << m_title : os << "No Title";

        os << "</title></head>\n<body>\n";
        if (m_title) {
            os << "<h1>" << m_title <<  "</h1>\n";
        }
    //keeps track of Multiple Spaces
    bool MS = false;
    //loops through each character in m_content using index op
    for (int i = 0; (*this)[i]; i ++) {
        //gets current character in index
        char ch = (*this)[i];
        //switch statement for each condition based on char value
        switch (ch) {
        case ' ':
            //nbsp = non-break space
            (MS) ? os << "&nbsp;" : os << ' ';
            //toggles true to indicate a space was found
            MS = true;
            break;
        case '<':
            os << "&lt;";
            MS = false;
            break;
        case '>':
            os << "&gt;";
            MS = false;
            break;
        case '\n':
            os << "<br />\n";
            MS = false;
            break;
        default:
            os << ch;
            MS = false;
        }
    }
    os << "</body>\n</html>";
    }

}
