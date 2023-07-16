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
		
		//constructor
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
		std::ostream& display(std::ostream& os = std::cout)const;

		friend class Menu;
	};


	class Menu
	{
		//attributes
		MenuItem menuName;
		MenuItem* menuArray[MAX_MENU_ITEMS]{};
		int numMenu;
		
		Menu(const Menu& src) = delete;
		Menu& operator=(const Menu& src) = delete;

	public:
		//constructors
		Menu();
		Menu(const char*);
		//destructor
		~Menu();
		// Display the title of the Menu on ostream
		std::ostream& displayName(std::ostream& os = std::cout)const;
		// Display the entire Menu on ostream
		std::ostream& displayMenu(std::ostream& os = std::cout)const;
	
		
		// foolproof function run
		unsigned int run(std::istream& is = std::cin)const; 
		unsigned int operator~();

		Menu& operator<<(const char* menuitemContent);
		
		operator int() const;
		operator unsigned int() const;

		operator bool() const;

		const char* operator[](int) const;
	};

	std::ostream& operator<<(std::ostream& os, const Menu&);
}

#endif // !SDDS_MENU_H_
