/**********************************************************
 * Name: Victor Hasnat
 * Student ID: 119485183
 * Workshop: Workshop 4 part 2
 * Seneca email: vhasnat@myseneca.ca
 * Section: NDD
 **********************************************************/


#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"
#include <iostream>
namespace sdds {

	class ConfirmationSender
	{

		const Reservation** m_reservations;
		size_t m_size;

		int findReservation(const Reservation& res) const;

	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& src); //copy assignment
		ConfirmationSender(ConfirmationSender&& src); //move assignment

		~ConfirmationSender();

		ConfirmationSender& operator=(const ConfirmationSender& src); //copy assignment
		ConfirmationSender& operator=(ConfirmationSender&& src); //move assignment

		ConfirmationSender& operator +=(const Reservation& res);
		ConfirmationSender& operator -=(const Reservation& res);

		friend std::ostream& operator<< (std::ostream&, const ConfirmationSender& src);
	};
}
#endif
