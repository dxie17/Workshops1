// Workshop: 4
// Part: 2
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/06/20
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
///////////////////////////////////////////////////
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

namespace sdds
{

    class Label
    {
        char m_frameArg[9];
        char* m_content;
        void setDefault();
        void setLabel(const char* content);
    public:
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        ~Label();
        std::ostream& printLabel()const;
        void readLabel();
    };
}
#endif