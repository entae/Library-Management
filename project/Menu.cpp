// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 15, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "Menu.h"

using namespace std;
namespace sdds {

//MenuItem Class methods:
    MenuItem::MenuItem(const char* value) {
        if (value) {
            m_item = new char [strlen(value) + 1];
            strcpy(m_item, value);
        } else {
            m_item = nullptr;
        }
    }
    MenuItem::~MenuItem() {
        delete[] m_item;
    }

    MenuItem::operator bool()const {
        return m_item;
    }

    MenuItem::operator const char*()const {
        return &m_item[0];
    }

    void MenuItem::display(ostream& os)const {
        if (m_item) {
            os << m_item;
        }
    }

//Menu class methods:
    Menu::Menu() {
        m_title = nullptr;
        m_numItems = 0;
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
            m_menuItems[i] = nullptr;
        }
    }

    Menu::Menu(const char* title) {
        if (title) {
            m_title = new char[strlen(title +1)];
            strcpy(m_title, title);
        } 
        m_numItems = 0;
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i)
		{
			m_menuItems[i] = nullptr;
		}
	}

    Menu::~Menu() {
        if (m_menuItems) {
            for (unsigned int i = 0; i < m_numItems; ++i) {
                delete m_menuItems[i];
                m_menuItems[i] = nullptr;
            }
        }
        delete[] m_title;
        m_numItems = 0;
    }

    void Menu::displayTitle(ostream& os)const {
        if (m_title) {
            os << m_title << ":" << endl;
        }
    }

    void Menu::displayMenu(ostream& os)const {
        displayTitle(os);
        for (unsigned int i = 0; i < m_numItems; i++) {
            os << " " << (i + 1) << "- ";
			m_menuItems[i]->display(os);
			os << endl;
        }
        os << " 0- Exit" << endl << "> ";
    }

    unsigned int Menu::run()const {
        unsigned int select;
        displayMenu(cout);
        bool valid = false;
        while (!valid) {
            cin >> select;
            if (cin.fail() || select < 0 || select > m_numItems) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid Selection, try again: ";
            } else {
                cin.ignore(10000, '\n');
                valid = true;
            }
        }
        return select;
    }

    unsigned int Menu::operator~()const {
        return run();
    }

    Menu& Menu::operator<<(const char* menuItemContent) {
        if (m_numItems < MAX_MENU_ITEMS) {
            MenuItem* content = new MenuItem(menuItemContent);
            m_menuItems[m_numItems] = content;
            ++m_numItems;
        }
        return *this;
    }

    Menu::operator int()const {
        return m_numItems;
    }

    Menu::operator unsigned int()const {
        return m_numItems;
    }

    Menu::operator bool()const {
        return m_numItems > 0;
    }

    const char* Menu::operator[](unsigned int index)const {
        if (m_numItems > 0) {
            int menuIndex = index % m_numItems;
            return m_menuItems[menuIndex]->operator const char *();
        }
        return nullptr;
    }

    ostream& operator<<(ostream& os, const Menu& menu) {
        menu.displayTitle(os);
        return os;
    }
}