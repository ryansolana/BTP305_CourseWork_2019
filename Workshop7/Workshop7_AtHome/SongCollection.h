// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: November 5, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include <vector>
#include <list>

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

namespace sdds {

	struct Song {
		std::string m_title;
		std::string m_artist;
		std::string m_album;
		std::string m_releaseYear;
		size_t m_length;
		double m_price;

		Song();
		Song(const std::string& line);
	};

	class SongCollection {
		std::vector<Song> m_songs;
		size_t m_size;

	public:
		SongCollection();
		SongCollection(const std::string file);

		//prints out content of collection
		void display(std::ostream& out) const;

		void sort(const std::string field);

		void cleanAlbum();

		bool inCollection(const std::string artistName);

		std::list<Song> getSongsForArtist(const std::string artistName) const;
		
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);

}


#endif