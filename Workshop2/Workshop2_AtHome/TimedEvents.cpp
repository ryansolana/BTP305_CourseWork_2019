// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Sept 17, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include "TimedEvents.h"

namespace sdds {

	TimedEvents::TimedEvents() {
		m_numOfRecords = 0;

		m_startTime = std::chrono::steady_clock::now();
		m_endTime = std::chrono::steady_clock::now();

		for (auto& index : m_Records) {

			index.m_eventName = "undefined";
			index.m_unitsOfTime = "undefined";
		}
	}

	void TimedEvents::startClock() {
		m_startTime = std::chrono::steady_clock::now();
	}
	void TimedEvents::stopClock() {
		m_endTime = std::chrono::steady_clock::now();
	}
	void TimedEvents::recordEvent(const char* name) {

		m_Records[m_numOfRecords].m_eventName = name;
		m_Records[m_numOfRecords].m_unitsOfTime = "nanoseconds";
		m_Records[m_numOfRecords].m_durationOfEvent = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);

		m_numOfRecords++;
	}

	std::ostream& operator<<(std::ostream& os, TimedEvents& rhs) {

		os << "--------------------------" << std::endl
			<< "Execution Times:" << std::endl
			<< "--------------------------" << std::endl;

		for (unsigned int i = 0; i < rhs.m_numOfRecords; i++) {
			os << std::setw(20) << std::left << rhs.m_Records[i].m_eventName;
			os << std::setw(12) << std::right << rhs.m_Records[i].m_durationOfEvent.count() << " " << rhs.m_Records[i].m_unitsOfTime;
			os << std::endl;
		}

		os << "--------------------------" << std::endl;
		return os;
	}

}