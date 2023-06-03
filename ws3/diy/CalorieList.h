// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: 
// I have done all the coding by myself 
// and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H
#include "Food.h"
namespace sdds {
  class CalorieList {
    Food* c_name;       // pointer to the dynamically allocated array of Items
    int c_noOfItems;    // size of the dynamically allocated array of Items
    int c_itemsAdded;   // number of the Items added by the add method

    int totalCalorie()const;  // returns the sum of all the calories
    void Title()const;    // Prints the title
    void footer()const;   // Prints the footer containing total calories
    void setEmpty();     // sets the CalorieList to an emtpy state
    bool isValid()const;  // returns true is the CalorieList and all of its Items are valid
  
  public:
    // sets the CalorieList to accept the "size" number of Food Items. 
    // This function is called to prepare the CalorieList for accepting food items
    void init(int size); 

    // Adds Food Items using their Name, Calorie count and time of consumption up to 
    // the number set in the init() function, returns true if successful.
    bool add(const char* item_name, int calories, int when);

    // Displays the report with food information and the total calorie consumed in the day
    // as shown in the report sample
    void display()const;

    // Releases all the memory used. After this function init() can be called for another
    // report;
    void deallocate();
  };
}

#endif // !SDDS_CALORIELIST_H