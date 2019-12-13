// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Nov 2, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include <iostream>
#include "Car.h"

namespace sdds {
	class Racecar : public Car {
		double m_booster;
	public:
		Racecar();
		Racecar(std::istream& is);
		void display(std::ostream& os) const;
		double topSpeed() const;
	};

}

#endif