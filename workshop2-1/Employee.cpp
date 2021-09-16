// Workshop: 2
// Part: 1
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/06/02
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Employee.h"
#include "File.h"
using namespace std;

namespace sdds
{
    int noOfEmployees;
    Employee* employees = {0};
    FILE* fptr;
    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

//Fardad helps a lot here, thank you very much, I aapriciate it.
    bool load(Employee &employees) {
        bool ok = false;
        char name[128] = {0};
       // ok =  read(employees.m_empNo) && read(employees.m_salary)&&read(name);
        ok = fscanf(fptr,"%d,%lf,%[^\n]\n", &employees.m_empNo, &employees.m_salary, name) == 3;
        if (ok) {
            employees.m_name = new char[strLen(name) + 1];
            strCpy(employees.m_name, name);
        }
        return ok;
    }
 
    bool load() {
        bool ok = false;
        int cout_number=0;
        if (openFile(DATAFILE)) {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            for (int i = 0; i < noOfEmployees; i++) {
                load(employees[i]);
                cout_number++;
            }
            if (noOfEmployees != cout_number)
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            else
                ok = true;
            closeFile();
        }
        else
            cout << "Could not open data file: " << DATAFILE << endl;
        return ok;
    }

    void display() {
        sort();
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;
        for (int i = 0; i < noOfEmployees; i++)
            cout <<i+1<<"- "<<employees[i].m_empNo << ": " << employees[i].m_name 
            << ", " << employees[i].m_salary << endl;
        return;
    }

    void deallocateMemory() {
        for (int i = 0; i < noOfEmployees; i++) delete[]employees[i].m_name;
        delete[]employees;
        return;
    }
}