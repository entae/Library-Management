#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"
using namespace std;

namespace sdds {

    int noOfPostal;
    int noOfPopulation;
    Postal* pos;

    bool load(Postal &p) {
        bool ok = false;
        char name[128];
        if (read(name) && read(p.p_population)) {
            p.p_code = new char[strLen(name) + 1];
            strCpy(p.p_code, name);
            ok = true;
        }
        return ok;
    }
//Loads data from a file, and returns true if data was successfully loaded, false otherwise. 
//This function receives as a parameter the name of the file
    //If the file cannot be found, print the following error message:
    // Could not open data file: FILENAME<ENDL>

    //If the file doesn't have a correct content, print:
    // Error: incorrect number of records read; the data is possibly corrupted!<ENDL>
    bool load(const char filename[]) {
        bool ok = false;
        int i = 0;

        if (openFile(filename)) {
            noOfPostal = noOfRecords();
            pos = new Postal[noOfPostal];

            for (i = 0; i < noOfPostal;) {
                i += load(pos[i]);
            }

            if ( i != noOfPostal) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
            }
            else {
                ok = true;
            }
            closeFile();
        } else {
            cout << "Could not open data file: " << filename << endl;
        }
        return ok;
    }

    void sort() {
        int i, j;
        Postal temp;
        for (i = 1; i < noOfPostal; i++) {
            temp = pos[i];
            for (j = i - 1; j >= 0 && pos[j].p_population > temp.p_population; j--) {
                pos[j + 1] = pos[j];
            }
            pos[j + 1] = temp;
        }
    }

    void display(const Postal& pos) {
        cout << pos.p_code << ":  " << pos.p_population << endl;
    }

     void display() {
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort();
        for (int i = 0; i < noOfPostal; i++)
        {
            cout << i + 1 << "- ";
            display(pos[i]);
            noOfPopulation += pos[i].p_population;
        }

        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << noOfPopulation << endl;
    }

//a function with no parameters that return nothing and deallocate all dynamic memory used by the program.
    void deallocateMemory() {
      if (pos != nullptr) {
        for (int i = 0; i < noOfPostal; i++) {
            delete[] pos[i].p_code;
            pos[i].p_code = nullptr;
        }
        delete[] pos;
        pos = nullptr;
      }
   }

}