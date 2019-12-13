// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Oct 5, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include <iostream>
#include <ostream>
#include "Reservation.h"

namespace sdds {

	class Restaurant {
		Reservation* m_reservations;
		size_t m_size;
	public:
		//basic constructor, deconstructor
		Restaurant();
		~Restaurant();

		//custom constructor
		Restaurant(Reservation* reservations[], size_t cnt);

		//copy constructor
		Restaurant(const Restaurant& src);
		//copy assignment operator
		Restaurant& operator=(const Restaurant& src);

		//move constructor
		Restaurant(Restaurant&& src);
		//move assignment operator
		Restaurant& operator=(Restaurant&& src);

	

		size_t size() const;

		friend std::ostream& operator<<(std::ostream&, const Restaurant& src);
	};



}



#endif