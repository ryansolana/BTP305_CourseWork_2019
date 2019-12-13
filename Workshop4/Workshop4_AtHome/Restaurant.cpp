// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Oct 5, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Restaurant.h"
#include "Reservation.h"

namespace sdds {
	// default constructor
	Restaurant::Restaurant() {
		m_reservations = nullptr;
		m_size = 0;
	}
	// deconstructor
	Restaurant::~Restaurant() {
		delete[] m_reservations;
		m_reservations = nullptr;
	}
	// custom constructor
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {
		// safe state
		m_reservations = nullptr;
		m_size = 0;

		if (reservations != nullptr) {
			// allocate new memory if not nullptr
			m_reservations = new Reservation[cnt];
			// set size of for reservations
			m_size = cnt;

			for (unsigned int i = 0; i < size(); ++i) // create clone for all elements
			{
				m_reservations[i] = Reservation(*reservations[i]);
			}
		}
	}
	// copy constructor
	Restaurant::Restaurant(const Restaurant& src) {
		// safe state
		m_reservations = nullptr;
		m_size = 0;

		*this = src;
	}
	// copy assignment operator
	Restaurant& Restaurant::operator=(const Restaurant& src) {
		if (&src != this) {

			if (m_reservations != nullptr) {
				delete[] m_reservations;
				m_reservations = nullptr;
			}

			m_size = src.m_size;
			m_reservations = new Reservation[src.m_size];
			
			// copy all reservations
			for (auto i = 0u; i < m_size; ++i) {
				m_reservations[i] = src.m_reservations[i];
			}
		}
		return *this;
	}

	// move constructor
	Restaurant::Restaurant(Restaurant&& src) {
		// safe state
		m_reservations = nullptr;
		m_size = 0;

		*this = std::move(src);
	}

	// move assignment operator
	Restaurant& Restaurant::operator=(Restaurant&& src) {
		if (&src != this) {
			// dellocation of old memory
			delete[] m_reservations;
			m_reservations = nullptr;

			// move pointers
			m_reservations = src.m_reservations;
			m_size = src.m_size;

			// set to safestate
			src.m_reservations = nullptr;
			src.m_size = 0;
		}
		return *this;
	}

	size_t Restaurant::size() const {
		return m_size;
	}
	std::ostream& operator<<(std::ostream& os, const Restaurant& src) {
		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant" << std::endl;
		os << "--------------------------" << std::endl;

		if (src.size() == 0) {
			os << "The object is empty!" << std::endl;
		}
		else {
			for (unsigned int i = 0; i < src.size(); ++i) {
				os << src.m_reservations[i];
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}

