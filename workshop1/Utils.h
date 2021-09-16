// Workshop:1
// Part:1
// Full Name:Deyang Xie
// Student ID:150162204
// Email Address:dxie17@myseneca.ca
// Date:2021/05/25
// Description:I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
///////////////////////////////////////////////////
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds
{
    void flushkeys();
    bool ValidYesResponse(char ch);
    bool yes();
    void readCstr(char cstr[], int len);
    int readInt(int min, int max);
}

#endif