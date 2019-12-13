// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Oct 29, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Car.h"
#include <sstream>
#include <iomanip>

namespace sdds {
	void Car::TrimString(std::string& str) {
		// trim spaces at beginning of line
		while (str.at(0) == ' ')
			str = str.substr(1, str.length() - 1);

		// trim spaces at end of line
		while (str.at(str.length() - 1) == ' ')
			str = str.substr(0, str.length() - 1);
	}

	Car::Car() {

	}

	Car::~Car() {

	}
	Car::Car(std::istream& record) {
		std::string temp;

		std::getline(record, m_maker, ',');
		TrimString(m_maker);

		std::getline(record, m_condition, ',');
		TrimString(m_condition);

		std::getline(record, temp, '\n');
		TrimString(temp);
		m_topSpeed = double(std::stod(temp));

	}

	std::string Car::condition() const{
		std::string state;

		if (m_condition == "n") {
			 state = "new";
		}
		else if (m_condition == "u") {
			state = "used";
		}
		else if (m_condition == "b") {
			state = "broken";
		}
		else {
			state = "null";
		}
		return state;
	}

	double Car::topSpeed() const {
		//returns double
		return m_topSpeed;
	}

	void Car::display(std::ostream& out) const {
		out << "| ";
		out << std::right << std::setw(10) << m_maker;
		out << " | ";
		out << std::left << std::setw(6) << condition();
		out << " | ";
		out << std::setw(6) << std::setprecision(2) << std::fixed << m_topSpeed;
		out << " |";
	}
}