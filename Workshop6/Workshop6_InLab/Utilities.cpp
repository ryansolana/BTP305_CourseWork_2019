// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Oct 29, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Utilities.h"

namespace sdds {

	Vehicle* createInstance(std::istream& in) {
		std::string tempTag;

		Vehicle* temp = nullptr;

		std::getline(in, tempTag, ',');

		if (tempTag == "c" || tempTag == "C") {
			temp = new Car(in);
		}
		return temp;
	}
}