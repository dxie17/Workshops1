// Workshop: 6
// Part: 1
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/07/07
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
    Line::operator const char* () const {
        return (const char*)m_value;
    }

    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = nullptr;
        m_value = new char[strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }

    Line::Line() {
        m_value = nullptr;
    }

    Line::~Line() {
        delete[] m_value;
        m_value = nullptr;
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {
        if (fname != nullptr) {
            int lenDynamic = strLen(fname) + 1;
            char prefix[3] = "C_";
            isCopy ? lenDynamic += 2 : lenDynamic;
            m_filename = new char[lenDynamic];
            if (!isCopy) strCpy(m_filename, fname);
            else {
                for (int i = 0; i < lenDynamic; i++)
                {
                    if (i < 2) m_filename[i] = prefix[i];
                    else if (i >= 2) m_filename[i] = fname[i - 2];
                }
                m_filename[lenDynamic] = '\0';
            }
        }
        return;
    }

    void TextFile::setNoOfLines() {
        ifstream fin;
        bool notNull = false;
        if (m_filename != nullptr) {
            fin.open(m_filename);
            if (fin.is_open()) {
                char searchNewLine = '\0';
                while (fin.get(searchNewLine)) {
                    notNull = true;
                    if (searchNewLine == '\n')
                        m_noOfLines++;
                }
                m_noOfLines++;
                fin.close();
            }
        }
        if (!notNull) {
            delete[]m_filename;
            m_filename = nullptr;
        }
        return;
    }

    void TextFile::loadText() {
        ifstream fin;
        if (m_filename != nullptr) {
            delete[]m_textLines;
            m_textLines = nullptr;
            m_textLines = new Line[m_noOfLines];
            string tempStr;
            fin.open(m_filename);
            int i = 0;
            if (fin.is_open()) {
                for (i = 0; getline(fin, tempStr, '\n'); i++) {
                    m_textLines[i] = tempStr.c_str();
                }
                m_noOfLines = i;
                fin.close();
            }
        }
        return;
    }
    void TextFile::saveAs(const char* fileName) const {
        ofstream fout;
        if (fileName != nullptr) {
            fout.open(fileName);
            unsigned int i = 0;
            if (fout.is_open()) {
                for (i = 0; i < m_noOfLines - 1; i++)
                    fout << m_textLines[i].m_value << endl;
                fout << m_textLines[i].m_value;
                fout.close();
            }
        }
        return;
    }

    void TextFile::setEmpty() {
        delete[]m_textLines;
        m_textLines = nullptr;
        delete[]m_filename;
        m_filename = nullptr;
        m_noOfLines = 0;
        return;
    }

    TextFile::TextFile(unsigned int pageSize) {
        m_textLines = nullptr;
        m_filename = nullptr;
        m_pageSize = pageSize;
        m_noOfLines = 0;
    }

    TextFile::TextFile(const char* filename, unsigned int pageSize) {
        m_textLines = nullptr;
        m_filename = nullptr;
        m_pageSize = pageSize;
        m_noOfLines = 0;
        if (filename != nullptr) {
            m_filename = new char[strLen(filename) + 1];
            strCpy(m_filename, filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile& textfile) {
        setEmpty();
        setFilename(textfile.m_filename, textfile);
        m_noOfLines = textfile.m_noOfLines;
        m_textLines = new Line[m_noOfLines];
        for (unsigned int i = 0; i < textfile.m_noOfLines; i++) {
            m_textLines[i].m_value = new char[strLen(textfile.m_textLines[i].m_value) + 1];
            strCpy(m_textLines[i].m_value, textfile.m_textLines[i].m_value);
        }
        saveAs(m_filename);
        loadText();
    }

    TextFile& TextFile::operator=(const TextFile& textfile) {
        setFilename(textfile.m_filename, textfile);
        m_noOfLines = textfile.m_noOfLines;
        m_textLines = new Line[m_noOfLines];
        for (unsigned int i = 0; i < textfile.m_noOfLines; i++) {
            m_textLines[i].m_value = new char[strLen(textfile.m_textLines[i].m_value) + 1];
            strCpy(m_textLines[i].m_value, textfile.m_textLines[i].m_value);
        }
        saveAs(m_filename);
        loadText();
        return *this;
    }

    TextFile::~TextFile() {
        for (unsigned int i = 0; i < m_noOfLines; i++) {
            delete[] m_textLines[i].m_value;
            m_textLines[i].m_value = nullptr;
        }
        delete[]m_textLines;
        m_textLines = nullptr;
    }

    std::ostream& TextFile::view(std::ostream& ostr)const {
        if (m_filename != nullptr) {
            ostr << m_filename << endl;
            ostr << "==========" << endl;
            for (unsigned int i = 0; i < m_noOfLines; i++) {
                ostr << m_textLines[i].m_value << endl;
                if ((i + 1) % m_pageSize == 0) {
                    ostr << "Hit ENTER to continue..." << endl;
                    while (getchar() != '\n') {
                        ;
                    }
                    putchar('\n');
                }
            }
        }
        return ostr;
    }

    std::istream& TextFile::getFile(std::istream& istr) {
        char fileName[100] = { 0 };
        istr >> fileName;
        setFilename(fileName);
        loadText();
        setNoOfLines();
        return istr;
    }

    TextFile::operator bool()const {
        return m_textLines > 0 && m_filename != nullptr;
    }

    unsigned int TextFile::lines()const {
        return m_noOfLines;
    }

    const char* TextFile::name()const {
        return m_filename;
    }

    const char* TextFile::operator[](unsigned index) const
    {
        return *this ? m_textLines[index % m_noOfLines].m_value : nullptr;
    }

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
        text.view(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, TextFile& text) {
        text.getFile(istr);
        return istr;
    }
}