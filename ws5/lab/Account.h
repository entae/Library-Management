// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: Jun 13, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
   //Account constructors (implemented):
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
//*To be implemented:
    //returns true if the account is valid and otherwise false. 
      //This operator can not modify the account object.
      operator bool() const;
    //returns the account number.  
      operator int() const;
    //returns the balance value
      operator double() const;
    //returns true is the account is new or not set 
      //(i.e. if the account number is zero), 
      //otherwise it will return false.
      bool operator ~()const;
//Binary member operators
    //Note: All the binary member operators will not take any action 
    //if the account is in an invalid state.
      Account& operator=(int num);
      Account& operator=(Account&);
      Account& operator+=(double balance);
      Account& operator-=(double value);

      Account& operator<<(Account& src);
      Account& operator>>(Account& src);

   };
  //Binary helper operators
   double operator+(const Account& A, const Account& B);
   double operator+=(double& dbl,const Account& B);
}
#endif // SDDS_ACCOUNT_H_