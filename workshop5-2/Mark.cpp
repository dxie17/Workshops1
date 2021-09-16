// Workshop: 5
// Part: 2
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/06/30
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"
#include "Mark.h"

using namespace std;
namespace sdds
{
    void Mark::setEmpty() {
        m_mark = 0;
        m_grade = '\0';
        m_scale = 0.0;
        isValid = true;
        return;
    }

    void Mark::setGradeAndScale() {
        if (m_mark >= 0 && m_mark <50) {
            m_grade = 'F';
            m_scale = 0.0;
        }
        else if (m_mark >= 50 && m_mark < 60) {
            m_grade = 'D';
            m_scale = 1.0;
        }
        else if (m_mark >= 60 && m_mark < 70) {
            m_grade = 'C';
            m_scale = 2.0;
        }
        else if (m_mark >= 70 && m_mark < 80) {
            m_grade = 'B';
            m_scale = 3.0;
        }
        else if (m_mark >= 80 && m_mark <= 100) {
            m_grade = 'A';
            m_scale = 4.0;
        }
        return;
    }

    Mark::Mark() {
        setEmpty();
    }

    Mark::Mark(int mark) {
        setEmpty();
        if (mark >= 0 && mark <= 100) {
            m_mark = mark;
            setGradeAndScale();
        }
        else isValid = false;
    }
    Mark::operator bool() const {
        return isValid;
    }

    Mark::operator char() const {
        char returnGrade = '\0';
        if (isValid) returnGrade = m_grade;
        else returnGrade = 'X';
        return returnGrade;
    }

    Mark::operator int() const {
        return m_mark;
    }
    Mark::operator double() const {
        return m_scale;
    }

    Mark& Mark:: operator =(int mark) {
        setEmpty();
        if (mark >= 0 && mark <= 100) {
            m_mark = mark;
            setGradeAndScale();
        }
        else isValid = false;
        return *this;
    }

    Mark& Mark::operator +=(int addMark) {
        if (addMark >= 0 && (addMark + m_mark) <= 100 && *this) {
            m_mark += addMark;
            setGradeAndScale();
        }
        else {
            setEmpty();
            isValid = false;
        }
        return *this;
    }

    int operator +=(int& addMark, const Mark& markA) {
        if (addMark >= 0 && markA) addMark += markA.m_mark;
        return addMark;
    }
}