// Final Project Milestone 1 
// Date Module
// File	Date.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name: In Tae Chung,  Date: July 15, 2023     Reason
// 128 958 220 ; itchung@myseneca.ca
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>

namespace sdds {
   const int NO_ERROR = 0;
   const int CIN_FAILED = 1;
   const int YEAR_ERROR = 2;
   const int MON_ERROR = 3;
   const int  DAY_ERROR = 4;
   const char DATE_ERROR[5][16] = {
      "No Error",
      "cin Failed",
      "Bad Year Value",
      "Bad Month Value",
      "Bad Day Value"
   };
   const int  MIN_YEAR = 1500;

   //A class that encapsulates year, and month and day values for Date stamp, comparison and Date IO purposes.
   class Date {
   private:
      int m_year;
      int m_mon;
      int m_day;
      int m_ErrorCode;
      int m_CUR_YEAR;
      int daysSince0001_1_1()const; // returns number of days passed since the date 0001/1/1
      bool validate();             /* validates the date setting the error code and then returning the result 
                                    true, if valid, and false if invalid.*/
      void errCode(int theErrorCode);           // sets the error code value
      int systemYear()const;       // returns the current system year
      bool bad()const;             // return true if the Date is in an erroneous state
      int mdays()const;            // returns the number of days in current month (the month stored in m_mon attribute)
      void setToToday();           // sets the date to the current date (system date)
   public:
      Date();                      // creates a date with current date
      Date(int year, int mon, int day); /* create a date with assigned values
                                         then validates the date and sets the 
                                         error code accordingly */
      int errCode()const;         // returns the error code or zero if date is valid
      const char* dateStatus()const;  // returns a string corresponding the current status of the date
      int currentYear()const;         // returns the m_CUR_YEAR attribute value;

//functions to implement:
      /**
      * reads a date from the console in the following format YYYY/MM/DD
      * @param is - input instance to gather year,mon,day
      * @returns - formatted istream instance
      */
      std::istream& read(std::istream& is = cin); 

      /**
      * If the Date object is in a "bad" state (is invalid) print the "dateStatus()". 
      * Otherwise, the function writes the date in the specified format using ostream.
      * @param os - ostream set to print formatted YYYY/MM/DD
      * @returns - formatted ostream instance
      */
      std::ostream& write(std::ostream& os = cout)const;  

      //Use the return value of the daysSince0001_1_1() method to compare the two dates
      bool operator==(const Date& d)const;
      bool operator!=(const Date& d)const;
      bool operator>=(const Date& d)const;
      bool operator<=(const Date& d)const;
      bool operator<(const Date& d)const;
      bool operator>(const Date& d)const;

      /**
      * Returns the difference between two Dates in days
      * @param d - date being subtracted from after comparing to daysSince0001_1_1();
      * @returns - difference in days 
      */
      int operator-(const Date& d)const;

      //return true if the date is valid and false if not
      operator bool()const; 

   };

   //Overloads of insertion and extraction operators to call write and read method of Date
   std::ostream& operator<<(std::ostream& os, const Date& RO);
   std::istream& operator>>(std::istream& is, Date& RO);

}
#endif // !SDDS_DATE_H__