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
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds
{
    bool openFile(const char filename[]);
    void closeFile();
    int noOfRecords();
    bool read(char* str);
    bool read(int& emp_num);
    bool read(double& emp_salary);
}
#endif // !SDDS_FILE_H_