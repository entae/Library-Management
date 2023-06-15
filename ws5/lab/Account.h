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
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator ~()const;

      Account& operator=(int number);
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