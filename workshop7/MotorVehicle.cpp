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
#include <cstring>
#include <iomanip>
#include"MotorVehicle.h"
#include"cstring.h"

using namespace std;
namespace sdds
{
    void MotorVehicle::setEmpty() {
        m_plate[0] = '\0';
        m_address[0]= '\0';
        m_year=0;
        isFirstMove = true;
    }

    MotorVehicle::MotorVehicle() {
        setEmpty();
    }

    MotorVehicle::MotorVehicle(const char *plate, int year) {
        setEmpty();
        string s = "Factory";
        if (plate != nullptr && year > 0) {
            strCpy(m_plate, plate);
            m_year = year;
            strCpy(m_address, s.c_str());
        }
    }

    MotorVehicle::MotorVehicle(const char* plate, int year,const char*address) {
        setEmpty();
        if (plate != nullptr && year > 0) {
            strCpy(m_plate, plate);
            m_year = year;
            strCpy(m_plate, plate);
            if(address != nullptr) strCpy(m_address, address);
        }
    }

    void MotorVehicle::moveTo(const char *address) {
        string s = "Factory",strAddress= m_address;
        if (isFirstMove && s.compare(strAddress))
                cout << "|" << right << setw(8) << m_plate << "| |"
                << right << setw(20) << s << " ---> "
                << left << setw(20) << m_address << "|" << endl;
        isFirstMove = false;
        if (strCmp(address, m_address)) {
            char tempAdress[64] = { 0 };
            strCpy(tempAdress, m_address);
            strCpy(this->m_address, address);
            cout << "|" << right << setw(8) << m_plate << "| |"
                << right << setw(20) << tempAdress << " ---> "
                << left << setw(20) << address << "|" << endl;
        }
        return;
    }

    std::ostream& MotorVehicle::write(std::ostream& ostr)const {
        ostr <<"| "<< this->m_year << " | " << this->m_plate << " | " << this->m_address;
        return ostr;
    }

    std::istream& MotorVehicle::read(std::istream& istr) {
        cout << "Built year: ";
        istr >> m_year;
        cout << "License plate: ";
        istr >> m_plate;
        cout << "Current location: ";
        istr >> m_address;
        return istr;
    }

    std::ostream& operator<<(std::ostream& ostr,  const MotorVehicle &A) {
        A.write(ostr);
        return ostr;
    }

    std::istream &operator>>(std::istream& istr, MotorVehicle &A) {
        A.read(istr);
        return istr;
    }
}