// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: Jun 10, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include <iostream>
#include "Label.h"
namespace sdds {
    class LabelMaker {
        Label* m_labels;
        int m_noOfLabels;
    public:
        //creates a dynamic array of Labels to the size of noOfLabels
        LabelMaker(int noOfLabels);
        //Prints the Labels as demonstrated in the Execution sample
        void printLabels();
        //Gets the contents of the Labels as demonstrated in the Execution sample
        void readLabels();
        //Deallocates the memory when LabelMaker goes out of scope.
        ~LabelMaker();
    };
}

#endif //!SDDS_LABELMAKER_H