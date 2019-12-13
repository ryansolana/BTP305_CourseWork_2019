// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Oct 19, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "SpellChecker.h"

namespace sdds {

	void SpellChecker::TrimString(std::string& str) {

		//trim beginning whitespaces
		while (str.at(0) == ' ')
			str = str.substr(1, str.length() - 1);

		//trim end whitespaces
		while (str.at(str.length() - 1) == ' ')
			str = str.substr(0, str.length() - 1);
	}

	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);

		if (file.good()) {

			// for every line
			std::string line;
			size_t pos;

			for (auto i = 0u; i < 5; ++i) {
				//grab the line
				std::getline(file, line);

				//find the first space in line
				pos = line.find(' ');

				//from the beginning to the space separating the bad and good words
				m_badWords[i] = line.substr(0, pos);

				//from the space to the end, including the space (-1)
				m_goodWords[i] = line.substr(pos, line.length() - 1);

				//make sure no spaces exist in the good and bad words
				TrimString(m_badWords[i]);
				TrimString(m_goodWords[i]);
			}
		}
		else {
			throw "Bad file name!";
		}
	}

	void SpellChecker::operator()(std::string& text) const {
		// for every bad word...
		size_t pos = 0;

		for (auto i = 0u; i < 5; ++i) {
			// if badword has a match then store index into pos
			while (text.find(m_badWords[i]) != std::string::npos) {
				pos = text.find(m_badWords[i]);
				// replace the text with the compared bad word to equivalent good word
				text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
			}
		}
	}
}
