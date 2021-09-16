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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"

#include "Label.h"
using namespace std;
namespace sdds
{

    void Label::setDefault() {
        m_frameArg[0] ='\0';
        m_content = nullptr;
        strCpy(m_frameArg, "+-+|+-+|");
        return;
    }

    void Label::setLabel(const char* content) {
        if (content != nullptr) {
            int lenContent = 0;
            strLen(content) > 70 ? lenContent=70 : lenContent = strLen(content);
            m_content = new char[lenContent + 1];
            strnCpy(m_content, content, lenContent);
        }
        return;
    }

    Label::Label(){
        setDefault();
    }
    Label::Label(const char* frameArg){
        setDefault();
        if(strLen(frameArg)==8) strCpy(m_frameArg, frameArg);
    }

    Label::Label(const char* frameArg, const char* content) {
        setDefault();
        if (strLen(frameArg) == 8) strCpy(m_frameArg, frameArg);
        setLabel(content);
    }

    Label::~Label() {
        delete[] m_content;
        m_content = nullptr;
    }

    std::ostream& Label::printLabel()const {
        if (m_content != nullptr) {
            cout << m_frameArg[0];
            for (int i = 0; i < strLen(m_content) + 2; i++) cout << m_frameArg[1];
            cout << m_frameArg[2] << endl;

            cout << m_frameArg[7];
            for (int i = 0; i < strLen(m_content) + 2; i++) cout << ' ';
            cout << m_frameArg[3] << endl;

            cout << m_frameArg[7];
            cout << ' '<< m_content<< ' ';
            cout << m_frameArg[3] << endl;

            cout << m_frameArg[7];
            for (int i = 0; i < strLen(m_content) + 2; i++) cout << ' ';
            cout << m_frameArg[3] << endl;

            cout << m_frameArg[6];
            for (int i = 0; i < strLen(m_content) + 2; i++) cout << m_frameArg[5];
            cout << m_frameArg[4];
        }
        return cout;
    }

    void Label::readLabel(){
        char tempStr[100] = {0};
        cin.getline(tempStr, 100);
        setLabel(tempStr);
        return;
    }
}