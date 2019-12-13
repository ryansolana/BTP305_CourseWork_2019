// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: November 12, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Item.h"
#include "Utilities.h"

Item::Item() {
	m_name = "null";
	m_desc = "null";
	m_serialNumber = 0;
	m_quantity = 0;
	m_widthField = 0u;
}

Item::Item(const std::string line) {
	// format: m_name[?]m_serialNumber[?]m_quantity[?]m_desc

	Utilities util;

	bool more = true;
	size_t current_pos = 0;

	m_name = util.extractToken(line, current_pos, more);

	m_serialNumber = std::stoi(util.extractToken(line, current_pos, more));

	m_quantity = std::stoul(util.extractToken(line, current_pos, more));

	if (util.getFieldWidth() > m_widthField) {
		m_widthField = util.getFieldWidth();
	}

	m_desc = util.extractToken(line, current_pos, more);	
}

const std::string& Item::getName() const {
	return m_name;
}

const unsigned int Item::getSerialNumber() {
	return m_serialNumber++;
}

const unsigned int Item::getQuantity() {
	return m_quantity;
}

void Item::updateQuantity() {
	if (m_quantity != 0) {
		m_quantity--;
	}
}

void Item::display(std::ostream& os, bool full) const {

	os << std::setw(m_widthField) << std::left << getName();
	os << " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "]" << std::setfill(' ');

	if (full == true){
		os << " Quantity: " << std::setw(m_widthField) << std::left << m_quantity <<
			" Description: " << m_desc;
	}
	os << std::endl;

}

size_t Item::m_widthField = 0u;
