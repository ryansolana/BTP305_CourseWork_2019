// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Sept 28, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_LVPAIR_H
#define SDDS_LVPAIR_H

#include "List.h"
#include <iostream>
#include <string>
#include <iomanip>

namespace sdds {

	template<typename L, typename V>
	class LVPair {
		L m_Label;
		V m_Value;
	public:
		LVPair() : m_Label { "undefined" }, m_Value{ 0 }{ }

		LVPair(const L& aa, const V& bb) : m_Label(aa), m_Value(bb) { }

		const L& key() const {
			return m_Label;
		}
		const V& value() const {
			return m_Value;
		}
		virtual void display(std::ostream& os) const {
			os << m_Label << " : " << m_Value << std::endl;
		}
	};

	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}

	//
	// Upgraded module begins here
	//

	template<typename L, typename V>
	class SummableLVPair : public LVPair<L, V> {
		// initial value for summation
		static V m_initialValue;
		// variable for formatting, changes everytime new pair is added to collection
		static size_t m_minFieldWidth;
	public:
		// static public member
		static const V& getInitialValue() {
			return m_initialValue;
		}
		// default constructor
		SummableLVPair() {};

		// 2 arg constructor
		SummableLVPair(const L& lbl, const V& val) : sdds::LVPair<L, V>(lbl,val) {
			if (lbl.size() > m_minFieldWidth)
				// set lbl.size() which is int or size_t to the field width
				m_minFieldWidth = lbl.size();
		};

		// query
		V sum(const L& lbl, const V& val) const {

			// return result of ternary operator
			return this->key() == lbl ? val + this->value() : this->value();
		}

		void display(std::ostream& os) const {
			// setw to m_minFieldWidth, left hand justification
			os << std::left << std::setw(m_minFieldWidth);
			// explicitly call LVPair display 
			LVPair<L, V>::display(os);
			// right side justify
			os << std::right;

		}

	
	};
	// outside class static definition
	template<typename L, typename V>
	size_t SummableLVPair<L, V>::m_minFieldWidth = 0;



	// specializations

	// explicit definition
	template<>
	std::string SummableLVPair<std::string, std::string>::m_initialValue = "";

	// explicit definition
	template<>
	int SummableLVPair<std::string, int>::m_initialValue = 0;

	// sum function specialization
	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& lbl, const std::string& val) const {

		//create temp string
		std::string temp;

		//check if true, then concat. if false then dont
		if (lbl.compare(this->key()) == 0 && val.compare(m_initialValue) != 0) {
			temp = val + ", " + this->value();
		} else {
			temp = this->value();
		}
		return temp;
	}

}


#endif