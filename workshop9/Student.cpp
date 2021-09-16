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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

using namespace std;
#include "Student.h"
namespace sdds
{
    Student::Student() {
        set(0, "", 0.0);
    }
    Student::Student(int stno, const char* name, double gpa) {
        set(stno, name, gpa);
    }
    void Student::set(int stno, const char* name, double gpa) {
        m_stno = stno;
        strcpy(m_name, name);
        m_gpa = gpa;
    }
    ostream& Student::display(ostream& os)const {
        return os << m_stno << " " << m_name << " GPA: " << fixed << setprecision(1) << m_gpa;
    }
    istream& Student::read(istream& is) {
        is >> m_stno;
        is.getline(m_name, 40, '\n');
        return is;
    }
    bool Student::operator==(double gpa)const {
        return m_gpa > (gpa - 0.001) && m_gpa < (gpa + 0.001);
    }
}