// Workshop: 3
// Part: 1
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/06/09
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
///////////////////////////////////////////////////
#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds
{
    void Item::setName(const char* name) {
        if (name!=nullptr)
            strnCpy(m_itemName, name,20); 
        else
            m_itemName[0] = '\0';
        return;
    }

    void Item::setEmpty() {
        m_itemName[0] = '\0';
        m_price = 0.0;
        return;
    }

    void Item::set(const char* name, double price, bool taxed) {
        setName(name);
        if (m_itemName[0]=='\0' || price <= 0.0)setEmpty();
        else {
            strnCpy(m_itemName, name,20);
            m_price = price;
            m_taxed = taxed;
        }
        return;
    }

    void Item::display()const {
        if (isValid()) {
                cout << "| ";
                cout.unsetf(ios::right);
                cout.setf(ios::left);
                cout.width(20);
                cout.fill('.');
                cout << m_itemName << " | ";
                cout.unsetf(ios::left);
                cout.setf(ios::right);
                cout.fill(' ');
                cout.setf(ios::fixed);
                cout.width(7);
                cout.precision(2);
                cout << m_price << " | ";
                if (m_taxed) cout << "Yes" << " |" << endl;
                else cout << "No" << "  |" << endl; 
        }
        else
            cout<<"| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |"<<endl;
        return;
    }

    bool Item::isValid()const {
        return  m_itemName[0] != '\0' && m_price != 0.0;
    }

    double Item::price()const {  
        return m_price;
    }

    double Item::tax()const {
        return m_taxed ? m_price * 0.13 : 0.0;
    }
}