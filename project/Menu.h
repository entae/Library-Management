// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 15, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_

namespace sdds {

	// Forward declaration
	class Menu; 
	const unsigned int MAX_MENU_ITEMS = 20;

	class MenuItem
	{
		char* m_name{}; // cstring of characters for the content of the menu item dynamically
		
		//constructors
		MenuItem();
		MenuItem(const char*);
		//copy constructor and copy assignment deleted
		MenuItem(const MenuItem& src) = delete;
		MenuItem& operator=(const MenuItem& src) = delete;
		//destructor
		~MenuItem();
		//bool type conversion
		operator bool() const;
		//const char* type conversion
		operator const char* ();
		//display the content of the MenuItem on ostream
		std::ostream& display(std::ostream& os)const;

		friend class Menu;
	};


	class Menu
	{
		//attributes
		MenuItem menuName;
		MenuItem* menuArray[MAX_MENU_ITEMS]{};
		int numMenu;
		//copy constructor and copy assignment deleted
		Menu(const Menu& src) = delete;
		Menu& operator=(const Menu& src) = delete;

	public:
		//constructors
		Menu();
		Menu(const char*);
		//destructor
		~Menu();
		// Display the title of the Menu on ostream
		std::ostream& displayName(std::ostream& os)const;
		// Display the entire Menu on ostream
		std::ostream& displayMenu(std::ostream& os)const;
	
		
		// foolproof function run
		unsigned int run(std::istream& is)const; 
		unsigned int operator~();

		//overload to add a MenuItem to the Menu
		Menu& operator<<(const char* menuitemContent);
		
		//int and unsigned int overloads to return the number of MenuItems on the Menu
		operator int() const;
		operator unsigned int() const;

		//bool type conversion, returns true if Menu has 1 or more MenuItems
		operator bool() const;

		//indexing operator, returns the const char* cast of corresponding MenuItem in the array of MenuItem pointers.
		const char* operator[](int) const;
	};

	std::ostream& operator<<(std::ostream& os, const Menu&);
}

#endif // !SDDS_MENU_H_
