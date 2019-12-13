// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: November 12, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include "List.h"
#include "Element.h"

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
}

#endif