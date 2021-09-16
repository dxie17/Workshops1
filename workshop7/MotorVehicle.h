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
#ifndef SDDS_MOTORVEHICLE_H_
#define SDDS_MOTORVEHICLE_H_
namespace sdds
{
    class MotorVehicle
    {
        char m_plate[9];
        char m_address[64];
        int m_year;
        bool isFirstMove=true;
        void setEmpty();
    public:
        MotorVehicle();
        MotorVehicle(char const* plate, int year);
        MotorVehicle(const char* plate, int year, const char* address);
        void moveTo(const char *address);
        std::ostream& write(std::ostream& ostr)const;
        std::istream& read(std::istream& istr);
    };
    std::ostream& operator<<(std::ostream& ostr, const MotorVehicle &A);
    std::istream& operator>>(std::istream& istr, MotorVehicle & A);
}
#endif