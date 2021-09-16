//Name: Jiyuan Chen
//Email : jchen467@myseneca.ca
//ID : 128684206
//Date : 2021 - 6 - 18
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  
#include "Canister.h"
using namespace std;
namespace sdds {
	const double PI = 3.14159265;

	void Canister::setToDefault() {
		m_contentName = nullptr;
		m_height = 13;
		m_diameter = 10;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	void Canister::setName(const char* Cstr) {
		if (Cstr != nullptr && m_usable==true) {
			delete[] m_contentName;
			m_contentName = new char[strLen(Cstr) + 1];
			strCpy(m_contentName, Cstr);
		}
	}

	bool Canister::isEmpty() const {
		return m_contentVolume < 0.00001;
	}

	bool Canister::hasSameContent(const Canister& C) const {
		return !strCmp(m_contentName, C.m_contentName) && m_contentName != nullptr && C.m_contentName != nullptr;
	}


	Canister::Canister() {
		setToDefault();
	}


	Canister::Canister(const char* contentName) {
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double height, double diameter,
		const char* contentName) {
		setToDefault();
		if (height <= 40 && height >= 10.00 && diameter <= 30 && diameter >= 10.00) {
			if (contentName != nullptr) {
				m_contentName = new char[strLen(contentName) + 1];
				strCpy(m_contentName, contentName);
			}
			m_diameter = diameter;
			m_height = height;
		}
		else {
			m_usable = false;
		}
	}

	Canister::~Canister() {
		delete[] m_contentName;
	}

	Canister& sdds::Canister::setContent(const char* contentName) {
		if (!contentName) {
			m_usable = false;
		}
		else if (isEmpty()) {
			setName(contentName);
		}
		else if (strCmp(m_contentName, contentName)!=0) {
			m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(double quantity) {
		if (m_usable && quantity > 0.0 && (quantity + volume()) <= capacity())
		{
			m_contentVolume += quantity;
			m_usable = true;
		}
		else
		{
			m_usable = false;
		}

		return *this;
	}

	Canister& Canister::pour(Canister& C) {
		setContent(C.m_contentName);
		if (C.volume() > (capacity() - volume())){
			C.m_contentVolume -= (capacity() - volume());
			m_contentVolume = capacity();
		}
		else
		{
			pour(C.m_contentVolume);
			C.m_contentVolume = 0.0;
		}

		return *this;
	}

	double sdds::Canister::volume() const {
		return m_contentVolume;
	}

	std::ostream& sdds::Canister::display() const {
		cout.setf(ios::fixed);
		cout.precision(1);
		cout.width(7);
		cout << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
		if (!m_usable) {
			cout << " of Unusable content, discard!";
		}else if (m_contentName != nullptr) {
			cout << " of ";
			cout.width(7);
			cout << m_contentVolume << "cc   " << m_contentName;
		}

		return cout;
	}

	double sdds::Canister::capacity() const {
		return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
	}

	void sdds::Canister::clear() {
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;
	}
}