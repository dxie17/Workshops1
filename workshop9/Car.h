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
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include "ReadWrite.h"
namespace sdds
{
    class Car : public ReadWrite
    {
        char m_plate[9];
        char m_makeModel[41];
    public:
        Car(const char* plate = "", const char* makeModel = "");
        void set(const char* plate, const char* makeModel);
        std::ostream& display(std::ostream& os)const;
        std::istream& read(std::istream& is);
        bool operator==(const char* mmSubstr)const;
    };


}
#endif // !SDDS_CAR_H_
