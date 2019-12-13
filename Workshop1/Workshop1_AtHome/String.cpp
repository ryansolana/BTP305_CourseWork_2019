#include "String.h"

// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Sept 14, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

namespace sdds {

	unsigned int g_maxSize = 3;

	String::String(const char* string) {

		if (string != nullptr) {
			//allocate memory
			m_string = new char[g_maxSize+1];

			//copy string
			strncpy(m_string, string, g_maxSize);
			m_string[g_maxSize] = '\0';
		}
		else {
			m_string = nullptr;
		}
	}
	 
	// Copy Constructor
	String::String(const String& src) {

		if (src.m_string != nullptr) {
			m_string = new char[g_maxSize+1];
			strncpy(m_string, src.m_string, g_maxSize);
		}
		else {
			m_string = nullptr;
		}
	}

	// Deallocate memory
	String::~String() {
		delete m_string;
		m_string = nullptr;
	}
	// Copy Assignment Operator
	String& String::operator=(const String& src) {

		// Check for self assignment
		if (this != &src) {
			delete[] m_string;
			if (src.m_string != nullptr) {
				m_string = new char[g_maxSize+1];
				strncpy(m_string, src.m_string, g_maxSize);
			}
			else {
				m_string = nullptr;
			}
		}
		return *this;
	}

	void String::display(std::ostream& os) const { // ostream& is not needed, neither is return os
		os << m_string;
	}

	std::ostream& operator<<(std::ostream& lhs, const String& rhs) {

		static int counter = 1;
		lhs << counter << ": "; // passes as long as lhs is same type
		rhs.display(lhs);
		counter++;

		return lhs;
	}
}