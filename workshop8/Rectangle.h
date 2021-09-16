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
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include"LblShape.h"
namespace sdds{
    class Rectangle:public LblShape{
        int m_width;
        int m_height;
    public:
        Rectangle(); 
        Rectangle(const char* label,int width,int height);
        void getSpecs(std::istream& istr);
        void draw(std::ostream& ostr)const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Rectangle& A);
    std::istream& operator>>(std::istream& istr, Rectangle& A);
}
#endif