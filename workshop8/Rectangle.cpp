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
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include "Rectangle.h"
#include "Shape.h"
using namespace std;
namespace sdds{

    Rectangle::Rectangle():LblShape::LblShape(){
        m_width = 0;
        m_height = 0;
    }
    Rectangle::Rectangle(const char* label, int width, int height) : LblShape::LblShape(label) {
        m_width = 0;
        m_height = 0;
        if (width >= Shape::strLen(LblShape::label()) + 2 && height >= 3 && label != nullptr) {
            m_width = width;
            m_height = height;
        }
        else label = nullptr;
    }

    void Rectangle::getSpecs(std::istream& istr) {
        LblShape::getSpecs(istr);
        istr >> m_width;
        string s;
        getline(istr, s, ',');
        istr >> m_height;
        istr.ignore(1000, '\n');
    }

    void Rectangle::draw(std::ostream& ostr) const {
        int len = m_width - 2;
        if (len > 0 && m_height > 0) {
            char oldFill = ostr.fill('-');
            for (int i = 0; i < m_height; i++) {
                if (i == 0) {
                    ostr << '+';
                    cout.width(len);
                    ostr << "";
                    ostr << '+' << endl;
                }
                else if (i == 1) {
                    ostr.setf(ios::left);
                    ostr << '|';
                    ostr.fill(oldFill);
                    cout.width(len);
                    ostr << LblShape::label() <<'|'<< endl;
                }
                else if (i > 1 && i< m_height -1){
                    ostr << '|';
                    cout.width(len);
                    ostr << "";
                    ostr << '|' << endl;
                }
                else if (i == m_height - 1) {
                    ostr.fill('-');
                    ostr << '+';
                    cout.width(len);
                    ostr << "";
                    ostr << '+';
                }
            }
            ostr.fill(oldFill);
        }
    }

    std::ostream& operator<<(std::ostream& ostr, const Rectangle& A)
    {
        A.draw(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, Rectangle& A)
    {
        A.getSpecs(istr);
        return istr;
    }
}