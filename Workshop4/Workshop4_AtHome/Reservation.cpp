// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Oct 1, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Reservation.h"

namespace sdds {

	Reservation::Reservation() {
		// set all to safestate
		m_reservationId = "null";
		m_reservationName = "null";
		m_reservationEmail = "null@null.ca";
		m_partySize = 0;
		m_resDay = 0;
		m_resHour = 0;
	}
	// 1 arg constructor
	Reservation::Reservation(const std::string& m_res) {
		std::string temp = m_res;
		int pos = 0;
		
												// looks for ws
		temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
		// format
		// ID:NAME,EMAIL,PARTY SIZE, DAY, HOUR
		//std::cout << temp << std::endl;

		pos = temp.find(":");
		m_reservationId = temp.substr(0,pos);
		//remove used part of processed string
		temp.erase(0, pos+1);

		pos = temp.find(",");
		m_reservationName = temp.substr(0, pos);
		temp.erase(0, pos+1);

		pos = temp.find(",");
		m_reservationEmail = temp.substr(0, pos);
		temp.erase(0, pos+1);

		pos = temp.find(",");
		m_partySize = std::stoi(temp.substr(0, pos));
		temp.erase(0, pos+1);

		pos = temp.find(",");
		m_resDay = std::stoi(temp.substr(0, pos));
		temp.erase(0, pos+1);

		pos = temp.find(",");
		m_resHour = std::stoi(temp.substr(0, pos));
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& obj)
	{

		os << "Reservation" << " " << obj.m_reservationId << ": ";
		os << std::setw(10) << std::right  << obj.m_reservationName << "  ";
		os << std::setw(20) << std::left  << "<" + obj.m_reservationEmail + ">";
		os << "    ";
		// invalid resHour
		if (obj.m_resHour <= 0) {
			os << "Invalid:m_resHour";
		}
		// check if breakfast time (6am to 9am) check in 24hr fmt
		else if (obj.m_resHour >= 6 && obj.m_resHour <= 9) 
		{
			os << "Breakfast";
		}
		// check if lunch time (11am to 3pm) check in 24hr fmt
		else if (obj.m_resHour >= 11 && obj.m_resHour <= 15) 
		{
			os << "Lunch";
		} 
		// check if dinner time (5pm to 9pm) check in 24hr fmt
		else if (obj.m_resHour >= 17 && obj.m_resHour <= 21) 
		{
			os << "Dinner";
		}
		else {
			os << "Drinks";
		}

		os << " on day ";
		os << obj.m_resDay;
		os << " @ ";
		os << obj.m_resHour << ":00";
		os << " ";
		os << "for" << " " << obj.m_partySize << " " << "people.";
		os << std::endl;
		return os;
	}
	bool Reservation::operator==(const Reservation& src) const
	{
		return
			m_reservationName == src.m_reservationName &&
			m_reservationEmail == src.m_reservationEmail &&
			m_partySize == src.m_partySize &&
			m_resDay == src.m_resDay &&
			m_resHour == src.m_resHour;
	}
};
