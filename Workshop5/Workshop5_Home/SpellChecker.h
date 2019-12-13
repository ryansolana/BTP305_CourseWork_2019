// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Oct 19, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>
#include <fstream>

/* Add a SpellChecker module to your project. 
This module should maintain two arrays of strings, both of size 5 (statically allocated):*/

namespace sdds {
	class SpellChecker {
		// arrays of strings for words
		std::string m_badWords[5];
		std::string m_goodWords[5];
	public:
		void TrimString(std::string& str);

		SpellChecker(const char* filename);
		// functor override
		void operator()(std::string& text) const;
	};
}

#endif