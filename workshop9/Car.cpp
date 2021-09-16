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
#include <cstring>
using namespace std;

#include "Car.h"
using namespace std;
namespace sdds
{
    Car::Car(const char* plate, const char* makeModel) {
        set(plate, makeModel);
    }
    void Car::set(const char* plate, const char* makeModel) {
        strncpy(m_plate, plate, 8);
        m_plate[8] = 0;
        strncpy(m_makeModel, makeModel, 40);
        m_makeModel[40] = 0;;
    }
    std::ostream& Car::display(std::ostream& os)const {
        return os << m_plate << " " << m_makeModel;
    }
    std::istream& Car::read(std::istream& is) {
        is >> m_plate;
        is.getline(m_makeModel, 40, '\n');
        return is;
    }
    bool Car::operator==(const char* mmSubstr)const {
        return strstr(m_makeModel, mmSubstr) != nullptr;
    }
}