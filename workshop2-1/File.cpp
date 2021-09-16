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
#include <cstdio>
#include "File.h"

namespace sdds
{
    extern FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    bool read(char *empinfo) {
        return fscanf(fptr, "%[^\n]\n", empinfo) ==1;
    }
    bool read(int & emp_num) {
        return fscanf(fptr, "%d,", &emp_num) ==1;
    }
    bool read(double & emp_salary) {
        return fscanf(fptr, "%lf,", &emp_salary) ==1;
    } 
}