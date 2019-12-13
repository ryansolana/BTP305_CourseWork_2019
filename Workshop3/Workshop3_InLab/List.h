// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Sept 24, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_LIST_H
#define SDDS_LIST_H

#include <iostream>


namespace sdds {

	template<typename T, int N = 0>
	class List {

		T m_Array[N];
		size_t m_sizeOfArray;
		const size_t m_maxSize;

	public:
		List() : m_sizeOfArray(0u), m_maxSize(N) { }

		size_t size() const {
			return m_sizeOfArray;
		}
		const T& operator[](size_t i) {
			return m_Array[i];
		}
		void operator+=(const T& tt) {
			if (m_sizeOfArray < m_maxSize) {
				m_Array[m_sizeOfArray] = tt;
				++m_sizeOfArray;
			}
		}

	};
}

#endif