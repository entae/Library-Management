// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: 
// I have done all the coding by myself 
// and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;
namespace sdds {
    void Food::setName(const char* name) {
        strnCpy(f_name, name, 30);
        f_name[30] = '\0';
    }

    void Food::setEmpty() {
        f_name[0] = '\0';
        f_cal = 0;
        f_when = 0;
    }

    void Food::set(const char* name, int calorie, int mealtime) {
        if (name != nullptr) {
            setName(name);
        } else {
            setName("");
        }
        if (calorie > 0) {
            f_cal = calorie;
        } else {
            f_cal = 0;
        }
        if (mealtime > 0) {
            f_when = mealtime;
        } else {
            f_when = 0;
        }
    }

    void Food::display()const {
        if (isValid()) {
            cout << "| ";
            cout.width(30);
            cout.fill('.');
            cout << left << f_name << " | ";

            cout.width(4);
            cout.fill(' ');
            cout << right << f_cal << " | ";

            // ternary operator to change f_when into designated string;
            const char* mealtime = (f_when == 1) ? "Breakfast" :
                                   (f_when == 2) ? "Lunch" :
                                   (f_when == 3) ? "Dinner" :
                                   (f_when == 4) ? "Snack" :
                                   "Bedtime";
            cout.width(11);
            cout.fill(' ');
            cout << left << mealtime << '|' << endl;
        } else {
            cout << "| ";
            line (30, 'x');
            cout << " | ";
            line (4,'x');
            cout << " | ";
            line(10,'x');
            cout << " |" << endl;
        }
    }

    bool Food::isValid()const {
        return f_name[0] != '\0' && f_cal > 0;
    }

    int Food::calorieCount()const {
        return f_cal; 
    }
        
}