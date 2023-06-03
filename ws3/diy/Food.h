// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: 
// I have done all the coding by myself 
// and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H
namespace sdds {

    class Food {
        char f_name[31];
        int f_cal;
        int f_when;

        void setName(const char* name);

    public:
        void setEmpty();
        void set(const char* name, int calorie, int mealtime);
        void display()const;
        bool isValid()const;
        int calorieCount()const;
    };
}

#endif // !SDDS_FOOD_H
