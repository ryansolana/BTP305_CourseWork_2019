// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Oct 9, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

// Workshop 5 - Functions and Error Handling
// 2019/10 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"
#include <string>

using namespace sdds;

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];

	std::ifstream file(argv[1]);
	auto index = 0u;

	if (file.good()) {
		for (std::string line; std::getline(file, line); ) {
			if (line.at(0) != '#') {
				library[index] = Book(line);
				index++;
			}
		}
	}
	
	

	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	auto conversion = [=](Book& book) {
		if (book.country() == "US") {
			book.price() *= usdToCadRate;
		}
		if (book.country() == "UK" && (book.year() >= 1990 && book.year() <= 1999) ) {
			book.price() *= gbpToCadRate;
		}
	};


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n\n";

	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.
		for (int i = 0; i < 7; ++i){
			
			conversion(library[i]);		

		}

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n";

	return 0;
}
