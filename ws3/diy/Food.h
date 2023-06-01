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
        int calorieNum;
        int consumptionTime;
        
        void display()const;
    }
}
#endif // !SDDS_FOOD_H
