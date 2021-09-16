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
#include "ReadWrite.h"
using namespace std;
namespace sdds
{
    ostream& operator<<(ostream& os, const ReadWrite& c) {
        return c.display(os);
    }

    istream& operator >> (istream& is, ReadWrite& c) {
        return c.read(is);
    }
}