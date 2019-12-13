// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Nov 2, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {
	class Car : public Vehicle {
		std::string m_tag;
		std::string m_maker;
		std::string m_condition;
		double m_topSpeed;

	public:
		bool isInt(std::string str) const;
		void TrimString(std::string& str);

		Car();
		~Car();
		Car(std::istream& record);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;

	};


}



#endif