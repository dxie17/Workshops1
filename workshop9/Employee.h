// Workshop: 9
// Part: 1
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/07/26
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
///////////////////////////////////////////////////
#include <iostream>
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_
#include "ReadWrite.h"
namespace sdds
{
    class Employee : public ReadWrite
    {
        int m_empno;
        int m_office;
        char m_name[41];
        double m_salary;
    public:
        Employee();
        Employee(int stno, const char* name, double salary, int office);
        void set(int stno, const char* name, double salary, int office);
        std::ostream& display(std::ostream& os)const;
        std::istream& read(std::istream& is);
        bool operator==(int office)const;
    };
}
#endif // !SDDS_EMPLOYEE_H_