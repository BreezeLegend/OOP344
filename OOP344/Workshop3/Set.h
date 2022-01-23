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
#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <iostream>

namespace sdds {

	template < class T, unsigned int N>
	class Set {
		T result[N];
		unsigned elements = 0;

	public:
		//Set() {
		//for (int i = 0; i < N; i++) {
		//result[i] = 0;
		//}
		//};

		size_t size() const {
			return elements;
		};

		const T& operator[] (size_t idx) const {

			return result[idx];
		};

        const T& get(size_t idx) const
		{
		    return result[idx];
		};

		void operator+=(const T& item) {

			if (elements < N) {
				result[elements] = item;
				elements++;
			}
		};



	};



}

#endif
