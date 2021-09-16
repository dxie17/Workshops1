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
#ifndef SDDS_SHOPPINGLIST_H
#define SDDS_SHOPPINGLIST_H

namespace sdds
{
    bool loadList();
    void displayList();
    void removeBoughtItems();
    void removeItem(int index);
    bool saveList();
    void clearList();
    void toggleBought();
    void addItemToList();
    void removeItemfromList();
    bool listIsEmpty();
}

#endif