/**********************************************************
 * Name: Victor Hasnat
 * Student ID: 119485183
 * Workshop: Workshop 6 part 2
 * Seneca email: vhasnat@myseneca.ca
 * Section: NDD
 **********************************************************/


#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include "Vehicle.h"
using namespace std;
namespace sdds {


	class Car : public Vehicle {
		std::string maker;
		std::string cond;
		double tSpeed;
	public:
		Car(std::istream&);
		Car();
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		void trim(std::string& str) const;
	};

}

#endif