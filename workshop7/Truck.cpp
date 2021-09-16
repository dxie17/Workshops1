// Workshop: 7
// Part: 1
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/07/12
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Truck.h"

using namespace std;
namespace sdds
{
    void Truck::setEmpty() {
        m_capacity = 0;
        m_cargo = 0;
    }

    Truck::Truck() {
        setEmpty();
    }

    Truck::Truck(const char *plate, int year, double capacity, const char*address):MotorVehicle(plate, year, address) {
        setEmpty();
        if (plate!=nullptr && year > 0 && capacity > 0)
            this->m_capacity = capacity;
        MotorVehicle::moveTo(address);
    }

    bool Truck::addCargo(double cargo) {
        bool isTrue= false;
        if (cargo > 0 && m_cargo < m_capacity) {
            isTrue = true;
            m_cargo += cargo;
            m_cargo > m_capacity ? m_cargo = m_capacity : m_cargo;
        }
        return isTrue;
    }

    bool Truck::unloadCargo() {
        bool isTrue = false;
        if (m_cargo > 0)isTrue = true;
        m_cargo = 0;
        return isTrue;
    }

    std::ostream& Truck::write(std::ostream& ostr) const{
        this->MotorVehicle::write(ostr)<< " | " << m_cargo << '/' << m_capacity;
        return ostr;
    }

    std::istream& Truck::read(std::istream& istr){
        this->MotorVehicle::read(istr);
        cout << "Capacity: ";
        istr >> m_capacity;
        cout << "Cargo: ";
        istr >> m_cargo;
        return istr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Truck &A) {
        A.write(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, Truck &A) {
        A.read(istr);
        return istr;
    }
}