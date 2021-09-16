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
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include"Shape.h"
namespace sdds{

    class LblShape: public Shape{
        char *m_label;
    protected:
        const char *label()const;
    public:
        LblShape();
        LblShape(const char *label);
        virtual void draw(std::ostream& ostr)const = 0;
        virtual void getSpecs(std::istream& istr);
        ~LblShape();
        LblShape(const LblShape*)= delete;
        LblShape & operator =(const LblShape*) = delete;
    };
}

#endif