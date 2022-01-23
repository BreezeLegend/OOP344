/**********************************************************
 * Name: Victor Hasnat
 * Student ID: 119485183
 * Workshop: Workshop 6 part 2
 * Seneca email: vhasnat@myseneca.ca
 * Section: NDD
 **********************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Autoshop.h"
#include "Vehicle.h"

using namespace std;

namespace sdds {

	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const {

		auto ptr = m_vehicles.begin();
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;
		for (ptr = m_vehicles.begin(); ptr < m_vehicles.end(); ptr++) {
			(*ptr)->display(out);
			out << endl;
		}
		out << "--------------------------------" << endl;

	}

	Autoshop::~Autoshop() {
		//auto ptr = m_vehicles.begin();
		for (auto ptr = m_vehicles.begin(); ptr < m_vehicles.end(); ptr++)
			delete* ptr;
	}
}