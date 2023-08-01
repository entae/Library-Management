// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 31, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds {
    class HtmlText :  public Text {
        //holds title of HTML conversion dynamically
        char* m_title;
    public:
        HtmlText(const char* filename=nullptr, const char* title = nullptr);
        //rule of three goes here
        HtmlText(const HtmlText& code);
        HtmlText& operator=(const HtmlText& code);
        virtual ~HtmlText();

        //overriding the write function
        virtual void write(std::ostream& os)const;
    };
}
#endif // !SDDS_HTMLTEXT_H__