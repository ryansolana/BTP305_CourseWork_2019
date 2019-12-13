// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: November 5, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>

#include "SongCollection.h"


namespace sdds {
	// SONG

	Song::Song() {
		m_artist	=	"null";
		m_title		=	"null";
		m_album		=	"null";
		m_releaseYear	=	"null";
		m_price		=	0;
		m_length	=	0;
	}

	Song::Song(const std::string& line) {

		auto trimStr = [](std::string str){
			// check if str is empty and if all characters are spaces
			if ((!str.empty() && !std::all_of(str.begin(), str.end(), isspace))) {
				// check beginning for spaces and remove
				while (str.at(0) == ' ')
					str = str.substr(1, str.length() - 1);
				// check end for spaces and remove
				while (str.at(str.length() - 1) == ' ')
					str = str.substr(0, str.length() - 1);
			}
			return str;
		};

		if (!line.empty() && line.length() >= 90) {

			m_title 	= trimStr(line.substr(0, 24));
			m_artist 	= trimStr(line.substr(24, 25));
			m_album 	= trimStr(line.substr(50, 25));
			m_releaseYear 	= trimStr(line.substr(75, 5));

			// trim string and then convert it to a size_t
			m_length 	= stoul(trimStr(line.substr(80, 5)));
			m_price 	= stod((line.substr(85, 5)));

		}
	}

	// SONG_COLLECTION

	// constructors
	SongCollection::SongCollection(){
		m_size = 0;
	}


	SongCollection::SongCollection(const char* fileName) {
		std::ifstream file(fileName);
		std::string line;

		// check if the file is good
		if (file.good()) {
			while (std::getline(file, line)) {
				if (!line.empty()) {
					Song temp(line);
					// insert song into collection of songs
					m_songs.push_back(temp);
				}
			}
		}
		else {
			std::string err = "File doesn't exist!";
			std::cout << err;
			throw err;
		}
	}


	void SongCollection::display(std::ostream& os) {

		auto displaySong = [&](const Song song) {
			os << song << std::endl;
		};

		std::for_each(m_songs.begin(), m_songs.end(), displaySong);
	}

	std::ostream& operator<<(std::ostream& os, const Song& song) {
		auto playtime = [&]() {
			int minutes;
			int seconds;

			minutes = song.m_length / 60;
			seconds = song.m_length % 60;

			if (seconds < 10) {
				os << minutes << ":0" << seconds;
			}
			else {
				os << minutes << ":" << seconds;
			}
		};

		os << "| ";
		os << std::left << std::setw(20) << song.m_title;
		os << " | ";
		os << std::left << std::setw(15) << song.m_artist;
		os << " | ";
		os << std::left << std::setw(20) << song.m_album;
		os << " | ";
		os << std::right << std::setw(6) << song.m_releaseYear;
		os << " | ";
		playtime();
		os << " | ";
		os << std::setprecision(2) << std::fixed << song.m_price;
		os << " |";

		return os;
	}
}

