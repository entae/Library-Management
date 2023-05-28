#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#define DATAFILE "PCpopulations.csv"
namespace sdds {
   
   struct Postal {
      char* p_code;
      double p_population;
   };
    bool load();
    void display(void);
    void deallocateMemory();
    
}
#endif // SDDS_POPULATION_H_