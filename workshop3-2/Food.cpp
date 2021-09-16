// Workshop: 3
// Part: 2
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/06/12
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
///////////////////////////////////////////////////
#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;
namespace sdds
{
    void Food::setName(const char* name) {
        if (name != nullptr)
            strnCpy(m_foodName, name, 30);
        else
            m_foodName[0] = '\0';
        return;
    }

    void Food::setEmpty() {
        m_foodName[0] = '\0';
        m_calories = 0;
        m_timeWhen = 0;
        return;
    }

    void Food::set(const char* name, int calories, int timeWhen) {
        setName(name);
        if (m_foodName[0] == '\0' || calories <= 0) setEmpty();
        else {
            strnCpy(m_foodName, name, 30);
            m_calories = calories;
            m_timeWhen = timeWhen;
        }
        return;
    }

    void Food::display()const {
        if (isValid()) {
            cout << "| ";
            cout.unsetf(ios::right);
            cout.setf(ios::left);
            cout.width(30);
            cout.fill('.');
            cout << m_foodName << " | ";
            cout.unsetf(ios::left);
            cout.setf(ios::right);
            cout.fill(' ');
            cout.setf(ios::fixed);
            cout.width(4);
            cout.precision(2);
            cout << m_calories << " | ";
            cout.unsetf(ios::right);
            cout.setf(ios::left);
            cout.width(10);
            cout.fill(' ');
            if (m_timeWhen==1) cout << "Breakfast";
            else if(m_timeWhen == 2) cout << "Lunch";
            else if (m_timeWhen == 3) cout << "Dinner";
            else if (m_timeWhen == 4) cout << "Snack";
            cout<< " |" << endl;
        }
        else
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
        return;
    }

    bool Food::isValid()const {
        return  m_foodName[0] != '\0' && m_calories > 0;
    }

    int Food::calories()const {
        return m_calories;
    }
}