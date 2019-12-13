// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Sept 17, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <string>

namespace sdds {

	typedef std::chrono::steady_clock::time_point time_point;
	typedef std::chrono::steady_clock::duration duration;

	class TimedEvents {
		size_t m_numOfRecords;
		time_point m_startTime;
		time_point m_endTime;

		struct {
			std::string m_eventName;
			std::string m_unitsOfTime;
			duration m_durationOfEvent;
		} m_Records[7];

	public:
		//default constructor 
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char*);
		friend std::ostream& operator<<(std::ostream& os, TimedEvents& rhs);
	};

}

#endif