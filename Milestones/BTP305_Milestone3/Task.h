// Milestone 3

// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: November 28, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <deque>
#include <numeric>
#include "CustomerOrder.h"

class Task : public Item {
	std::deque<CustomerOrder> m_orders;
	Task* m_pNextTask;

public:
	// default constructor
	Task();

	// custom constructor
	Task(const std::string& record);

	void runProcess(std::ostream& os);

	bool moveTask();

	void setNextTask(Task& task);

	Task* getNextTask();

	bool getCompleted(CustomerOrder& order);

	void validate(std::ostream& os) const;

	Task& operator+=(CustomerOrder&& other);

	// deleted copy functionality
	Task(const Task&) = delete;
	Task& operator=(const Task&) = delete;

	// deleted move functionality
	Task(Task&&) = delete;
	Task& operator=(Task&&) = delete;

};


#endif