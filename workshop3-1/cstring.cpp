// Workshop: 3
// Part: 1
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/06/09
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
///////////////////////////////////////////////////
#include "cstring.h"

namespace sdds
{
    void strCpy(char* des, const char* src) {
        int len_src = 0;
        for (len_src = 0; src[len_src] != '\0'; len_src++);
        des[len_src] = { 0 };
        for (int i = 0; i < len_src; i++)des[i] = src[i];
        des[len_src] = '\0';
        return;
    }

    void strnCpy(char* des, const char* src, int len) {
        int len_src = 0;
        for (len_src = 0; src[len_src] != '\0'; len_src++);
        if (len_src >= len)
            for (int i = 0; i < len; i++)des[i] = src[i];
        else {
            des[len_src] = 0;
            for (int i = 0; i < len_src; i++)des[i] = src[i];
        }
        des[len] = '\0';
        return;
    }

    int strCmp(const char* s1, const char* s2) {
        int len_s1 = 0, len_s2 = 0, returnValue = 1;
        for (len_s1 = 0; s1[len_s1] != '\0'; len_s1++);
        for (len_s2 = 0; s2[len_s2] != '\0'; len_s2++);
        if (len_s1 == len_s2) {
            int index;
            for (index = 0; index < len_s1 && s1[index] == s2[index]; index++);
            if (index == len_s1)returnValue = 0;
            else {
                if (s1[index] > s2[index])returnValue = 1;
                else returnValue = -1;
            }
        }
        else if (len_s1 > len_s2)
            returnValue = 1;
        else
            returnValue = -1;
        return returnValue;
    }

    int strnCmp(const char* s1, const char* s2, int len) {
        int len_s1 = 0, len_s2 = 0, returnValue = 1;
        for (len_s1 = 0; s1[len_s1] != '\0'; len_s1++);
        for (len_s2 = 0; s2[len_s2] != '\0'; len_s2++);
        if (len_s1 > len && len_s2 < len) returnValue = 1;
        else if (len_s1 < len && len_s2 > len)returnValue = -1;
        else if (len_s1 >= len && len_s2 >= len) {
            int index = 0;
            for (index = 0; index < len && s1[index] == s2[index]; index++);
            if (index == len)returnValue = 0;
            else {
                if (s1[index] > s2[index])returnValue = 1;
                else returnValue = -1;
            }
        }
        else if (len_s1 < len && len_s2 < len)
            returnValue = strCmp(s1, s2);
        return returnValue;
    }

    int strLen(const char* s) {
        int len = 0;
        for (len = 0; s[len] != '\0'; len++);
        return len;
    }

    const char* strStr(const char* str1, const char* str2) {
        int i, i_continue, flag_break = 0;
        const char* returnAdress;
        for (i = 0; i < strLen(str1) && str2[0] != str1[i]; i++);
        if (strLen(str1) - i < strLen(str2)) returnAdress = nullptr;
        else {
            for (i_continue = i; i_continue < i + strLen(str2) && flag_break == 0; i_continue++)
                if (str1[i_continue] != str2[i_continue - i])   flag_break = 1;
            if (flag_break == 0)returnAdress = &str1[i];
            else returnAdress = nullptr;
        }
        return returnAdress;
    }

    void strCat(char* des, const char* src) {
        int len_des = strLen(des), len_src = strLen(src), i = len_des;
        for (i = len_des; i < len_des + len_src; i++)
            des[i] = src[i - len_des];
        des[i] = '\0';
        return;
    }
}