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
#include<iostream>
#include "Shape.h"
using namespace std;
namespace sdds{

    void Shape::draw(std::ostream& ostr)const {
    
    }

    void Shape::getSpecs(std::istream& istr) {

    }
    std::ostream& operator<<(std::ostream& ostr, const Shape& A)
    {
        A.draw(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, Shape& A)
    {
        A.getSpecs(istr);
        return istr;
    }

    void Shape::strCpy(char* des, const char* src) {
        int len_src = 0;
        for (len_src = 0; src[len_src] != '\0'; len_src++);
        des[len_src] = { 0 };
        for (int i = 0; i < len_src; i++)des[i] = src[i];
        des[len_src] = '\0';
        return;
    }

    int Shape::strLen(const char* s) {
        int len = 0;
        for (len = 0; s[len] != '\0'; len++);
        return len;
    }
}