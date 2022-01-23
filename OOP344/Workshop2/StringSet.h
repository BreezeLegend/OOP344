/**********************************************************
 * Name: Victor Hasnat
 * Student ID: 119485183
 * Workshop: Workshop 2 part 2
 * Seneca email: vhasnat@gmail.com
 * Section: NDD
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/




#pragma once
#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <string>
#include <fstream>

using namespace std;

namespace sdds {
	class StringSet {
	public:
		string* rs_strings;
		int rs_string_count;

		StringSet();

		~StringSet();

		StringSet(char* given_str);

		StringSet(const StringSet& given_rs);

		StringSet(StringSet&& given_rs);

		StringSet& operator=(StringSet&& given_rs);

		StringSet& operator=(const StringSet& given_rs);

		size_t size();

		string getRecord(int given_t);
		string operator[](int given_t);
	};
}

#endif