/**********************************************************
 * Name: Victor Hasnat
 * Student ID: 119485183
 * Workshop: Workshop 4 part 2
 * Seneca email: vhasnat@myseneca.ca
 * Section: NDD
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <string>
#include "Reservation.h"
#include <iomanip>
#include <algorithm>


namespace sdds {

	Reservation::Reservation() {
		m_reservationID = {};
		m_reservationName = {};
		m_email = {};
		m_numOfppl = 0;
		m_day = 0;
		m_hour = 0;
	}

		Reservation::Reservation(const std::string& res)
	{
		std::string temp;
		temp = res;
		int pos;
		//create temp value for each member variables;	
		std::string id = {};
		std::string name = {};
		std::string email = {};
		int numOfPeople = 0;
		int date = 1;
		int hour = 1;


		//find id
		pos = temp.find(":");
		id = temp.substr(0, pos);
		temp.erase(0, pos + 1);

		id.erase(0, id.find_first_not_of(" "));
		id.erase(id.find_last_not_of(" ") + 1);

		//find name
		pos = temp.find(",");
		name = temp.substr(0, pos);
		temp.erase(0, pos + 1);

		name.erase(0, name.find_first_not_of(" "));
		name.erase(name.find_last_not_of(" ") + 1);

		//erase space in res string
		temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());

		//find email
		pos = temp.find(",");
		email = temp.substr(0, pos);
		temp.erase(0, pos + 1);

		//find noOfPeople
		pos = temp.find(",");
		if (pos == 1)
		{
			numOfPeople = std::stoi(temp.substr(0, pos));
		}
		else
		{
			numOfPeople = std::stoi(temp.substr(0, pos - 1));
		}
		temp.erase(0, pos + 1);

		//find day
		pos = temp.find(",");
		if (pos == 1)
		{
			date = std::stoi(temp.substr(0, pos));
		}
		else
		{
			date = std::stoi(temp.substr(0, pos - 1));
		}
		temp.erase(0, pos + 1);

		//find time
		hour = std::stoi(temp);

		//assgin values
		m_reservationID = id;
		m_reservationName = name;
		m_email = email;
		m_numOfppl = numOfPeople;
		m_day = date;
		m_hour = hour;
	}
	std::ostream& operator<<(std::ostream& os, const Reservation& cp) {
		std::cout <<  "Reservation " << std::setw(10) << std::right << cp.m_reservationID << ": "
			<< std::setw(20) << std::right
			<< cp.m_reservationName << "  "
			<< std::setw(24) << std::left
			<< "<" + cp.m_email + ">";

		if (6 <= cp.m_hour && cp.m_hour <= 9) {
			std::cout << "Breakfast";
		}
		else if (11 <= cp.m_hour && cp.m_hour <= 15) {
			std::cout << "Lunch";
		}
		else if (17 <= cp.m_hour && cp.m_hour <= 21) {
			std::cout << "Dinner";
		}
		else {
			std::cout << "Drinks";
		}
		std::cout << " on day " << cp.m_day << " @ " << cp.m_hour << ":00"
			<< " for " << cp.m_numOfppl;
        if (cp.m_numOfppl>1)
        {
			std::cout<< " people." << std::endl;
        }
        else
        {
            std::cout<< " person." << std::endl;
        }

		return os;
	}

	bool Reservation::operator==(const Reservation& res) const
	{
		return	m_reservationID==res.m_reservationID;
	}

}
