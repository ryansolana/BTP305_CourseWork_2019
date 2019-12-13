// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Nov 2, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "Vehicle.h"


namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;

	public:
		~Autoshop();
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out);

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto& obj : m_vehicles) {
				if (test(obj))
					vehicles.push_back(obj);
			}

		}

	};


}


#endif