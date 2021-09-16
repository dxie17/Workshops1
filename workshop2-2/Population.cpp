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
#include<iostream>
#include "Population.h"
#include "File.h"

using namespace std;

namespace sdds
{
    int coutLine = 0;
    Codepopulation* codepop = { 0 };
    void sort() {
        int i, j;
        Codepopulation temp;
        for (i = coutLine - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (codepop[j].populatonNumber> codepop[j + 1].populatonNumber) {
                    temp = codepop[j];
                    codepop[j] = codepop[j + 1];
                    codepop[j + 1] = temp;
                }
            }
        }
        return;
    }

    bool load(const char *fileName) {
        bool ok = false;
        if (openFile(fileName)) {
            coutLine = noOfRecords();
            codepop = new Codepopulation[coutLine];
            int i = 0;
            while(read(codepop[i].codeString) && read(codepop[i].populatonNumber))i++;
            if (i != coutLine)
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            else ok = true;
            closeFile();
        }
        else cout << "Could not open data file: " << fileName << endl;
        return ok;
    }
    void deallocateMemory() {
        delete[]codepop;
        return;
    }

    void display() {
        sort();
        int sum = 0;
        cout <<"Postal Code: population"<< endl;
        cout << "-------------------------" << endl;
        for (int i = 0; i < coutLine; i++)
        {
            cout << i + 1 << "- " << codepop[i].codeString << ":  " 
                << codepop[i].populatonNumber << endl;
            sum += codepop[i].populatonNumber;
        }    
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " <<sum<< endl;
        return;
    }
}