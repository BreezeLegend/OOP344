/**********************************************************
 * Name: Victor Hasnat
 * Student ID: 119485183
 * Workshop: Workshop 5 part 2
 * Seneca email: vhasnat@myseneca.ca
 * Section: NDD
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS_
#include "Movie.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Book.h"

namespace sdds {
	
	Movie::Movie() {
		m_releaseYear = 0;
	}
	
	
	const std::string& Movie::title() const {
		return m_title;
	}
	
	
	Movie::Movie(const std::string& strMovie) {
		std::string copy = strMovie;
		trim(copy); //pulling trim() from Book module
		size_t position;
		
		position = copy.find(',');
		m_title = copy.substr(0, position);
		trim(m_title);
		copy.erase(0, position + 1);
			
		position = copy.find(',');
		m_releaseYear = std::stoi(copy.substr(0, position));
		copy.erase(0, position + 1);
			
		m_description = copy.substr(0);
		trim(m_description);
			
		}
	
	// Overload display
	std::ostream& operator<<(std::ostream& os, const Movie& movie) {
		os << std::setw(40) << movie.m_title << " | "
		<< std::setw(4) << movie.m_releaseYear << " | "
		<< movie.m_description
		<< std::endl;
		
		return os;
		}
}

