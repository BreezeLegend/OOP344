/**********************************************************
 * Name: Victor Hasnat
 * Student ID: 119485183
 * Workshop: Workshop 6 part 2
 * Seneca email: vhasnat@myseneca.ca
 * Section: NDD
 **********************************************************/

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>
#include <fstream>
#include "Car.h"

namespace sdds {

	class Racecar :
		public Car
	{
		double m_booster;
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};

}

#endif