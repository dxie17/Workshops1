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
#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"
namespace sdds
{
    class CalorieList
    {
        Food * m_food;
        int m_noOfFood;
        int m_foodAdded;
        int totalCalories()const;
        void Title()const;
        void footer()const;
        void setEmpty();
        bool isValid()const;
    public:
        void init(int noOfFood);
        bool add(const char* foodName, int calories, int timeWhen);
        void display()const;
        void deallocate();
    };
}
#endif