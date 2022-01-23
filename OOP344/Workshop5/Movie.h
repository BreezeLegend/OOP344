/**********************************************************
 * Name: Victor Hasnat
 * Student ID: 119485183
 * Workshop: Workshop 5 part 2
 * Seneca email: vhasnat@myseneca.ca
 * Section: NDD
 **********************************************************/

#ifndef _SDDS_Movie_H_
#define _SDDS_Movie_H_

#include <string>
#include <iostream>
#include "SpellChecker.h"

namespace sdds {
	
	class Movie {
		
	private:
		std::string m_title;
		size_t m_releaseYear;
		std::string m_description;
	
	public:
		Movie();
		//~Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
		
		//Template function
		template <typename T>
		void fixSpelling(T &spellChecker){
			spellChecker.operator()(m_title);
			spellChecker.operator()(m_description);
		}
	};
}

#endif /* _SDDS_Movie_H_*/