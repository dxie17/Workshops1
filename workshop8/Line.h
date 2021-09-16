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
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include"LblShape.h"
namespace sdds{

    class Line:public LblShape{
        int m_length;
    public:
        Line();
        Line(const char* label, int length);
        void getSpecs(std::istream& istr);
        void draw(std::ostream& ostr)const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Line& A);
    std::istream& operator>>(std::istream& istr, Line& A);
}

#endif