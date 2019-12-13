// Milestone 3

// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: November 28, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <utility>
#include <fstream>

#include "Task.h"
#include "CustomerOrder.h"
#include "Utilities.h"

class LineManager {
	std::vector<Task*> m_AssemblyLine;
	std::deque<CustomerOrder> m_toBeFilledOrders;
	std::deque<CustomerOrder> m_completedOrders;
	size_t m_cntCustomerOrder;

	// start task in assemblyline
	Task* m_startingTask;
	// last task in assemblyline
	Task* m_finalTask;

public:
	LineManager();

	// custom constructor
	LineManager(const std::string& fileName, std::vector<Task*>& assemblyLineTasks, std::vector<CustomerOrder>& ordersToFill);

	bool run(std::ostream& os);

	// displays all the orders that were completed
	void displayCompleted(std::ostream& os) const;

	// validates each task on the assembly line
	void validateTasks() const;

};

#endif