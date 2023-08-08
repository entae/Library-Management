// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: Aug 7, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

#include "Collection.h"

namespace sdds {
    /// <summary>
    /// T must be compatible with == operator
    /// K should be compatible with being compared with elements in the T array with the == operator
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="collection">Reference to an array of types, unmodifiable</param>
    /// <param name="array">array of objects of template type</param>
    /// <param name="size">number of elements in the array</param>
    /// <typeparam name="K"></typeparam>
    /// <param name="key">value to search for within array</param>
    /// <returns>true if a match between the K object and an element in the array T are found</returns>
    template <typename T, typename K>
    bool search(Collection<T>& collection, const T* array, int size, const K& key ) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (array[i] == key) {
                collection.add(array[i]);
                found = true;
            }
        }
        return found;
    }

    /// <summary>
    /// T must be compatible with << operator
    // index operator[] must be defined for T
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="title">title of the list to be printed</param>
    /// <param name="array">constant array of objects of template type</param>
    /// <param name="size">number of elements in the array</param>
    /// <returns>lists all elements of an array</returns>
    template <typename T>
    void listArrayElements(const char* title, const T* array, int size) {
        std::cout << title << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << i+1 << ": " << array[i] << std::endl;
        }
    }
}

#endif // !SDDS_SEARCHNLIST_H_