// Milestone 3

// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: November 28, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Task.h"

// default constructor
Task::Task() {
	m_pNextTask = nullptr;
}
// custom constructor
Task::Task(const std::string& record) : Item(record) {
	m_pNextTask = nullptr;
}

void Task::runProcess(std::ostream& os) {

	// check if orders are not empty
	if (!m_orders.empty()) {

		// if fill state is false, fill it so it is. keep going for every last order until we reach a true
		while (m_orders.back().getItemFillState(Item::getName()) == false) {
			m_orders.back().fillItem(*this, os);
		}
	}
}

bool Task::moveTask() {
	// check if orders are not empty
	if (!m_orders.empty()) {
		if (m_orders.back().getItemFillState(Item::getName()) == true) {
			if (m_pNextTask != nullptr) {
				*m_pNextTask += std::move(m_orders.back());
				m_orders.pop_back();
			}
		}
	}
	return !(m_orders.size() == 0);
}

void Task::setNextTask(Task& task) {
	m_pNextTask = &task;
}

// next task query for this task obj
Task* Task::getNextTask() {
	return m_pNextTask;
}

bool Task::getCompleted(CustomerOrder& order) {

	bool completed = false;

	// check if orders are not empty
	if (!m_orders.empty()) {
		
		// confirm that the order is filled
		if (m_orders.back().getOrderFillState() == true) {

			// place last customer order into parameter
			order = std::move(m_orders.back());

			// remove last customer order from deque to reflect change
			m_orders.pop_back();

			// set task to completed
			completed = true;
		}
	}

	return completed;
}

void Task::validate(std::ostream& os) const{
	// check if next task exist
	if (m_pNextTask != nullptr) {
		os << getName() << " --> " << m_pNextTask->getName() << std::endl;
	}
	else {
		os << getName() << " --> " << "END OF LINE" << std::endl;
	}
}

Task& Task::operator+=(CustomerOrder&& other) {
	m_orders.push_front(std::move(other));

	return *this;
}