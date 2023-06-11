// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: Jun 10, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Label.h"
using namespace std;
namespace sdds {

    void Label::setToDefault() {
        l_label = nullptr;
        l_border = nullptr;
        setBorder("+-+|+-+|");
    }

    void Label::setBorder(const char* frameArg) {
        if (frameArg && frameArg[0] != '\0') {
            delete[] l_border;
            l_border = new char[strLen(frameArg) + 1];
            strCpy(l_border, frameArg);
        }
    }

    void Label::setLabel(const char* label) {
        if (label && label[0] != '\0') {
            delete[]l_label;
            l_label = new char[strLen(label) + 1];
            strCpy(l_label, label);
        }
    }

    void Label::readLabel() {
        char str[71];
        //reads a string up to 70 characters or until newline is read
        cin.getline(str, 70, '\n');
        setLabel(str);
    }
  
    //Prints the label by drawing the frame around the content ad shown in the Execution sample. 
        //Note that no newline is printed after the last line and cout is returned at the end.
    ostream& Label::printLabel()const {
        if (l_label && l_border) {
        //top line of frame
            cout << l_border[0];
            line( (strLen(l_label)+2), l_border[1]);
            cout << l_border[2] << endl;
        //empty space above label
            cout << l_border[7];
            line( (strLen(l_label)+2),' ');
            cout << l_border[3] << endl;
        //middle line containing label
            cout << l_border[7];
            cout << ' ' << l_label << ' ' << l_border[3] << endl;
        //empty space below label
            cout << l_border[7];
            line( (strLen(l_label)+2),' ');
            cout << l_border[3] << endl;
        //final line of frame
            cout << l_border[6];
            line( (strLen(l_label)+2), l_border[5]);
            cout << l_border[4];
        }
        return cout;
    }

    Label::Label() {
        setToDefault();
    }
    //Creates an empty label and sets the frame to the frameArg argument.
    Label::Label(const char* frameArg) {
        setToDefault();
        setBorder(frameArg);
    }
    //Creates a Label with the frame set to frameArg 
        //and the content of the Label set to the corresponding argument. 
    //Note that you must keep the content dynamically 
        //even though it should never be more than 70 characters.
    Label::Label(const char* frameArg, const char* content) {
        setToDefault();
        setBorder(frameArg);
        setLabel(content);
    }

    //Makes sure there is no memory leak when the label goes out of scope.
    Label::~Label() {
        delete[] l_label;
        delete[] l_border;
    }

}
