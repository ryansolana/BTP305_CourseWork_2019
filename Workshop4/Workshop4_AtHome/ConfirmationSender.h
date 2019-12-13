// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Oct 5, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds {

	class ConfirmationSender{

		const Reservation** m_reservations;
		size_t m_size;
		

	public:
		
		// basic constructor and deconstructor
		ConfirmationSender();
		~ConfirmationSender();

		// copy constructor 		// copy assignment op
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender& operator=(const ConfirmationSender& src);

		// move constructor 		// move assignment op
		ConfirmationSender(ConfirmationSender&& src);
		ConfirmationSender& operator=(ConfirmationSender&& src);
		
		// op overloads
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);

		// insertion operator
		friend std::ostream& operator<<(std::ostream&, const ConfirmationSender& src);
		int findResIndex(const Reservation& res) const;
	};



}



#endif