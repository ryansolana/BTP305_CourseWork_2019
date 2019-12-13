// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Nov 2, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <sstream>
#include <iostream>

#include "Utilities.h"

namespace sdds {

	Vehicle* createInstance(std::istream& in) {

		std::string tokens; // a god damn line 
		std::string m_tag;
		std::stringstream string_stream;
		Vehicle* temp = nullptr;

		auto trimTag = [&]() { //remove spaces at the ends 
			while (m_tag[0] == ' ')
				m_tag = m_tag.substr(1, m_tag.length() - 1);


			while (m_tag[m_tag.length() - 1] == ' ')
				m_tag = m_tag.substr(0, m_tag.length() - 1);
		};



		std::getline(in, tokens);


		if (!tokens.empty()) {



			m_tag = tokens.substr(0, tokens.find(","));
			trimTag();

			//std::cout << m_tag << std::endl;

			string_stream << tokens;


			//std::cout << "line is " << tokens << std::endl;

			if (m_tag == "c" || m_tag == "C") {
				temp = new Car(string_stream);
			}
			else if (m_tag == "r" || m_tag == "R") {
				temp = new Racecar(string_stream);
			}
			else {
				std::string errMsg("Unrecognized record type: [");
				errMsg += m_tag + "]";
				throw  errMsg;
			}

		}
		return temp;
	}
}