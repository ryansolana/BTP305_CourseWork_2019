// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Sept 17, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"

namespace sdds {
	//	default constructor
	Text::Text() {
		m_size = 0;
		m_strings = nullptr;
	}
	//	destructor
	Text::~Text() {
		delete[] m_strings;
		m_strings = nullptr;
	}
	//	custom constructor
	Text::Text(const char* fileName) {
		m_size = 0;

		std::string line;
		std::ifstream file(fileName); // open, connect fin to filename for reading

		// count how many strings there are first
		if (file.is_open()) {
			while (!file.eof()) {
				std::getline(file, line, ' ');
				m_size++;
				//db	
			}
			m_size--;

			//once num of strings are counted then allocate memory for amount of strings
			m_strings = nullptr;
			m_strings = new std::string[m_size];

			int index = 0;
			
			while (!file.eof()) {
				//std::getline(file, line, ' ');
				file >> m_strings[index];
				index++;
			}
		}
		else {
			std::cout << "failed to open file" << std::endl;
			m_strings = nullptr;
			m_size = 0u;
		}
	}

	//	copy constructor
	Text::Text(const Text& src) {
		if (this != &src) {
			m_size = src.m_size;

			//allocate new
			if (src.m_strings != nullptr) {
				m_strings = new std::string[src.m_size];
				for (unsigned int i = 0; i < src.m_size; i++) {
					m_strings[i] = src.m_strings[i];
				}
			}
			else {
				std::cout << "self assignment detected";
				m_strings = nullptr;
				m_size = 0u;
			}
		}
	
	}
	//	copy assignment operator
	Text& Text::operator=(const Text& src) {
		//check self assignment
		if (this != &src) {
			m_size = src.m_size;

			//deallocate old memory
			delete[] m_strings;

			//allocate new
			if (src.m_strings != nullptr) {
				m_strings = new std::string[src.m_size];
				for (unsigned int i = 0; i < src.m_size; i++) {
					m_strings[i] = src.m_strings[i];
				}
			}
			else {
				std::cout << "self assignment detected";
				m_strings = nullptr;
				m_size = 0u;
			}
		}
		return *this;
	}
	//	query returning num of records in current object
	size_t Text::size() const {
		return m_size;
	}
}