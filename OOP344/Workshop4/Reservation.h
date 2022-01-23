/**********************************************************
 * Name: Victor Hasnat
 * Student ID: 119485183
 * Workshop: Workshop 4 part 2
 * Seneca email: vhasnat@myseneca.ca
 * Section: NDD
 **********************************************************/

#pragma once
#ifndef _SDDS_RESERVATION_H_
#define _SDDS_RESERVATION_H_

#include <iostream>

using namespace std;

namespace sdds
{
	class Reservation
	{
	private:
		string m_reservationID;
		string m_reservationName;
		string m_email;
		unsigned int m_numOfppl;
		unsigned int m_day;
		unsigned int m_hour;

	public:
		Reservation(); 
		Reservation(const string& res);
		void trim(string& str);
		//Friend helper
		friend ostream& operator<<(ostream& os, const Reservation& copy);
		bool operator==(const Reservation& src) const;
	};

	

}


#endif // !SDDS_RESERVATION_H_
