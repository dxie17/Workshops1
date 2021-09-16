// Workshop: 3
// Part: 2
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/06/12
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
///////////////////////////////////////////////////
#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds
{
    class Food
    {
        char m_foodName[31];
        int m_calories;
        int m_timeWhen;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int calories, int timeWhen);
        void display()const;
        bool isValid()const;
        int calories()const;
    };
}

#endif // !SDDS_SUBJECT_H