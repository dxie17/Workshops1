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
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds
{
    FILE* fptr;
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

    bool read(char *codeString) {
        return fscanf(fptr, "%[^,],", codeString) == 1;
    }
    bool read(int &poputionNumber) {
        return fscanf(fptr, "%d\n", &poputionNumber) == 1;
    }
}