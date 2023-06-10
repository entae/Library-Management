// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: Jun 10, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
namespace sdds {
    class Label {
        char* l_label;
        char* l_border;

        void setToDefault();
        void setBorder(const char* frameArg);
        void setLabel(const char* label);
    public:
        //Prints the label by drawing the frame around the content ad shown in the Execution sample. 
            //Note that no newline is printed after the last line and cout is returned at the end.
        std::ostream& printLabel()const;

        //Reads the label from console up to 70 characters and stores it in the Label as shown in the Execution sample
        void readLabel();
        //Creates an empty label and defaults the frame to "+-+|+-+|"
        Label();
        //Creates an empty label and sets the frame to the frameArg argument.
        Label(const char* frameArg);
        //Creates a Label with the frame set to frameArg 
            //and the content of the Label set to the corresponding argument. 
        //Note that you must keep the content dynamically 
            //even though it should never be more than 70 characters.
        Label(const char* frameArg, const char* content);
        //Makes sure there is no memory leak when the label goes out of scope.
        ~Label();
    };
}

#endif // !SDDS_LABEL_H
