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
#ifndef SDDS_FILE_H
#define SDDS_FILE_H
#include"ShoppingRec.h"
namespace sdds
{
    bool openFileForRead();
    bool openFileForOverwrite();
    void closeFile();
    bool freadShoppingRec(ShoppingRec* rec);
    void fwriteShoppintRec(const ShoppingRec* rec);
}

//#endif