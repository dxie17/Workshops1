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
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdlib>
#include"ShoppingList.h"
#include"Utils.h"

// set to false when compling on Linux
const bool APP_OS_WINDOWS = false;

using namespace std;
using namespace sdds;

int listMenu();

int main() {
    bool done = false;
    loadList();
    while (!done) {
        system(APP_OS_WINDOWS ? "cls" : "clear");
        switch (listMenu()) {
        case 1:
            toggleBought();
            break;
        case 2:
            addItemToList();
            break;
        case 3:
            removeItemfromList();
            break;
        case 4:
            removeBoughtItems();
            break;
        case 5:
            clearList();
            break;
        default:
            done = true;
        }
    }
    saveList();
    return 0;
}

int listMenu() {
    cout << "-->>> My Shopping List <<<--" << endl;
    displayList();
    cout << "----------------------------" << endl
        << "1- Toggle bought Item" << endl
        << "2- Add Shopping Item" << endl
        << "3- Remove Shopping Item" << endl
        << "4- Remove bought Items" << endl
        << "5- Clear List" << endl
        << "0- Exit" << endl << "> ";
    return readInt(0, 5);
}