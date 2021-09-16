// Workshop: 9
// Part: 1
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/07/26
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
///////////////////////////////////////////////////
#include <iostream>
#include "Collection.h"
#include "Car.h"
#include "Employee.h"
#include "Student.h"
using namespace std;
namespace sdds
{
    template <typename T1, typename T2>
    bool search(Collection<T1> & obj, T1 *array,int noOfElement, T2 key) {
        bool isTrue= false;
        int countNum = 0;
        for (int i = 0; i < noOfElement; i++) {
            if (array[i] == key) {
                obj[countNum] = array[i];
                countNum++;
                isTrue = true;
            }
        }
        return isTrue;
    }
    /* comment section:Template type requirements
    In this section I create template <typename T1, typename T2> to realize the function. The reason why I have to create two typenames is because in the template function there will be 4 parameters, just one is defined(int), the rest of 3 is not defined. But the first one(Collection<T1>) is relative with the second one(T1) so I can solve it just by using one typename. The last one(T2) I have to create another typename to represent it. In this way, when the template function called in the main.cpp it will create corresponding function. For example, in main.cpp when search(Cres,C,7,"Tesla") calls the template function it will create a function search(Collection<Car> & obj, Car *array,int noOfElement,char* key) to execute it and get results. While search(Sres, S, 6, 4.0) calls the template function it will create a function search(Collection<Student> & obj, Student *array,int noOfElement,double key) to execute it and get results and so on.
*/

    template <typename T>
    void listArrayElements(const char*listTitle, T& array, int noOfElement) {
        std::cout << listTitle << endl;
        for (int i = 0; i < noOfElement; i++) {
            std::cout <<i+1 <<": " << array[i] << endl;
        }
        return;
    }
    /*  comment section:Template type requirements
    In this section I create template <typename T> to realize the function. It's easy to understand compared with the one above. The reason why I have to create just one typename is because in the template function there will be 3 parameters, two of them is defined(const char,int), just one is not defined. In this way, when the template function called in the main.cpp it will create corresponding function. For example, in main.cpp when listArrayElements("All the cars:", C,7) calls the template function it will create a function listArrayElements(const char*listTitle, Car & array, int noOfElement) to execute it and get results. While listArrayElements("All students:", S, 6) calls the template function it will create a function listArrayElements(const char*listTitle, Student & array, int noOfElement) to execute it and get results and so on.
    */
}