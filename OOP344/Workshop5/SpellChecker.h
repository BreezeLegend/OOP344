/**********************************************************
 * Name: Victor Hasnat
 * Student ID: 119485183
 * Workshop: Workshop 5 part 2
 * Seneca email: vhasnat@myseneca.ca
 * Section: NDD
 **********************************************************/

#ifndef _SDDS_SpellChecker_H_
#define _SDDS_SpellChecker_H_

#include <iostream>

namespace sdds {

	class SpellChecker {
		private:
		std::string m_badWords[6];
		std::string m_goodWords[6];
		int m_badWodrs_Count[6];
		public:
		SpellChecker(const char* filename);
		void Trim(std::string& str);
		void operator()(std::string& text) ;
		void showStatistics(std::ostream& out) const;
	};
}
#endif /*  _SDDS_SpellChecker_H_ */