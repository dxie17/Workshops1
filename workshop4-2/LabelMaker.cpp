//one
//Name: Jiyuan Chen
//Email : jchen467@myseneca.ca
//ID : 128684206
//Date : 2021 - 6 - 121
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include<iostream>
#include "Label.h"
#include "LabelMaker.h"

using namespace std;


namespace sdds{

	void LabelMaker::setMakerToDefault() {
		m_noOfLabels = 0;
		m_lables = nullptr;
	}

	LabelMaker::LabelMaker(){
		setMakerToDefault();
	}

	LabelMaker::LabelMaker(int noOfLabels)
	{
		setMakerToDefault();
		m_noOfLabels = noOfLabels;
		m_lables = new Label[m_noOfLabels];
	}

	void LabelMaker::readLabels()
	{
		cout << "Enter " << m_noOfLabels << " labels:" << endl;
		for (int i = 0; i < m_noOfLabels; i++) {
			cout << "Enter label number " << i+1 << endl;
			m_lables[i].readLabel();
		}
	}

	void LabelMaker::printLabels()
	{
		for (int i = 0; i < m_noOfLabels; i++) {
			m_lables[i].printLabel();
			cout << endl;
		}
	}

	LabelMaker::~LabelMaker()
	{
		for (int i = 0; i < m_noOfLabels; i++) {
			m_lables[i].Label::~Label();
		}
		delete m_lables;

	}

}
