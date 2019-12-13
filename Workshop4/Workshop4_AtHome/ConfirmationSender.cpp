// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Oct 5, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "ConfirmationSender.h"

namespace sdds {

	int ConfirmationSender::findResIndex(const Reservation& res) const
	{
		int index = -1; // res does not exist assumption

		// compare res with current reservations
		for (unsigned int i = 0; i < m_size; ++i) {
			
			if (res == Reservation(*m_reservations[i])) 
			{ 
				// set index
				index = i;
				// stop for loop
				break; 
			}
		}
		return index;
	}

	ConfirmationSender::ConfirmationSender()
	{
		m_reservations = nullptr;
		m_size = 0u;
	}

	// copy constructor
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
	{
		*this = src;
	}

	// move constructor
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)
	{
		*this = std::move(src);
	}

	ConfirmationSender::~ConfirmationSender()
	{
		m_reservations = nullptr;
		m_size = 0;
	}

	// copy assignment op
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
	{
		if (this != &src) {
			// shallow copy
			m_size = src.m_size;

			// deep copy
			m_reservations = new Reservation const* [src.m_size];
			for (auto i = 0u; i < (src.m_size); ++i)
				m_reservations[i] = src.m_reservations[i];
		}
		return *this;
	}

	// move assignment op
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src)
	{
		if (this != &src) {
			// shallow copy
			m_size = src.m_size;
			src.m_size = 0;
			// deep copy
			m_reservations = src.m_reservations;
			src.m_reservations = nullptr;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		// find res index
		int index = findResIndex(res);

		// setup temp pointer
		const Reservation** temp = nullptr;

		// if res does not exist in object
		if (index == -1) { 

			// allocate memory for new array
			temp = new Reservation const* [m_size + 1]; 

			// copy over old info to tmp obj
			for (unsigned int i = 0; i < m_size; ++i)
				temp[i] = m_reservations[i];

			temp[m_size] = &res;

			// transfer over address
			m_reservations = temp; 
			// show changes
			m_size++; 

			// deallocate memory for temp
			temp = nullptr; //untether address from tmp

		}
		return *this;

	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		// find res index
		int index = findResIndex(res);

		// setup temp pointer
		const Reservation** temp = nullptr;

		// if res does not exist in object
		if (index != -1) { 

			// check if res is final object in array
			if (index != static_cast<int>(m_size - 1u)) { 
				m_reservations[index] = nullptr;
				m_reservations[index] = m_reservations[m_size - 1u];
			}

			// resizing the array
			temp = new Reservation const* [m_size - 1u]; 

			//copy over old info to tmp obj
			for (unsigned int i = 0; i < (m_size - 1u); ++i)  
				temp[i] = m_reservations[i];

			// transfer over address
			m_reservations = temp; 
			// show changes
			m_size--; 

			// set temp to nullptr
			temp = nullptr; 

		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& src)
	{
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;

		if (src.m_size != 0) {
			for (auto i = 0u; i < src.m_size; ++i)
				os << *src.m_reservations[i];
		}
		else {
			os << "The object is empty!" << std::endl;
		}

		os << "--------------------------" << std::endl;

		return os;
	}

}