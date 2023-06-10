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
#include "LabelMaker.h"
using namespace std;
namespace sdds {
    //creates a dynamic array of Labels to the size of noOfLabels
    LabelMaker::LabelMaker(int noOfLabels) {
        m_noOfLabels = noOfLabels;
        m_labels = new Label[noOfLabels];
    }

    //Prints the Labels as demonstrated in the Execution sample
    void LabelMaker::printLabels() {
        for (int i = 0; i < m_noOfLabels; i++) {
            m_labels[i].printLabel();
            cout << "\n";
        }
    }

    //Gets the contents of the Labels as demonstrated in the Execution sample
    void LabelMaker::readLabels() {
        cout << "Enter " << m_noOfLabels << " labels:" << endl;
        for (int i = 0; i < m_noOfLabels; ++i) {
            cout << "Enter label number " << i + 1 << endl;
            cout << "> ";
            m_labels[i].readLabel();
        }
    }

     LabelMaker::~LabelMaker() {
        delete[] m_labels;
     }
}
