#pragma once
#include <iostream>
#include <cstring>

// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Sept 10, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

namespace sdds{

	extern unsigned int g_maxSize;

	class String {
	private:
		char m_string[4];
	public:
		String(const char* string);
		
		void display(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& lhs, const String& rhs);
	};
	
}
