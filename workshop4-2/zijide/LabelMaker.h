// Workshop: 4
// Part: 2
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/06/20
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
///////////////////////////////////////////////////
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"
namespace sdds
{
    class LabelMaker
    {
        int m_noOfLabels;
        Label* m_Label;
        void setDefault();
        void setLabels(const int noOfLabels);
    public:
        LabelMaker();
        LabelMaker(int noOfLabels);
        ~LabelMaker();
        void readLabels();
        void printLabels()const;
    };

}

#endif