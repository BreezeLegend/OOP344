/**********************************************************
 * Name: Victor Hasnat
 * Student ID: 119485183
 * Workshop: Workshop 4 part 2
 * Seneca email: vhasnat@myseneca.ca
 * Section: NDD
 **********************************************************/


#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H


#include "Reservation.h"
#include <iostream>

namespace sdds {

    class Restaurant {

        Reservation** m_res = nullptr;
        size_t m_num = 0;


    public:
		//NOT IN INSTRUCTION
        Restaurant();
		 ~Restaurant();
        Restaurant(const Restaurant& restaurant);
        Restaurant(Restaurant&&);
        Restaurant& operator = (const Restaurant&);
        Restaurant& operator = (Restaurant&&);
       
		//INSTRUCTION
        Restaurant(const Reservation** reservation, size_t cnt);
        size_t size() const;
        friend std::ostream& operator << (std::ostream& os, const Restaurant& restaurant);

    };
}

#endif // SDDS_RESTAURANT_H
