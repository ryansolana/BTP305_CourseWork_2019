// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: November 12, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	/*
	This function compares the elements in the two received lists for common product codes and builds the
	user-friendly list from the matching pairs. For each successful comparison, your function allocates
	dynamic memory of Product type using that description and the price. Your function then validates the
	Product object and adds it to its list. Your function returns a copy of this list.
	*/
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		Product* temp = nullptr;

		// for every element in desc
		for (auto i = 0u; i < desc.size(); ++i) {

			//for every element in price
			for (auto a = 0u; a < price.size(); ++a) {

				// compare the codes
				if (desc[i].code == price[a].code) {
					// if match then
					temp = new Product(desc[i].desc, price[a].price);

					// validate the new dynamically allocated object
					temp->validate();

					// if good after validation, push temp into priceList
					priceList += temp;

					delete temp;

					temp = nullptr;
				}

			}
		}
		return priceList;
	}

	// smart pointers implementation
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;

		// for every element in desc
		for (auto i = 0u; i < desc.size(); ++i) {

			//for every element in price
			for (auto a = 0u; a < price.size(); ++a) {

				// compare the codes
				if (desc[i].code == price[a].code) {
					// if match then
					std::unique_ptr<Product> temp(new Product(desc[i].desc, price[a].price));

					// validate the new dynamically allocated object
					temp->validate();

					// if good after validation, push temp into priceList
					priceList += temp;
				}

			}
		}
		return priceList;
	}
}