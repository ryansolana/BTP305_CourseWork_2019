

#include "String.h"

// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Sept 10, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

namespace sdds {

	unsigned int g_maxSize = 3;


	String::String(const char* string) {

		if (string != nullptr) {
			strncpy(m_string, string, 3);
			m_string[3] = '\0';
		}
		else {
			m_string[0] = '\0';
		}
	}

	void String::display(std::ostream& os) const{ // ostream& is not needed, neither is return os
		os << m_string;
	}

	std::ostream& operator<<(std::ostream& lhs, const String& rhs){
		
		static int counter = 1;
		lhs << counter << ": "; // passes as long as lhs is same type
		rhs.display(lhs);
		counter++;

		return lhs;
	}
}