/**********************************************************
 * Name: Victor Hasnat
 * Student ID: 119485183
 * Workshop: Workshop 2 part 2
 * Seneca email: vhasnat@gmail.com
 * Section: NDD
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/



#include "StringSet.h"

namespace sdds {
	StringSet::StringSet() {
		rs_strings = nullptr;
		rs_string_count = 0;
	}

	StringSet::~StringSet() {
		delete[] rs_strings;
		rs_strings = nullptr;
	}

	StringSet::StringSet(char* given_str) {
		string _buffer;
		ifstream file(given_str);
		int i = 0;
		while (!file.eof()) {
			getline(file, _buffer, ' ');
			++i;
		}
		rs_strings = new string[i + 1];
		_buffer = {};
		file.close();
		file.open(given_str);
		i = 0;
		while (getline(file, _buffer, ' ')) {
			rs_strings[i] = _buffer;
			++i;
		}
		rs_string_count = i;
	}

	StringSet::StringSet(const StringSet& given_rs) {
		*this = given_rs;
	}

	StringSet& StringSet::operator=(const StringSet& given_rs) {
		if (this != &given_rs)
		{
			rs_string_count = given_rs.rs_string_count;
			rs_strings = new string[rs_string_count];
			for (int i = 0; i < rs_string_count; ++i) {
				rs_strings[i] = given_rs.rs_strings[i];
			}
		}
		return *this;
	}

	size_t StringSet::size() {
		return rs_string_count;
	}

	string StringSet::getRecord(int given_t) {
			if(rs_strings != nullptr&&given_t<rs_string_count+1) {
			return string(rs_strings[given_t]);
		}
		else {
			return "";
		}
		return 0;
	}
	string StringSet::operator[] (int given_t)
	{
		return this->getRecord(given_t);
	}

	StringSet::StringSet(StringSet&& given_rs) {
		*this = move(given_rs);
	}

	StringSet& StringSet::operator=(StringSet&& given_rs) {
		if (this != &given_rs) {
			rs_string_count = given_rs.rs_string_count;
			rs_strings = new string[rs_string_count];
			for (int i = 0; i < rs_string_count; ++i) {
				rs_strings[i] = given_rs.rs_strings[i];
			}
			delete[] given_rs.rs_strings;
			given_rs.rs_strings = nullptr;
			given_rs.rs_string_count = 0;
		}
		return *this;
	}
}