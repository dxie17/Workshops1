// Workshop: 5
// Part: 1
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/06/23
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds
{
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }

    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }

    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }

    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }   
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    Account::operator bool() const {
        return m_number >= 10000 && m_number <= 99999 && m_balance>=0;
    }

    Account::operator int() const {
        return m_number;
    }
    Account::operator double() const {
        return m_balance;
    }

    bool Account::operator ~() const {
        return m_number == 0;
    }

    Account &Account::operator =(int number) {
        if (~(*this) && number >= 10000 && number <= 99999) m_number = number;
        else if (m_number < 0) setEmpty();
        return *this;
    }

    Account &Account::operator =(Account &accA) {
        if (m_number == 0 && bool(accA)) {
            m_number = accA.m_number;
            m_balance = accA.m_balance;
            accA.m_number = 0;
            accA.m_balance = 0.0;
        }
        return *this;
    }

    Account &Account::operator +=(double balance) {
        if (balance > 0 && *this) m_balance += balance;
        return *this;
    }

    Account &Account::operator -=(double balance) {
        if (balance > 0 && *this && balance<= m_balance) m_balance -= balance;
        return *this;
    }

    Account &Account::operator <<(Account& accA) {
        if (*this && accA && this->m_number!= accA.m_number) {
            m_balance += accA.m_balance;
            accA.m_balance = 0;
        }
        return *this;
    }

    Account &Account::operator >>(Account& accA) {
        if (*this && accA && this->m_number != accA.m_number) {
            accA.m_balance += m_balance;
            m_balance = 0;
        }
        return *this;
    }

    double operator+(const Account &accA, const Account &accB)
    {
        double balance = 0.0;
        if (accA && accB) balance = double(accA) + double(accB);
        return balance;
    }

    double operator+=(double & balance, const Account& accA)
    {
        if (balance >= 0 && accA) balance += double(accA);
        return balance;
    }
}