/**********************************************************
 * Name: Victor Hasnat
 * Student ID: 119485183
 * Workshop: Workshop 7 part 2
 * Seneca email: vhasnat@myseneca.ca
 * Section: NDD
 **********************************************************/


#ifndef _SDDS_SongCollection_H_
#define _SDDS_SongCollection_H_

//#include <stdio.h>
#include <vector>
#include <iostream>
#include <list>

namespace sdds {
	
	struct Song {
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price = 0;
		int m_releaseYear = 0;
		int m_songLength = 0;
	};
	
	class SongCollection {
		
		std::vector<sdds::Song> m_song; //manages a collection of objects of type Song.
	
	public:
		SongCollection(std::string file);
		void display(std::ostream& out) const;
		std::string& trim(std::string &str) ;
		
		//at_home
		void sort(std::string field);
		void cleanAlbum();
		bool inCollection(std::string artist) const;
		std::list<Song> getSongsForArtist(std::string artist) const;
	};
	
	//FREE HELPER
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}

#endif /* _SDDS_SongCollection_H_ */
