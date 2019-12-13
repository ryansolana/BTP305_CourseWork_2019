// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Sept 28, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_LIST_H
#define SDDS_LIST_H

#include <iostream>

namespace sdds {

	template<typename T, unsigned int N>
	class List {

		// an array of LV pairs
		T m_Array[N];
		// size of array
		size_t m_sizeOfArray;
		// maximum size
		const size_t m_maxSize;

	public:
		List() : m_sizeOfArray(0u), m_maxSize(N) { }

		size_t size() const {
			return m_sizeOfArray;
		}
		const T& operator[](int i) const{
			return m_Array[i];
		}
		void operator+=(const T& tt) {
			if (m_sizeOfArray < m_maxSize) {
				m_Array[m_sizeOfArray] = tt;
				++m_sizeOfArray;
			}
		}

	};

	//
	// Upgraded module begins here
	//

	/*
	L = type of label
	V = type of summation value
	T = type of element in collection
	N = max number of elements that can be in collection
	*/
	template<typename L, typename V, typename T, unsigned int N>
	class LVList : public List<T, N> {

	public:
		V accumulate(const L& label) const {
			// get the initial value and store into 
			V accumulation = T::getInitialValue();

			for (unsigned int i = 0u; i < this->size(); ++i) {
				// check if m_label inside the lvpair (current instance) matches this label
				if ( label == (*this)[i].key() ) {
					//give array at i, the value of sum(label, accumulator)
					accumulation = (*this)[i].sum(label, accumulation);
				}
			}

			return accumulation;
		}
	};
}

#endif