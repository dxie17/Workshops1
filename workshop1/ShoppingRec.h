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
#ifndef SDDS_SHOPPINGREC_H
#define SDDS_SHOPPINGREC_H

const int MAX_TITLE_LENGTH=50;
namespace sdds
{
    struct ShoppingRec
    {
        char m_title[MAX_TITLE_LENGTH+1];
        int m_quantity;
        bool m_bought;
    };
    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);
}
#endif