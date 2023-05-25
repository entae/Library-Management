#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;

   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee &m) {
        bool ok = false;
        char name[128];
    
        if(read(m.m_empNo) && read(m.m_salary) && read(name)) { //if reading of employee number, salay and name are successful
            m.m_name = new char[strLen(name)+1]; //while keeping the address in the name of the Employee Referencewhich is the size of the name +1
            strCpy(m.m_name,name); //copy the name into the newly allocated memory
            ok = true;
        }
      return ok;
   }

   // TODO: Finish the implementation of the 0 arg load function 
   bool load(void) {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) {
         noOfEmployees = noOfRecords(); //Set the noOfEmployees to the number of recoreds in the file.
         employees = new Employee[noOfEmployees]; //dynamically allocate an array of employees into the global Employee pointer; "employees" to the size of the noOfEmployees.
         for (i=0; i < noOfEmployees;) { 
            i += load(employees[i]); //In a loop load the employee records from the file into the dynamic array.
         }
         if (i != noOfEmployees) { //When the number of the records does not match the number of reads
            cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
         } else {
            ok = true;            
         }
         closeFile();
      } else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display(const Employee& m) {
      cout << m.m_empNo << ": " << m.m_name << ", " << m.m_salary << endl;
   }

   void display(void) {
      cout << "Employee Salary report, sorted by employee number" << endl;
      cout << "no- Empno, Name, Salary" << endl;
      cout << "------------------------------------------------" << endl;
      sort();
      for (int i = 0; i < noOfEmployees; i++) {
         cout << i+1 << "- ";
         display(employees[i]);
      } 
   }

   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory() {
      if (employees != nullptr) {
        for (int i = 0; i < noOfEmployees; i++) {
            delete[] employees[i].m_name;
        }
        delete[] employees;
        employees = nullptr;
        noOfEmployees = 0;
      }
   }

}