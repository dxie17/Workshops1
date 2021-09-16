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
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds
{
    struct Codepopulation
    {
        char codeString[40];
        int populatonNumber;
    };
    void sort();
    bool load(const char* fileName);
    void deallocateMemory(); 
    void display();
}
#endif // SDDS_POPULATION_H_