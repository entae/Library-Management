// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: Aug 6, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LIBAPP_H_
#define SDDS_LIBAPP_H_

#include "Menu.h"
#include "Publication.h"

namespace sdds {
    
    class LibApp {
        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;
        //added in ms5
        char m_fileName[256]{}; 
        Publication* m_PPA[SDDS_LIBRARY_CAPACITY]{}; //Publication Pointers Array
        int m_NOLP{}; //Number of Loaded Publications
        int m_LLRN{}; //Last Library Reference Number
        //"Choose the type of publication:"
        //provide two selections, "Book" and "Publication"
        //setup the publication type menu in the constructor as you did for the main and exit menus
        Menu m_publicationTypeMenu;

        bool confirm(const char* message);

        //simple private functions:
        void load();
        void save();
        int search(int searchType); //int argument added so method can be called in 3 diff modes
        void returnPub();

        //methods with confirmation:
        void newPublication();
        void removePublication();
        void checkOutPub();

    public:
        LibApp();
        LibApp(const char* filename);
        ~LibApp();
        void run();

        Publication* getPub(int libRef);
    };

}

#endif // !SDDS_LIBAPP_H