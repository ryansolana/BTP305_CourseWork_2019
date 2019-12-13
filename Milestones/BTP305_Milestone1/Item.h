// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: November 12, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <sstream>
#include "Utilities.h"

class Item : public Utilities {
	std::string m_name;

	std::string m_desc;

	size_t m_serialNumber;

	size_t m_quantity;

	static size_t m_widthField;

public:

	Item();

	Item(const std::string line);

	const std::string& getName() const;

	const unsigned int getSerialNumber();

	const unsigned int getQuantity();

	void updateQuantity();

	void display(std::ostream& os, bool full) const;


};

#endif