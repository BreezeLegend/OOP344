/**********************************************************
 * Name: Victor Hasnat
 * Student ID: 119485183
 * Workshop: Workshop 4 part 2
 * Seneca email: vhasnat@myseneca.ca
 * Section: NDD
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS_
#include "Restaurant.h"
#include <iostream>
#include <cstring>

namespace sdds {

    Restaurant::Restaurant()  {
        m_res = nullptr;
        m_num  = 0;
    }

    Restaurant::Restaurant(const Reservation **reservations, size_t cnt){
        if (reservations != nullptr && cnt > 0) { // if parameter not empty then allocate
            m_res = new Reservation*[cnt];
            for (size_t i = 0; i < cnt; i++) {
                m_res[m_num] = new Reservation(*reservations[i]);  //each element of array is a pointer
                m_num++;
            }
        } else {
            *this = Restaurant();
        }
    }
	
	// Copy constructor
    Restaurant::Restaurant(const Restaurant &cp) {
        *this = cp;
    }
	// Copy assignment
	Restaurant& Restaurant::operator= (const Restaurant& cp) {
		if (this != &cp) {
			delete [] m_res;
			m_num  = cp.m_num ;
			m_res = new Reservation*[m_num];
			
			for (size_t i = 0; i < m_num; i++) {
				m_res[i] = new Reservation;
				*(m_res[i]) = *(cp.m_res[i]);
			}
		}
		return *this;
	}

	
	// Move constructor
    Restaurant::Restaurant(Restaurant&& mv) {
        *this = std::move(mv);
    }

	//Move assignment
    Restaurant& Restaurant::operator= (Restaurant&& mv) {
        if (this != &mv) {
            delete [] m_res;
            m_num  = mv.m_num ;
            m_res = mv.m_res;
            mv.m_num  = 0;
            mv.m_res = nullptr;
        }
        return *this;
    }

	// return number of reservation in system
    size_t Restaurant::size() const {
        return m_num ;
    }

	//overload insertion operator
   std::ostream& operator << (std::ostream& os, const Restaurant& res) {
static int call_size = 0;        
if (res.size() == 0) {
	    call_size++;
            os << "--------------------------" << std::endl;
            os << "Fancy Restaurant (" << call_size << ")" << std::endl;
            os << "--------------------------" << std::endl;
            os << "This restaurant is empty!" << std::endl;
            os << "--------------------------" << std::endl;

        } else {
            call_size++;
            os << "--------------------------" << std::endl;
            os << "Fancy Restaurant (" << call_size << ")" << std::endl;
            os << "--------------------------" << std::endl;

            for (size_t i = 0; i < res.m_num ; i++) {
                os << *res.m_res[i];
            }
			
			os << "--------------------------" << std::endl;

        }
       return os;
    }

	
	//Do a full deallocation like this to avoid memory leak
    Restaurant::~Restaurant() {
		for (size_t i = 0; i < m_num ; i++){
           delete m_res[i];
		}
		  delete [] m_res; //you can do just this but memory leak
	}



}

