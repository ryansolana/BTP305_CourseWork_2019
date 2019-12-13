// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Sept 17, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef TEXT_H
#define TEXT_H

namespace sdds{

	class Text {
		// size of array, or number of elements 
		size_t m_size;
		std::string* m_strings;

	public:
		//	default constructor
		Text();
		//	destructor
		~Text();
		//	custom constructor
		Text(const char* fileName);
		//	copy constructor
		Text(const Text& src);
		//	copy assignment operator
		Text& operator=(const Text& src);
		//	query returning num of records in current object
		size_t size() const;
	};

}

#endif