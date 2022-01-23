/**********************************************************
 * Name: Victor Hasnat
 * Student ID: 119485183
 * Workshop: Workshop 3 part 2
 * Seneca email: vhasnat@myseneca.ca
 * Section: NDD
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/




#pragma once
#ifndef SDDS_SETSUM_H
#define SDDS_SETSUM_H
#include <iostream>
#include "Set.h"

namespace sdds {

	template <unsigned int N,class T >
	class SetSummable : public Set<T, N> {
	public:

		T accumulate(const std::string& filter) const {
			T accumulator(filter);
			for (unsigned int i = 0; i < (*this).size(); i++) {
				accumulator += (*this).get(i);
			}
			return accumulator;

		};

	};




}
#endif
