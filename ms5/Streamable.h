// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: Aug 6, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_

#include <iostream> 
namespace sdds {
   //An Interface is an abstract base class with only pure virtual functions.
    class Streamable {
    public:
        virtual std::ostream& write(std::ostream& ostr)const = 0;

        virtual std::istream& read(std::istream& istr) = 0;

        virtual bool conIO(std::ios& io)const = 0;

        virtual operator bool()const = 0;

        virtual ~Streamable() = default;
    };

    std::ostream& operator<<(std::ostream& os, const Streamable& stream);

    std::istream& operator>>(std::istream& is, Streamable& stream);
}
#endif // !SDDS_STREAMABLE_H_