// Workshop: 2
// Part: 2
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/06/03
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
///////////////////////////////////////////////////
#include "Population.h"
using namespace sdds;
int main() {
    if (load("PCpopulations.csv")) {
        display();
    }
    deallocateMemory();
    return 0;
}