// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Oct 19, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Movie.h"

namespace sdds {
	void Movie::Trim(std::string& str) const {
		// trim spaces at beginning of line
		while (str.at(0) == ' ')
			str = str.substr(1, str.length() - 1);

		// trim spaces at end of line
		while (str.at(str.length() - 1) == ' ')
			str = str.substr(0, str.length() - 1);
	}

	Movie::Movie() {
		m_title = "null";
		m_year = 0;
		m_desc = "null";

	}
	const std::string& Movie::title() const {
		return m_title;
	}
	Movie::Movie(const std::string& strMovie) {
		std::string temp = strMovie;

		std::stringstream temp2;

		temp2.str(temp);
		
	
		std::getline(temp2, m_title, ',');
		Trim(m_title);

		std::getline(temp2, temp, ',');
		Trim(temp);
		m_year = size_t(std::stoul(temp));

		std::getline(temp2, temp);
		Trim(temp);
		m_desc = temp;
	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie) {
		os << std::setw(40) << movie.m_title << " | ";
		os << std::setw(4) << movie.m_year << " | ";
		os << movie.m_desc << std::endl;

		return os;
	}
}

