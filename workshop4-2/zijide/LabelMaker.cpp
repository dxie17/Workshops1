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
//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"  
#include "LabelMaker.h"
using namespace std;
namespace sdds
{
    void LabelMaker::setDefault() {
        m_noOfLabels=0;
        m_Label=nullptr;
        return;
    }

    void LabelMaker::setLabels(const int noOfLabels) {
        m_noOfLabels = noOfLabels;
        m_Label = new Label[m_noOfLabels];
    }

    LabelMaker::LabelMaker() {
        setDefault();
    }

    LabelMaker::LabelMaker(int noOfLabels) {
        setDefault();
        setLabels(noOfLabels);
        return;
    }

    LabelMaker::~LabelMaker() {
        for (int i = 0; i < m_noOfLabels; i++) m_Label[i].~Label();
        delete[] m_Label;
    }

    void LabelMaker::readLabels() {
        cout << "Enter " << m_noOfLabels << " labels:" << endl;
        for (int i = 0; i < m_noOfLabels; i++) {
            cout << "Enter label number " << i + 1 << endl << "> ";
            m_Label[i].readLabel();
        }
        return;
    }

    void LabelMaker::printLabels()const {
        for (int i = 0; i < m_noOfLabels; i++) {
            m_Label[i].printLabel();
            cout << endl;
        }
        return;
    }
}