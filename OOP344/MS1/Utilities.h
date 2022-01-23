// Name:Victor Hasnat
// Seneca Student ID:119485183
// Seneca email:vhasnat@myseneca.ca	
// Date of completion:March 25,2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _SDDS_UTILITIES_H_
#define _SDDS_UTILITIES_H_

namespace sdds
{
//#include <stdio.h>
	
	class Utilities {
		size_t m_widthField = 1; //default value is 1
		static char m_delimiter;
		
	public:
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
}
#endif /* _SDDS_UTILITIES_H_ */