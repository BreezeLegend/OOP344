/**********************************************************
 * Name: Victor Hasnat
 * Student ID: 119485183
 * Workshop: Workshop 4 part 2
 * Seneca email: vhasnat@myseneca.ca
 * Section: NDD
 **********************************************************/

#include "ConfirmationSender.h"
namespace sdds {

	ConfirmationSender::ConfirmationSender()
	{
		m_reservations = nullptr;
		m_size = 0;
	}

	//copy constructor
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
	{
		*this = src;
	}


	//move constructor
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)
	{
		*this = std::move(src);
	}

	ConfirmationSender::~ConfirmationSender()
	{
		m_reservations = nullptr;
		m_size = 0;
	}


	//copy assignment
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
	{
		if (this != &src) {
			m_reservations = new Reservation const* [src.m_size];
			for (auto i = 0u; i < (src.m_size); ++i)
				m_reservations[i] = src.m_reservations[i];

			m_size = src.m_size;
		}
		return *this;
	}

	//move assignmrnt
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src)
	{
		if (this != &src) {

			m_reservations = src.m_reservations;
			src.m_reservations = nullptr;

			m_size = src.m_size;
			src.m_size = 0;

		}

		return *this;
	}



    int ConfirmationSender::findReservation(const Reservation& res) const
	{
		int index= -1;
		for (unsigned int i = 0; i < m_size; ++i) {

			if (res == Reservation(*m_reservations[i])) {
				index = i;
				break;
				
			}
		}
		return index;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		int found = findReservation(res);
		const Reservation** temp = nullptr;

		if (found == -1) {
			temp = new Reservation const* [m_size + 1];

			for (size_t i = 0; i < m_size; ++i)
				temp[i] = m_reservations[i];

			temp[m_size] =  &res;
			m_size++;

			m_reservations = temp;
			temp = nullptr;
		}

		return *this;
	}



	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		int found = findReservation(res);
		const Reservation** tmp = nullptr;


		if (found != -1) {

			if (found != static_cast<int>(m_size - 1)) {
				m_reservations[found] = nullptr;
				m_reservations[found] = m_reservations[m_size - 1];
			}


			tmp = new Reservation const* [m_size - 1u];
			for (auto i = 0u; i < (m_size-1u); ++i)
				tmp[i] = m_reservations[i];

			m_reservations = tmp;
			m_size--;

			tmp = nullptr;

		}

		return *this;
	}


	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& src)
	{
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;

		if (src.m_size != 0) {
			for (unsigned int i = 0; i < src.m_size; ++i)
				os << *src.m_reservations[i];
		}
		else {
			os << "There are no confirmations to send!" << std::endl;
		}
		os << "--------------------------" << std::endl;
		return os;
	}

}
