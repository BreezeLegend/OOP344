// Name:Victor Hasnat
// Seneca Student ID:119485183
// Seneca email:vhasnat@myseneca.ca	
// Date of completion:March 25,2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <string>
#include "Utilities.h"

using namespace std;

namespace sdds {
	char Utilities::m_delimiter = ' ';
	
	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos,
		bool& more)
	{
		string result = "";

		// use delimiter to extraxt the next token from str starting at next_pos
		size_t first_pos = next_pos;
		next_pos = str.find(m_delimiter, first_pos);
		
		if (next_pos == string::npos)
		{
			result = str.substr(first_pos);
			m_widthField = max(result.length(), m_widthField);
			more = false;
		}
		else if (first_pos == next_pos)
		{
			more = false;
			throw "No token between delimiters!";
		}
		else
		{
			result = str.substr(first_pos, next_pos - first_pos);
			m_widthField = max(result.length(), m_widthField);
			more = true;
		}
		next_pos++;
		return result;
	}

	// Class functions
	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}
	
	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}