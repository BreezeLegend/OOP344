/**********************************************************
 * Name: Victor Hasnat
 * Student ID: 119485183
 * Workshop: Workshop 5 part 2
 * Seneca email: vhasnat@myseneca.ca
 * Section: NDD
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS_
#include "SpellChecker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

namespace sdds {


    void SpellChecker::Trim(std::string& str) {

		while (str.at(0) == ' ')
			str = str.substr(1, str.length() - 1);


		while (str.at(str.length() - 1) == ' ')
			str = str.substr(0, str.length() - 1);


	}
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename); //load content of file that has mispelled words
		unsigned int firstSpace;
		std::string tmp; 
		if (!file.is_open()) { //if file is missing
			throw "Bad file name!";
		}

		// Looking for a size of an array in a for loop
		// NOTE: sizeof( myArray ) will get the total number of bytes allocated for that array.
		// Find the number of elements in the array by dividing by the size of one element in the array: sizeof( myArray[0] )
		// for i less than mumber of element in m_badWords
		for (size_t i = 0; i < sizeof(m_badWords) / sizeof(m_badWords[0]); i++) {
			//Each line from the file is in the format BAD_WROD GOOD_WORD so load both
			//the two fields can be separated by any number of spaces.
			 std::getline(file, tmp);
			 	firstSpace = tmp.find(' '); // Find first space 
				m_badWords[i] = tmp.substr(0, firstSpace); // Anything before the first space represents the bad_word
				m_goodWords[i] = tmp.substr(firstSpace, tmp.length() - 1); //anything after the fist space represents the good word
                m_badWodrs_Count[i]=0;
				Trim(m_badWords[i]);
				Trim(m_goodWords[i]);
				
		}
	}

	// FUNCTOR
	void SpellChecker::operator()(std::string& text){
		size_t word = 0;

		//if size of array is less than i = 0, i++
		for (size_t i = 0; i < sizeof(m_badWords)/ sizeof(m_badWords[0]); i++) {
			word = text.find(m_badWords[i]); // word = any bad word
			if (word != std::string::npos) { // if parameter 'text' contains m_badWords at least once in the whole
				do {
                    m_badWodrs_Count[i]++;
					text.replace(word, m_badWords[i].size(), m_goodWords[i]); //replace it
					word = text.find(m_badWords[i]); //then keep looking
				} while (word != std::string::npos);
		}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{    out <<"Spellchecker Statistics"<<std::endl;
       for (size_t i = 0; i < sizeof(m_badWords)/ sizeof(m_badWords[0]); i++)
       {  
           out <<std::setw(15)<< std::right <<m_badWords[i]<<": "<<m_badWodrs_Count[i]<<" replacements"<<std::endl;
       }

	}
}
