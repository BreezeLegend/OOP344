/**********************************************************
 * Name: Victor Hasnat
 * Student ID: 119485183
 * Workshop: Workshop 5 part 2
 * Seneca email: vhasnat@myseneca.ca
 * Section: NDD
 **********************************************************/


#ifndef _SDDS__BOOK_H_
#define _SDDS__BOOK_H_
#include <iostream>
#include "SpellChecker.h"

namespace sdds {

    class Book {
        std::string m_author;
        std::string m_title;
        std::string m_country;
        size_t m_year;
        double m_price;
        std::string m_desc;

    public:
        Book();
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();
        Book(const std::string& strBook);
		
		const std::string &description() const ;
        friend std::ostream& operator<<(std::ostream& os, const Book& book);
	
		
		//Template function
			template <typename T>
		void fixSpelling(T& spellChecker){
			spellChecker.operator()(m_desc);
		}
    };
		void trim(std::string& str);

}

#endif //_SDDS__BOOK_H_