// Milestone 3

// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: November 28, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <iostream>
#include <string>
#include <algorithm>
#include "Item.h"

struct ItemInfo {
	std::string m_itemName;
	size_t m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};


class CustomerOrder {
	// name of customer
	std::string m_name;

	// name of product being assembled
	std::string m_product;

	// amount of components for assembly in order
	size_t m_cntItem;

	// array of pointers
	ItemInfo** m_listItem;

	// maximum width of a field for display 
	static size_t m_widthField;

public:

	bool isEmpty() const;

	// default construct
	CustomerOrder();

	// deconstructor
	~CustomerOrder();

	// custom construct
	CustomerOrder(const std::string& record);

	// deleting copy operations
	CustomerOrder(const CustomerOrder& other);
	CustomerOrder& operator=(const CustomerOrder& other) = delete;
	
	// move operations promises not to throw error
	CustomerOrder(CustomerOrder&& other) noexcept;

	// move assignemnt op
	CustomerOrder& operator=(CustomerOrder&& other);

	bool getItemFillState(std::string itemName) const;

	bool getOrderFillState() const;
	
	void fillItem(Item& item, std::ostream&);

	void display(std::ostream&) const;

};





#endif