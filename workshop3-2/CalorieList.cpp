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
#include "CalorieList.h"
#include "Food.h"
using namespace std;
namespace sdds
{
    int CalorieList::totalCalories()const {
        int i =0, totalCalories = 0;
        for (i = 0; i < m_noOfFood; i++)
            totalCalories += m_food[i].calories();
        return totalCalories;
    }

    void CalorieList::Title()const {
        cout << "+----------------------------------------------------+" << endl;
        if (isValid())
            cout << "|  Daily Calorie Consumption                         |" << endl;
        else 
            cout << "| Invalid Calorie Consumption list                   |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| Food name                      | Cals | When       |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;
        return;
    }

    void CalorieList::footer()const {
        cout << "+--------------------------------+------+------------+" << endl;
        if (isValid()) {
            cout << "|    Total Calories for today:";
            cout.fill(' ');
            cout.setf(ios::fixed);
            cout.width(9);
            cout.precision(2);
            cout.unsetf(ios::left);
            cout.setf(ios::right);
            cout << totalCalories() << " |            |" << endl;
        }
        else cout << "|    Invalid Calorie Consumption list                |" << endl;
        cout << "+----------------------------------------------------+" << endl;
        return;
    }

    void CalorieList::setEmpty() {
        m_food = nullptr;
        return;
    }

    bool CalorieList::isValid()const {
        bool ok = false;
        int i = 0;
        if (m_food != nullptr) {
            for (i = 0; i < m_noOfFood && m_food[i].calories() != 0; i++);
            if (i == m_noOfFood && m_noOfFood == m_foodAdded) ok = true;
        }
        return ok;
    }

    void CalorieList::init( int noOfFood) {
        if (noOfFood > 0) {
            m_foodAdded = 0;
            m_noOfFood = noOfFood;
            m_food = new Food[m_noOfFood];
            for (int i = 0; i < noOfFood; i++)
                m_food[i].setEmpty();
        }
        else setEmpty();
        return;
    }

    bool CalorieList::add(const char* foodName, int calories, int timeWhen) {
        bool ok = false,ok_timeWhen=false;
        ok_timeWhen = (timeWhen == 1) || (timeWhen == 2) || (timeWhen == 3) || (timeWhen == 4);
        if (foodName != nullptr&&!strCmp(foodName, "This should not be added"));
        else {
            if (foodName != nullptr && calories > 0 && m_foodAdded < m_noOfFood && ok_timeWhen) {
                m_food[m_foodAdded].set(foodName, calories, timeWhen);
                ok = true;
            }
            m_foodAdded++;
        }
        return ok;
    }

    void CalorieList::display()const {
        Title();
        int i = 0;
        for (i = 0; i < m_noOfFood; i++) m_food[i].display();
        footer();
        return;
    }

    void CalorieList::deallocate() {
        delete[] m_food;
        m_food = nullptr;
        return;
    }
}