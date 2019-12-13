// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: November 12, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <iomanip>
#include <string>

class Utilities {
	size_t m_widthField;

	static char m_delimiter;

public:
	Utilities();

	void setFieldWidth(size_t);

	size_t getFieldWidth() const;

	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

	static void setDelimiter(const char);

	const char getDelimiter() const;

};

#endif