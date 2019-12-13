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
#include <numeric>

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

	SongCollection::SongCollection(const std::string fileName) {
		std::ifstream file(fileName);
		std::string line;
		m_size = 0;

		if (fileName == "songs.txt") {// continue
		}
		else {
			throw "File name mismatch!";
		}
		
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
		//place size of collection into m_size
		m_size = m_songs.size();
	}


	void SongCollection::display(std::ostream& os) const {

		auto getTotalSeconds = [](int sum, const Song song) {
			return song.m_length + sum;
		};

		size_t totalSeconds = std::accumulate(m_songs.begin(), m_songs.end(), 0, getTotalSeconds);
		size_t minutes = totalSeconds / 60;
		size_t hours = minutes / 60;

		totalSeconds %= 60;
		minutes -= 60;

		auto displaySong = [&](const Song song) {
			os << song << std::endl;
		};

		std::for_each(m_songs.begin(), m_songs.end(), displaySong);
		os << "----------------------------------------------------------------------------------------" << std::endl;
		os << "|                                                        Total Listening Time: " << hours 
			<< ":" 
			<< minutes 
			<< ":"
			<< totalSeconds 
			<< " |" << std::endl;
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

	// At Home

	void SongCollection::sort(const std::string field) {
		//s1 means song1, etc
		auto compare = [&](Song s1, Song s2) {
			if (field == "title") {
				return s2.m_title > s1.m_title;
			}
			else if (field == "album") {
				return s2.m_album > s1.m_album;
			}
			else if (field == "length") {
				return s2.m_length > s1.m_length;
			}
			else {
				std::string err = "Invalid field!";
				std::cout << err << std::endl;
				throw err;
			}
		};
		std::sort(m_songs.begin(), m_songs.end(), compare);
	}

	void SongCollection::cleanAlbum() {
		auto clearAlbum = [&](Song& song) {
			if (song.m_album == std::string("[None]")) {
				song.m_album.clear();
			}
		};

		std::for_each(m_songs.begin(), m_songs.end(), clearAlbum);
	}

	bool SongCollection::inCollection(const std::string artistName){
		bool result = std::any_of(m_songs.begin(), m_songs.end(), [&](const Song& song) {return song.m_artist == std::string(artistName);});

		return result;
	}

	std::list<Song> SongCollection::getSongsForArtist(const std::string artistName) const {
		//create list to hold the songs of the artist 
		std::list<Song> artistSongs(m_songs.size());

		auto iterator = std::copy_if(m_songs.begin(), m_songs.end(), artistSongs.begin(), [&](const Song& song) {return song.m_artist == std::string(artistName); });
		
		// resize list to the size of the distance between the begin and iterator
		artistSongs.resize(std::distance(artistSongs.begin(), iterator));

		return artistSongs;
	}
}

