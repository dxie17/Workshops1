//one
//Name: Jiyuan Chen
//Email : jchen467@myseneca.ca
//ID : 128684206
//Date : 2021 - 6 - 18
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LABEL_H_
#define SDDS_LABEL_H_

#include <iostream>
#include "cstring.h"

namespace sdds {

	class Label {
		char m_frameArg[9];
		char* m_content;
		void setToDefault();
		void setContent(const char* content);
		void setFrameArg(const char* frameArg);
	public:

		Label();
		//Creates an empty label and defaults the frame to "+-+|+-+|"

		Label(const char* frameArg);
		//Creates an empty label and sets the frame to the frameArg argument.

		Label(const char* frameArg, const char* content);
		//Creates a Label with the frame set to frameArg and the content of the Label set to the corresponding argument.Note that you must keep the content dynamically even though it should never be more than 70 characters.

		~Label();
		//Makes sure there is no memory leak when the label goes out of scope.

		void readLabel();
		//Reads the label from console up to 70 characters and stores it in the Label as shown in the Execution sample

		std::ostream& printLabel()const;
		//Prints the label by drawing the frame around the content ad shown in the Execution sample.Note that no newline is printed after the last lineand cout is returned at the end.
	};
}



#endif // !_LABEL_H_
