// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Nov 2, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Car.h"
#include <sstream>
#include <iomanip>

namespace sdds {
	bool Car::isInt(std::string str) const { //Check if the string only has digits

		bool isInt = (str.find_first_not_of("0123456789.") == std::string::npos);

		return isInt;
		//true if the string only contains digits
	};

	void Car::TrimString(std::string& str) {
		// trim spaces at beginning of line

		if ((!str.empty() && (str.find_first_not_of(' ') != std::string::npos))) {
			while (str.at(0) == ' ')
				str = str.substr(1, str.length() - 1);

			// trim spaces at end of line
			while (str.at(str.length() - 1) == ' ')
				str = str.substr(0, str.length() - 1);
		}
		else {
			str.clear();
		}
	}



	Car::Car() {

	}

	Car::~Car() {

	}

	Car::Car(std::istream& record) {

		std::string error = "Invalid record!";

		std::getline(record, m_tag, ',');
		TrimString(m_tag);

		std::getline(record, m_maker, ',');
		TrimString(m_maker);

		std::getline(record, m_condition, ',');
		TrimString(m_condition);

		if (m_condition.empty())
			m_condition = "n";

		if (!(m_condition == "n" || m_condition == "u" || m_condition == "b")) {
			throw error;
		}

		std::string temp;

		std::getline(record, temp, ',');
		TrimString(temp);
		if (isInt(temp) == true) {
			m_topSpeed = double(std::stod(temp));
		}
		else {
			throw error;
		}

	}

	std::string Car::condition() const {
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
		else if (m_condition == " " || "") {
			state = "new";
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
		out << std::setw(6) << std::setprecision(2) << std::fixed << topSpeed();
		out << " |";
	}
}