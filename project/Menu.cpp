// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 15, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include<iomanip>
#include <iostream> 

using namespace std;
#include "Menu.h"
#include "Utils.h"

namespace sdds 
{
	MenuItem::MenuItem() {
		m_name = nullptr;
	}

	MenuItem::MenuItem(const char* name)
	{
		if (name) {
			delete[] m_name;
			m_name = new char[strLen(name) + 1];
			strCpy(m_name, name);
		} else {
			delete[] m_name;
			m_name = nullptr; 
		}
	}

	MenuItem::~MenuItem() {
		delete[] m_name;
	}

	MenuItem::operator bool() const {
		return (m_name != nullptr && m_name[0] != '\0');
	}


	MenuItem::operator const char*() {
		return m_name;
	}


	ostream& MenuItem::display(ostream& os = cout)const {
		if (*this) {
			os << m_name;
		}
		return os;
	}

	Menu::Menu() {
		menuName.m_name = nullptr;
		numMenu = 0;
	}

	Menu::Menu(const char* name) {
		if (name) {
			delete[] menuName.m_name;
			menuName.m_name = new char[strLen(name) + 1];
			strCpy(menuName.m_name,name);
			numMenu = 0;
		} else {
			delete[] menuName.m_name;
			menuName.m_name = nullptr;
			numMenu = 0;
		}	
	}

	Menu::~Menu() {
		for (int i = 0; i < numMenu; ++i) {
			delete menuArray[i];
		}
	}

	ostream& Menu::displayName(ostream& os = cout)const {
		if (menuName) {
			os << menuName.m_name;
		} else {
			os << "";
		}
		return os;
	}

	ostream& Menu::displayMenu(ostream& os = cout)const {
		if (menuName) {
			displayName(); 
			os << endl;
		}
		for (int i = 0; i < numMenu; ++i) {
			os << " " << setw(1) << right << i + 1;
			os << "- ";
			menuArray[i]->display();
			os << endl;
		}
		os << " 0- Exit" << endl << "> ";
		return os;
	}

	unsigned int Menu::operator~() {
		int selection = run(cin);
		return selection;
	}

	unsigned int Menu::run(istream& is = cin) const {
		int select;
		int flag = 1;
		displayMenu();
		while (flag) {
			if (!(is >> select) || select > numMenu || select < 0) {
				is.clear();
				is.ignore(200, '\n');
				cout << "Invalid Selection, try again: ";
			}
			else{
				is.ignore(200, '\n');
				flag = 0;
			}
		}
		return select;
	}

	Menu& Menu::operator<<(const char* menuitemContent) {
		if (numMenu < (int)MAX_MENU_ITEMS) {
			menuArray[numMenu] = new MenuItem(menuitemContent);
			numMenu++;
		}
		return *this;
	}

	Menu::operator int() const {
		return numMenu;
	}

	Menu::operator unsigned int() const {
		return numMenu;
	}


	Menu::operator bool() const {
		return (numMenu >= 1);
	}


	ostream& operator<<(ostream& os, const Menu& aMenu) {
		return aMenu.displayName(os);
	}


	const char* Menu::operator[](int size) const {
		if (size < numMenu)
		{
			return (const char*)(*menuArray[size]);
		}
		else
		{
			int mod = size % numMenu;
			return (const char*)(*menuArray[mod]);
		}
	}
}