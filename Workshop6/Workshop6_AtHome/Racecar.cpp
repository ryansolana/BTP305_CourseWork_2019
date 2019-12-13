// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Nov 2, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Racecar.h"
#include "Car.h"

namespace sdds {

	Racecar::Racecar() : Car()
	{
		m_booster = 0;
	}
	Racecar::Racecar(std::istream& is) : Car(is)
	{
		std::string boosterStr;
		std::getline(is, boosterStr);

		Car::TrimString(boosterStr);
		if (!boosterStr.empty()) {
			if (Car::isInt(boosterStr))
				m_booster = stod(boosterStr);
		}
	}

	void Racecar::display(std::ostream& os) const
	{
		std::string line;

		Car::display(os);
		os << "*";
	}

	double Racecar::topSpeed() const
	{
		return Car::topSpeed() + (Car::topSpeed() * m_booster);
	}

}