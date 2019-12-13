// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: November 12, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Utilities.h"

Utilities::Utilities() {
	m_widthField = 0u;
}

void Utilities::setFieldWidth(size_t size) {
	m_widthField = size;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

const std::string Utilities::extractToken(const std::string& line, size_t& current_pos, bool& more) {

	// more equals token found

	more = false;
	std::string token;
	size_t next_pos = 0;

	// check if current_pos is valid
	if (line.length() > current_pos) {
		// find at what index the delimiter is
		next_pos = line.find(m_delimiter, current_pos);

		if (next_pos != std::string::npos) {
			token = line.substr(current_pos, next_pos - current_pos);
		}
		else {
			token = line.substr(current_pos);	
		}
			
	}
		

	//validate token, do if token was found
	if (!token.empty()) {
		more = true;

		//move current position after the delimiter
		current_pos = next_pos + 1;

		if (token.length() > m_widthField) {
			m_widthField = token.length();
		}
	}
	else {
		throw "Unsuccessful token extraction";
	}

	return token;
}

//static function
void Utilities::setDelimiter(const char c) {
	m_delimiter = c;
}

const char Utilities::getDelimiter() const {
	return m_delimiter;
}

char Utilities::m_delimiter = 'l';
	
