// Workshop: 8
// Part: 1
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/07/19
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
///////////////////////////////////////////////////
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
namespace sdds{

    class Shape{
    public:
        virtual void draw(std::ostream& ostr)const = 0;
        virtual void getSpecs(std::istream& istr) = 0;
        virtual ~Shape() {}
        void strCpy(char* des, const char* src);
        int strLen(const char* s);
    };
    std::ostream& operator<<(std::ostream& ostr, const Shape& A);
    std::istream& operator>>(std::istream& istr, Shape& A);
}

#endif