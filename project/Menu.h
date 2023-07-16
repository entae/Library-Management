// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 15, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>

namespace sdds {

    const int MAX_MENU_ITEMS = 20;

    //A class that has several MenuItems to be displayed so the user can select one of them for an action to be executed in the program
    class Menu;

    //A class that hold a text Item; (an option or title to be displayed) in a menu to be selected by the user. This is a fully private class that is only accessible by Menu (see next class)
    class MenuItem {
        friend class Menu;

        char* m_item{nullptr};
        MenuItem(const char* value = nullptr); // set to empty state
        ~MenuItem();
        //delete copy constructor and copy assignment
        MenuItem(const Menu& source) = delete;
        MenuItem& operator=(const Menu& source) = delete;
        operator bool()const;
        operator const char*()const; //when MenuItem is casted to "const char*", should return the address of the content Cstring
        void display(std::ostream& os)const;
    };

    class Menu {
        char* m_title{nullptr};
        MenuItem* m_menuItems[MAX_MENU_ITEMS] = {nullptr};
        unsigned int m_numItems {0};
    public:
        Menu();
        Menu(const char* title);
        ~Menu();
        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;
        void displayTitle(std::ostream& os)const;
        void displayMenu(std::ostream& os)const;
        unsigned int run()const;
        unsigned int operator~()const;
        Menu& operator<<(const char* menuItemContent);
        operator int()const;
        operator unsigned int()const;
        operator bool()const;
        const char* operator[](unsigned int index)const;
    };
    std::ostream& operator<<(std::ostream& os, const Menu& menu);
}
#endif // !SDDS_MENU_H__