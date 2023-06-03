// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: 
// I have done all the coding by myself 
// and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds {

    int CalorieList::totalCalorie()const {
        int calorieSum = 0;
        int i;
        for (i=0; i < c_itemsAdded; i++) {
            calorieSum += c_name[i].calorieCount();
        }
        return calorieSum;
    }

    void CalorieList::Title()const {
        //start of header
        cout << '+';
        line(52,'-');
        cout << '+' << endl;

        cout << "|  Daily Calorie Consumption";
        line(25,' ');
        cout << "|" << endl;

        cout << '+';
        line(32,'-');
        cout << '+';
        line(6,'-');
        cout << '+';
        line(12,'-');
        cout << '+' << endl;
        
        cout << "| Food name";
        line(22,' ');
        cout << "| Cals | When       |" << endl;

        cout << '+';
        line(32,'-');
        cout << '+';
        line(6,'-');
        cout << '+';
        line(12,'-');
        cout << '+' << endl;
        // end of header
    }

    void CalorieList::footer()const {
        cout << '+';
        line(32,'-');
        cout << '+';
        line(6,'-');
        cout << '+';
        line(12,'-');
        cout << '+' << endl;

        int calorieTotal = totalCalorie();
        cout << "|    Total Calories for today:";
        cout.width(9);
        cout << right << calorieTotal << " |";
        line(12,' ');
        cout << '|' << endl;

        cout << '+';
        line(52,'-');
        cout << '+' << endl;
    } 
    void CalorieList::setEmpty() {
        c_name = nullptr;
    }

    bool CalorieList::isValid()const {
        bool tf = true;
        int i;
        if (c_name == nullptr) {
            tf = false;
        }
        for (i=0; i < c_noOfItems; i++) {
            if (!c_name[i].isValid()) {
                tf = false;
            }
        }
        return tf;
    }

    // sets the CalorieList to accept the "size" number of Food Items. 
    // This function is called to prepare the CalorieList for accepting food items
    void CalorieList::init(int size) {
        int i;
        if (size > 0) {
            c_noOfItems = size;
            c_itemsAdded = 0;
            c_name = new Food[c_noOfItems];
            for (i=0; i < c_noOfItems; i++) {
                c_name[i].setEmpty();
            } 
        } else {
            setEmpty();
        }
    }

    // Adds Food Items using their Name, Calorie count and time of consumption up to 
    // the number set in the init() function, returns true if successful.
    bool CalorieList::add(const char* item_name, int calories, int when) {
        bool tf = false;
        if (c_itemsAdded < c_noOfItems) {
            c_name[c_itemsAdded].set(item_name, calories, when);
            c_itemsAdded++;
            tf = true;
        }
        return tf;
    }

    // Displays the report with food information and the total calorie consumed in the day
    // as shown in the report sample
    void CalorieList::display()const {
        int i;
        Title();
        for (i=0; i < c_noOfItems; i++) {
            c_name[i].display();
        }
        footer();
    }

    // Releases all the memory used. After this function init() can be called for another
    // report;
    void CalorieList::deallocate() {
        //if m_items is not an empty state deallocates the m_items arrays and sets the pointers to null.
        if (c_name != nullptr) {
        delete[] c_name;
          c_name = nullptr;
          c_noOfItems = 0;
          c_itemsAdded = 0;
        }
    }

}