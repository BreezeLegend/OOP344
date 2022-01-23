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
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Vehicle.h"
#include "Racecar.h"


using namespace std;

namespace sdds {

	Vehicle* createInstance(std::istream& in) {
		char ch = '\0';
		char ch2 = '\0';

		std::string substr = "";
		getline(in, substr);
		std::stringstream ss(substr);
		ss >> ch >> ch2;
		if (ss) {
			if (ch == 'c' || ch == 'C') {
				return new Car(ss);
			}
			else if (ch == 'r' || ch == 'R') {
				return new Racecar(ss);
			}
			else
				throw ch;
		}
		else
			return nullptr;
	}

}