// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Oct 19, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

namespace sdds {
	class Movie {
		std::string m_title;
		std::string m_desc;
		size_t m_year;
	public:
		void Trim(std::string& str) const;
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);

		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_title);
			spellChecker(m_desc);
		}

		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
	};
}



#endif