//one
//Name: Jiyuan Chen
//Email : jchen467@myseneca.ca
//ID : 128684206
//Date : 2021 - 6 - 21
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "cstring.h"
#include "Label.h"

namespace sdds {

	class LabelMaker {
		Label* m_lables;
		int m_noOfLabels;
		void setMakerToDefault();

	public:
		LabelMaker();
		LabelMaker(int noOfLabels);
		//creates a dynamic array of Labels to the size of noOfLabels

		void readLabels();
		//Gets the contents of the Labels as demonstrated in the Execution sample

		void printLabels();
		//Prints the Labels as demonstrated in the Execution sample

		~LabelMaker();
		//Deallocates the memory when LabelMaker goes out of scope.

	};

}
