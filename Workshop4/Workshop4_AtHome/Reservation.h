// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Oct 1, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>

namespace sdds {
	class Reservation {
		std::string m_reservationId;
		std::string m_reservationName;
		std::string m_reservationEmail;
		size_t m_partySize;
		// min 1, max 31
		unsigned int m_resDay;
		// min 1, max 24
		unsigned int m_resHour;

	public:
		Reservation();
		Reservation(const std::string& m_res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& obj);
		// helps comparing res for restaurant
		bool operator==(const Reservation& src) const;
	};
}



#endif