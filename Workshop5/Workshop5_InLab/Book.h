// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Oct 9, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <iomanip>
#include <sstream>


namespace sdds {

	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_country;
		std::string m_desc;
		unsigned int m_year;
		double m_price;
		

	public:

		void Trim(std::string& str) const;
		// default constructor
		Book();
		/* 1 param constructor, recieve book as string 
		A constructor that receives the book as a string; this constructor is responsible to extract
		the information about the book from the parameter and store it in the attributes of the instance. 
		The parameter will always have the following format: AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION
		*/
		Book(const std::string&);

		// query that returns author of book
		const std::string& author() const;
		// query that returns desc of book
		const std::string& desc() const;
		// query that returns title of book
		const std::string& title() const;
		// query that returns publication country
		const std::string& country() const;
		// query that returns publication year
		const size_t year() const;
		// returns price by reference, can update price
		double& price();

		friend std::ostream& operator<<(std::ostream& os, const Book& obj);
		
	};





}


#endif