//one
//Name: Jiyuan Chen
//Email : jchen467@myseneca.ca
//ID : 128684206
//Date : 2021 - 6 - 18
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include"Label.h"
#include "cstring.h"

using namespace std;

namespace sdds {

	void Label::setToDefault()
	{
		m_content = nullptr;
		strnCpy(m_frameArg, "+-+|+-+|", 8);
		m_frameArg[8] = '\0';
	}

	void Label::setContent(const char* content) {
		if (content != nullptr) {
			//setToDefault();
			int len = strLen(content);
			if (len > 70) len = 70;
			m_content = new char[len + 1];
			strnCpy(m_content, content, len);
			m_content[len] = '\0';
		}
	}

	void Label::setFrameArg(const char* frameArg) {
		setToDefault();
		if (strLen(frameArg)==8) {
			strnCpy(m_frameArg, frameArg, 8);
			m_frameArg[8] = '\0';
		}
	}

	Label::Label()
	{
		setToDefault();
	}

	Label::Label(const char* frameArg)
	{
		setToDefault();
		setFrameArg(frameArg);
	}

	Label::Label(const char* frameArg, const char* content)
	{
		setToDefault();
		setFrameArg(frameArg);
		setContent(content);
	}

	Label::~Label()
	{
		delete[] m_content;
		m_content = nullptr;
	}

	void Label::readLabel()
	{
		char ch[71] = { 0 };
		cin.getline(ch, 70);
		setContent(ch);
	}

	std::ostream& Label::printLabel() const
	{	
				
		if (m_content ==nullptr) {
			cout << endl;
		}else{
			int blankLen = strLen(m_content) + 2;
			cout<<m_frameArg[0];
			for (int i = 0; i < blankLen; i++) cout << m_frameArg[1];
			cout << m_frameArg[2] << endl;

			cout<<m_frameArg[7];
			for (int i = 0; i < blankLen; i++) cout << " ";
			cout << m_frameArg[3] << endl;

			cout << m_frameArg[7] << " " << m_content << " " << m_frameArg[3] << endl;

			cout << m_frameArg[7];
			for (int i = 0; i < blankLen; i++) cout << " ";
			cout << m_frameArg[3] << endl;

			cout << m_frameArg[6];
			for (int i = 0; i < blankLen; i++) cout << m_frameArg[5];
			cout << m_frameArg[4] << endl;
		}
				
		return cout;
	}


}