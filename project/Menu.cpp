// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 15, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include "Menu.h"

using namespace std;
namespace sdds {

//MenuItem Class methods:
    MenuItem::MenuItem() {
        m_item = nullptr;
    }
    
    MenuItem::MenuItem(const char* value) {
        if (value != nullptr && value[0] != '\0')
		{
			delete[] m_item;
			m_item = new char[strlen(value) + 1];
			strcpy(m_item, value);
		}
		else
		{
			delete[] m_item;
			m_item = nullptr; // set to empty state
		}
	}

    MenuItem::~MenuItem() {
        delete[] m_item;
    }

    MenuItem::operator bool()const {
        return (m_item != nullptr && m_item[0] != '\0');
    }

    MenuItem::operator const char*() {
        return m_item;
    }

    ostream& MenuItem::display(ostream& os)const {
        if (*this) {
            os << m_item;
        }
        return os;
    }

//Menu class methods:
    Menu::Menu() {
        setEmpty();
    }

    Menu::Menu(const char* title) {
        if (title[0] != '\0') {
            delete[] menu.m_item;
            menu.m_item = new char[strlen(title +1)];
            strcpy(menu.m_item, title);
            m_numItems = 0;
        } else {
			delete[] menu.m_item;
            setEmpty();
		}
	}

    void Menu::setEmpty() {
        menu.m_item = nullptr;
        m_numItems = 0;
    }

    Menu::~Menu() {
        for (int i = 0; i < m_numItems; ++i)
    }

    ostream& Menu::displayTitle(ostream& os)const {
        if (menu) {
            os << menu.m_item;
        } else {
            os << "";
        }
        return os;
    }

    ostream& Menu::displayMenu(ostream& os)const {
        if (menu) {
			displayTitle(); 
			os << ":" << endl;
		}
		for (int i = 0; i < m_numItems; ++i) {
			os << " " << setw(1) << right << i + 1;
			os << "- ";
			m_menuItems[i]->display();
			os << endl;
		}
		os << " 0- Exit" << endl << "> ";
	
		return os;
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
        return (m_numItems >= 1);
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