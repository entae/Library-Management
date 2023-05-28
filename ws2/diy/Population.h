#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#define DATAFILE "PCpopulations.csv"
namespace sdds {
   
   struct Postal {
      char* p_code;
      int p_population;
   };
    void sort();
    bool load(Postal &p);
    bool load(const char filename[]);
    void display(const Postal& pos);
    void display();
    void deallocateMemory();
    
}
#endif // SDDS_POPULATION_H_