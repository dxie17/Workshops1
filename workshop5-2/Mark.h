// Workshop: 5
// Part: 2
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/06/30
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
///////////////////////////////////////////////////
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds
{
    class Mark
    {
        int m_mark;
        char m_grade;
        double m_scale;
        bool isValid;
        void setEmpty();
        void setGradeAndScale();
    public:
        Mark();
        Mark(int mark);
        operator bool() const;
        operator char() const;
        operator int() const;
        operator double() const;
        Mark& operator =(int mark);
        Mark& operator +=(int addMark);
        friend int operator +=(int& addMark, const Mark& markA);
    };
}
#endif // SDDS_MARK_H_