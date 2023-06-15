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
      //if instance is not new, nothing happens
      if (operator~()) {
         //value of number is copied if within range(valid)
         if (number >= 10000 && number <= 99999) {
            m_number = number;
         } else {
            //if not within range, set to invalid state
            setEmpty();
         }
      }
      return *this;
   }

   Account& Account::operator=(Account& src) {
      //if instance is new && src is valid
      //copies src values into *this and src is set to zero
      if (operator~() && src) {
         m_number = src.m_number;
         m_balance = src.m_balance;
         src.m_number = 0;
         src.m_balance = 0.0;
      }
      return *this;
   }

   Account& Account::operator+=(double value) {
      //if *this is valid and value is a non-negative value
      if (*this && value >= 0) {
         //value is added to the value of m_balance
         m_balance += value;
      }
      return *this;
   }

   Account& Account::operator-=(double value) {
      //if *this is valid and value is positive
      //and subtraction won't end in a negative value
      if (*this && value > 0 && m_balance >= value) {
         //value is subtracted from m_balance
         m_balance -= value;
      }
      return *this;
   }

   Account& Account::operator<<(Account& src) {
      //if this and &src are not the same instance
      // && src and &src are both valid
      if(this != &src && (bool)src && *this) {
         //argument balance is added to instance balance
         //and argument balance is set to zero
         m_balance += src.m_balance;
         src.m_balance = 0.0;
      }
      return *this;
   }

   Account& Account::operator>>(Account& src) {
      //the position of src and instance object are switched from <<
      src << *this;
      return *this;
   }

//Binary helper operators:

   //
   double operator+(const Account& A,const Account& B) {
      double sum = 0.0;
      //if instances A and B are both valid
      if (A && B) {
         //double value is the sum of A and B's balances
         sum = (double)A + (double)B;
      }
      //if either instance is invalid 0.0 is returned
      return sum;
   }

   double operator+=(double& dbl,const Account& B) {
      return dbl += (double)B;
   }

}