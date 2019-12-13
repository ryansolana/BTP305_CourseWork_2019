// Milestone 3

// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: November 28, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include "CustomerOrder.h"
#include <iomanip>

bool CustomerOrder::isEmpty() const
{
	return (m_name.compare("null") == 0);
}


// default construct
CustomerOrder::CustomerOrder() {

	m_name = "null";
	m_product = "null";
	m_cntItem = 0;
	m_listItem = nullptr;

}

// deconstructor
CustomerOrder::~CustomerOrder() {
	delete[] m_listItem;
	m_listItem = nullptr;
}

// custom construct
CustomerOrder::CustomerOrder(const std::string& record) : CustomerOrder(){

	Utilities util;

	bool more = true;

	size_t current_pos = 0;

	m_name = util.extractToken(record, current_pos, more);

	m_product = util.extractToken(record, current_pos, more);

	std::string item;

	m_cntItem = std::count(record.begin(), record.end(), util.getDelimiter()) - 1;

	m_listItem = new ItemInfo* [m_cntItem];

	if (m_cntItem > 0) {
		for (auto i = 0u; i < m_cntItem; ++i) {

			//extract string
			item = util.extractToken(record, current_pos, more);

			// create another product info and pointer to it
			ItemInfo* info = new ItemInfo(item);

			// push it into list
			m_listItem[i] = info;
		}
		if (util.getFieldWidth() > m_widthField) {
			m_widthField = util.getFieldWidth();
		}
	}
	else
	{
		throw std::string("No items found");
	}
}
// copy operation
CustomerOrder::CustomerOrder(const CustomerOrder& other) {
	throw "Copy operations on CustomerOrder class objects are not allowed";
}

// move operations promises not to throw error
CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept : CustomerOrder() {
	*this = std::move(other);
}

// move assignemnt op
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) {

	if (this != &other) {

		m_name = other.m_name;
		m_product = other.m_product;
		m_cntItem = other.m_cntItem;


		if (m_listItem != nullptr)
			delete[] m_listItem;

		m_listItem = other.m_listItem;
		other.m_listItem = nullptr;
	}

	return *this;
}

bool CustomerOrder::getItemFillState(std::string itemName) const {

	for (auto i = 0u; i < m_cntItem; ++i) {
		if ((*m_listItem[i]).m_itemName == itemName && (*m_listItem[i]).m_fillState == false) {

			return (*m_listItem[i]).m_fillState;
		}
	}
	return true;
}

bool CustomerOrder::getOrderFillState() const {
	bool filled = true;

	for (auto i = 0u; i < m_cntItem; ++i) {
		if ((*m_listItem[i]).m_fillState == false) {
			filled = false;
		}
	}

	// otherwise
	return filled;
}

void CustomerOrder::fillItem(Item& item, std::ostream& os) {
	for (auto i = 0u; i < m_cntItem; ++i) {
		// if items exist in inventory
		if (item.getName() == m_listItem[i]->m_itemName && m_listItem[i]->m_fillState == false) {
		
			if (item.getQuantity() > 0) {
				// reduce by 1
				item.updateQuantity();

				(*m_listItem[i]).m_serialNumber = item.getSerialNumber();
				(*m_listItem[i]).m_fillState = true;

				os << "Filled " << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;

			} else {
				os << "Unable to fill " << m_name << ", " << m_product << "[" << item.getName() << std::endl;
			}	
		} 
	}
}

void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - " << m_product << std::endl;

	for (auto i = 0u; i < m_cntItem; ++i) {
		os << "[";
		os << std::right << std::setfill('0') << std::setw(6) << (*m_listItem[i]).m_serialNumber << std::setfill(' ');
		os << "] " << std::left;
		os << std::setw(m_widthField) << (*m_listItem[i]).m_itemName;
		os << " - ";

		if ((*m_listItem[i]).m_fillState == true ){
			os << "FILLED";
		}
		else {
			os << "MISSING";
		}

		os << std::endl;
	}
}

size_t CustomerOrder::m_widthField = 0;