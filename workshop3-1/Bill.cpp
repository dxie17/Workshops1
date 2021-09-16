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
#include "Bill.h"
#include "Item.h"
using namespace std;
namespace sdds
{
    double Bill::totalTax()const {
        int i = 0;
        double totaltax= 0.0;
        for (i = 0; i < m_noOfItems; i++)
            totaltax += m_items[i].tax();
        return totaltax;
    }

    double Bill::totalPrice()const {
        int i = 0;
        double totalprice = 0.0;
        for (i = 0; i < m_noOfItems; i++)
            totalprice += m_items[i].price();
        return totalprice;
    }

    void Bill::Title()const {
        cout<<"+--------------------------------------+"<<endl;
        if (isValid()) {
            cout << "| ";
            cout.unsetf(ios::right);
            cout.setf(ios::left);
            cout.fill(' ');
            cout.width(36);
            cout << m_title;
            cout <<" |" << endl;
        }
        else cout << "| Invalid Bill                         |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
        return;
    }

    void Bill::footer()const {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid()) {
            cout << "|                Total Tax: ";
            cout.fill(' ');
            cout.setf(ios::fixed);
            cout.width(10);
            cout.precision(2);
            cout.unsetf(ios::left);
            cout.setf(ios::right);
            cout<< totalTax()<<" |"<<endl;
            cout << "|              Total Price: ";
            cout.width(10);
            cout << totalPrice() << " |" << endl;
            cout << "|          Total After Tax: ";
            cout.width(10);
            cout << totalTax()+totalPrice() << " |" << endl;
        }
        else cout << "| Invalid Bill                         |" << endl;
        cout << "+--------------------------------------+" << endl;
        return;
    }

    void Bill::setEmpty() {
        m_title[0] = '\0';
        m_items = nullptr;
        return;
    }

    bool Bill::isValid()const {
        bool ok = false;
        int i = 0;
        if (m_title[0] != 0 && m_items != nullptr) {
            for (i = 0; i < m_noOfItems && (m_items + i) != nullptr; i++);
            if (i == m_noOfItems&& m_noOfItems== m_itemsAdded) ok = true;
        }
        return ok;
    }

    void Bill::init(const char* title, int noOfItems) {
        if (title != nullptr && noOfItems > 0) {
            m_itemsAdded = 0;
            m_noOfItems = noOfItems;
            strnCpy(m_title, title,36);
            m_items = new Item[m_noOfItems];
            for (int i = 0; i < noOfItems; i++)
                m_items[i].setEmpty();
        }
        else setEmpty();
        return;
    }

    bool Bill::add(const char* item_name, double price, bool taxed) {
        bool ok = false;
        if (item_name != nullptr && price > 0 && m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            ok = true;
        }
        m_itemsAdded++;
        return ok;
    }

    void Bill::display()const {
        Title();
        int i = 0;
        for (i = 0; i < m_noOfItems; i++) m_items[i].display();
        footer();
        return;
    }

    void Bill::deallocate() {
        delete[] m_items;
        m_items = nullptr;
        return;
    }
}