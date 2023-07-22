// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 21, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LIBAPP_H_
#define SDDS_LIBAPP_H_

#include "Menu.h"

namespace sdds {
    
    class LibApp {
        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;

        bool confirm(const char* message);

        //simple private functions:
        void load();
        void save();
        void search();
        void returnPub();

        //methods with confirmation:
        void newPublication();
        void removePublication();
        void checkOutPub();

    public:
        LibApp();
        void run();
    };

}

#endif // !SDDS_LIBAPP_H