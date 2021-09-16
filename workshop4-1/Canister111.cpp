// Workshop: 4
// Part: 1
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/06/18
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
#define PI 3.14159265
using namespace std;
namespace sdds
{ 
    void Canister::setToDefault() {
        m_contentName = nullptr;
        m_diameter = 10.0;
        m_height = 13.0;
        m_contentVolume = 0.0;
        m_usable=true;
        return;
    }

    void Canister::setName(const char* Cstr) {
        if (m_usable&& Cstr != nullptr) {
            delete[]m_contentName;
            m_contentName = nullptr;
            m_contentName = new char[strLen(Cstr) + 1];
            strCpy(m_contentName, Cstr);
        }
        return;
    }

    bool Canister::isEmpty()const {
        return volume() < 0.00001;
    }

    bool Canister::hasSameContent(const Canister& C)const {
        return m_contentName != nullptr && C.m_contentName != nullptr &&
            !(strCmp(m_contentName, C.m_contentName));
    }

    Canister::Canister() {
        setToDefault();
    }

    Canister::Canister(const char* contentName) {
        setToDefault();
        if (contentName != nullptr) {
            m_contentName = new char[strLen(contentName) + 1];
            strCpy(m_contentName, contentName);
        } 
    }

    Canister::Canister(double height, double diameter, const char* contentName) {
        setToDefault();
        if (height >= 13.0 && height <=40.0 && diameter >= 10.0&& diameter <= 30.0) {
            if (contentName != nullptr) {
                m_contentName = new char[strLen(contentName) + 1];
                strCpy(m_contentName, contentName);
            }
            m_diameter = diameter;
            m_height = height;
        }
        else m_usable = false;
    }

    Canister::~Canister() {
        if (m_contentName != nullptr) {
            delete[]m_contentName;
            m_contentName = nullptr;
        }
    }

    Canister& Canister::setContent(const char* contentName) {
        if (contentName == nullptr) m_usable = false;
        else if (isEmpty()) {
            setName(contentName);
            m_contentVolume = 0.0;
            m_usable = true;
        }
        else if(strCmp(m_contentName,contentName))m_usable= false;
        return *this;
    }

    Canister& Canister::pour(double quantity) {
        if (m_usable && quantity > 0 && volume() + quantity <= capacity())
            m_contentVolume += quantity;
        else m_usable = false;
        return *this;
    }

    Canister& Canister::pour(Canister&C) {
        if (C.m_contentName != nullptr) {
            *this = setContent(C.m_contentName);
            if (!hasSameContent(C))m_usable = false;
            if (C.volume() > capacity() - volume()) {
                C.m_contentVolume = C.m_contentVolume - (capacity() - volume());
                m_contentVolume = capacity();
            }
            else {
                pour(C.m_contentVolume);
                C.m_contentVolume = 0.0;
            }
        }
        return *this;
    }

    double Canister::volume()const {
        return m_contentVolume;
    }

    std::ostream& Canister::display()const {
        cout.fill(' ');
        cout.setf(ios::fixed);
        cout.width(7);
        cout.precision(1);
        cout.unsetf(ios::left);
        cout.setf(ios::right);
        cout << capacity();
        cout<< "cc (" << m_height << "x" << m_diameter<< ") Canister";
        if (m_contentName != nullptr && m_usable) {
            cout << " of ";
            cout.fill(' ');
            cout.width(7);
            cout << volume()<<"cc   ";
            cout.unsetf(ios::right);
            cout.setf(ios::left);
            cout<<m_contentName;
        }  
        else if(!m_usable)
        {
            cout.fill(' ');
            cout.width(15);
            cout << " of Unusable content, discard!";
        }
        return cout;
    }

    double Canister::capacity()const {
        return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
    }

    void Canister::clear() {
        delete[]m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
        return;
    }
}