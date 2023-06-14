// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: Jun 13, 2023
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
//public:
/*
The Account class can be in three different states:
Invalid Empty State
   An account is in an invalid state if invalid information is fed into the account. 
   In these types of situations the account number is set to -1 and the balance is set to 0. 
   The Account object in this case is rendered inactive and can not be used anymore.
New
   An account is considered New or not set when it is just created and the account number is not assigned yet. 
   This state of the Account class is flagged by setting the account number (m_number) to 0.
Valid
   An Account is considered valid if the account number is a 5 digit integer with a zero or positive balance.
*/

//returns true if the account is valid and otherwise false. 
   Account::operator bool()const {
      return m_number >= 10000 && m_number <= 99999 
         && m_balance >= 0;
   }
//returns the account number.  
   Account::operator int()const {
      return m_number;
   }
//returns the balance value
   Account::operator double()const {
      return m_balance;
   }
//returns true is the account is new or not set 
//(i.e. if the account number is zero), 
//otherwise it will return false.
   bool Account::operator ~()const{
      return m_number == 0;
   }

   Account& Account::operator=(int number) {
      if (operator~()) {
         if (number >= 10000 && number <= 99999) {
            m_number = number;
         } else {
            setEmpty();
         }
      }
      return *this;
   }

   Account& Account::operator=(Account& src) {
      if (operator~() && (bool)src) {
         m_number = src.m_number;
         m_balance = src.m_balance;
         src.m_number = 0;
         src.m_balance = 0.0;
      }
      return *this;
   }

   Account& Account::operator+=(double value) {
      if (*this && value >= 0) {
         m_balance += value;
      }
      return *this;
   }

   Account& Account::operator-=(double value) {
      if (*this && value > 0 && m_balance >= value) {
         m_balance -= value;
      }
      return *this;
   }

   Account& Account::operator<<(Account& src) {
      if(this != &src && (bool)src && *this) {
         m_balance += src.m_balance;
         src.m_balance = 0.0;
      }
      return *this;
   }

   Account& Account::operator>>(Account& src) {
      src << *this;
      return *this;
   }

  //Binary helper operators
   double operator+(const Account& A,const Account& B) {
      double sum = 0.0;
      if ((bool)A && (bool)B) {
         sum = (double)A + (double)B;
      }
      return sum;
   }

   double operator+=(double& dbl,const Account& B) {
      return dbl += (double)B;
   }

}