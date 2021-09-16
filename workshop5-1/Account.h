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
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds
{
    class Account
    {
        int m_number;
        double m_balance;
        void setEmpty();
    public:
        Account();
        Account(int number, double balance);
        std::ostream& display()const;
        operator bool() const;
        operator int() const;
        operator double() const;
        bool operator ~() const;
        Account &operator =(int number);
        Account &operator =(Account & accA);
        Account &operator +=(double balance);
        Account &operator -=(double balance);
        Account &operator <<(Account& accA);
        Account &operator >>(Account& accA);
        friend double operator +(const Account &accA, const Account &accB);
        friend double operator +=(double & balance, const Account& accA);
    };


}
#endif // SDDS_ACCOUNT_H_