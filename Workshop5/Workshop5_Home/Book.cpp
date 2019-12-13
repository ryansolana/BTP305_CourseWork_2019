// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Oct 19, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Book.h"

namespace sdds
{
	void Book::Trim(std::string& str) {
		// trim spaces at beginning of line
		while (str.at(0) == ' ')
			str = str.substr(1, str.length() - 1);

		// trim spaces at end of line
		while (str.at(str.length() - 1) == ' ')
			str = str.substr(0, str.length() - 1);
	}

	// default constructor
	Book::Book() {
		m_author = "null";
		m_title = "null";
		m_country = "null";
		m_desc = "null";
		m_year = 0;
		m_price = 0;
	}
	/* 1 param constructor, recieve book as string
	A constructor that receives the book as a string; this constructor is responsible to extract
	the information about the book from the parameter and store it in the attributes of the instance.
	The parameter will always have the following format: AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION
	*/

	Book::Book(const std::string& str) {
		std::string temp = str;

		std::stringstream temp2;

		temp2.str(temp);

		std::getline(temp2, m_author, ',');
		Trim(m_author);

		std::getline(temp2, m_title, ',');
		Trim(m_title);

		std::getline(temp2, m_country, ',');
		Trim(m_country);

		std::getline(temp2, temp, ',');
		Trim(temp);
		m_price = atof(temp.c_str());

		std::getline(temp2, temp, ',');
		Trim(temp);
		m_year = size_t(std::stoul(temp));

		std::getline(temp2, temp);
		Trim(temp);
		m_desc = temp;
	}

	// query that returns title of book
	const std::string& Book::title() const {
		return m_title;
	}
	// query that returns publication country
	const std::string& Book::country() const {
		return m_country;
	}
	// query that returns publication year
	const size_t Book::year() const {
		return m_year;
	}
	// returns price by reference, can update price
	double& Book::price()  {
		return m_price;
	}

	std::ostream& operator<<(std::ostream& os, const Book& obj) {
		os << std::setw(20) << obj.m_author << " | ";

		os << std::setw(22) << obj.m_title << " | ";

		os << std::setw(5) << obj.m_country << " | ";

		os << std::setw(4) << obj.m_year << " | ";

		os << std::setw(6) << std::fixed << std::setprecision(2) << obj.m_price << " | ";

		os << std::setw(6) << obj.m_desc << std::endl;

		return os;
	}

}