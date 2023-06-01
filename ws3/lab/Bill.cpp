// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: Jun 1, 2023
// I have done all the coding by myself 
// and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

    // returns the total tax applied to the Items
      double Bill::totalTax()const {
        double sumTax = 0.0;
        int i;
        //loops through the array and sums up the values returned with 'double Item::tax()const'
        for (i = 0; i < m_itemsAdded; i++){
          sumTax += m_items[i].tax();
        }
        return sumTax;
      }

    // returns the sum of prices of Items
      double Bill::totalPrice()const {
        double sumPrice = 0.0;
        int i;
        //loops through the array and sums up the values returned with 'double Item::price()const'
        for (i = 0; i < m_itemsAdded; i++) {
          sumPrice += m_items[i].price();
        }
        return sumPrice;
      } 
    // Prints the title of the shopping list
      void Bill::Title()const {
        cout << '+';
        line(38,'-');
        cout.setf(ios::left);
        cout << '+' << endl;

        //Valid if Item name and price hold valid values 
        if(isValid()){
          cout << "| ";
          cout.width(36);
          cout << left << m_title;
          cout << " |" << endl;
        } else { 
          cout << "| Invalid Bill";
          line(24,' ');       
          cout << " |" << endl;
        }

        cout << '+';
        line(22,'-');
        cout << '+';
        line(9,'-');
        cout << '+';
        line(5,'-');
        cout << '+' << endl;

        cout << "| Item Name";
        line(11,' ');
        cout << " | Price   + Tax |" << endl;

        cout << '+';
        line(22,'-');
        cout << '+';
        line(9,'-');
        cout << '+';
        line(5,'-');
        cout << '+' << endl;

      }   

    // prints the footer containing total tax, price and total price after tax
      void Bill::footer()const{
        cout << '+';
        line(22,'-');
        cout << '+';
        line(9,'-');
        cout << '+';
        line(5,'-');
        cout << '+' << endl;

        //sets the tax, price, and total values
        double tax = totalTax();
        double price = totalPrice();
        double total = tax + price;

        if (isValid()) {
          cout << '|';
          line(16,' ');
          cout << "Total Tax:";
          cout.width(11);
          cout.precision(2);
          cout.setf(ios::fixed);
          cout.setf(ios::right);
          cout << tax << " |" << endl;
          
          cout << '|';
          line(14,' ');
          cout << "Total Price:";
          cout.width(11);
          cout.precision(2);
          cout << price << " |" << endl;
        
          cout << '|';
          line(10,' ');
          cout << "Total After Tax:";
          cout.width(11);
          cout.precision(2);
          cout << total << " |" << endl;
        } else {
          cout << "| Invalid Bill";
          line(25, ' ');
          cout << '|' << endl;
        }
        cout << '+';
        line(38, '-');
        cout << '+' << endl;
      }
    // sets the Bill to an emtpy state
      void Bill::setEmpty(){
        m_title[0] = '\0';
        m_items = nullptr;
      }    
    // returns true is the Bill and all of its Items are valid
      bool Bill::isValid()const{
        bool tf = true;
        //checks for whether m_title and m_items have have non-empty values
        if (m_title[0] == '\0' || m_items == nullptr) {
          tf = false;
        }
        //loop for checking that all incidents in the array meet the above criteria
        for (int i=0; i < m_noOfItems; i++) {
          if (!m_items[i].isValid()) {
            tf = false;
          }
        }
        return tf;
      }
   
      void Bill::init(const char* title, int noOfItems){
        int i;
        //checks that both title and noOfItems are non-empty values
        if (title != nullptr && noOfItems > 0) {
          m_noOfItems = noOfItems;
          m_itemsAdded = 0;
          int titleLength = strLen(title);
          //limits the length of the titleLength 
          if(titleLength > 36) {
            titleLength = 36;
          }
          strnCpy(m_title, title, titleLength);
          m_title[titleLength] = '\0'; //adding null-termination at end of string
          //dynamically allocating an array of Items pointed by m_items, length of array is m_noOfItems
          m_items = new Item[m_noOfItems];
          //sets each index in the array to a safe state
          for (i = 0; i < m_noOfItems; i++) {
            m_items[i].setEmpty();
          } 
        } else {
          //sets Bill to an empty state if arguments are invalid
          setEmpty();
        }
      }

      bool Bill::add(const char* item_name, double price, bool taxed){
        bool tf = false;
        //checks if number of added items is less than the m_items array
        if (m_itemsAdded < m_noOfItems) {
          //sets the next subject to the corresponding argument values
          m_items[m_itemsAdded].set(item_name, price, taxed);
          m_itemsAdded++;
          tf = true;
        }
        return tf;
      }

      void Bill::display()const{
        int i;
        Title();
        // loops through each item and displays in format coded in Item.cpp
        for (i=0; i < m_noOfItems; i++) {
          m_items[i].display();
        }

        footer();
      }

      void Bill::deallocate(){
        //if m_items is not an empty state deallocates the m_items arrays and sets the pointers to null.
        if (m_items != nullptr) {
          delete[] m_items;
          m_items = nullptr;
          m_noOfItems = 0;
          m_itemsAdded = 0;
        }
      }
}