// Milestone 3

// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: November 28, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "LineManager.h"

LineManager::LineManager() {
	m_cntCustomerOrder = 0;
	m_startingTask = nullptr;
	m_finalTask = nullptr;
}

// custom constructor
LineManager::LineManager(const std::string& fileName, std::vector<Task*>& assemblyLineTasks, std::vector<CustomerOrder>& ordersToFill) : LineManager() {

	std::ifstream file(fileName);

	if (file.good()) {
		// 1. resize to match ordersToFill
		///////////////////////////////////////////////

		m_toBeFilledOrders.resize(ordersToFill.size());
		// move contents of parameter into tb filled orders
		std::move(ordersToFill.begin(), ordersToFill.end(), m_toBeFilledOrders.begin());


		// 2. resize to match assemblylinetasks
		///////////////////////////////////////////////

		m_AssemblyLine.resize(assemblyLineTasks.size());
		// copy contents of parameter into assemblyline
		std::copy(assemblyLineTasks.begin(), assemblyLineTasks.end(), m_AssemblyLine.begin());

		// set size of customer order count
		m_cntCustomerOrder = m_toBeFilledOrders.size();


		//3. read lines from file to gather tasks
		///////////////////////////////////////////////

		bool more = true;
		size_t current_pos = 0;

		//task names tokenized from line
		std::string taskName1;
		std::string taskName2;

		//getline temporary string holder
		std::string line;

		Utilities util;

		// keep looping getline on file and insert into line each time
		while (std::getline(file, line)) {

			// reset pos and more each iteration, usage of utility module
			more = true;
			current_pos = 0;

			taskName1 = util.extractToken(line, current_pos, more);

			if (current_pos != std::string::npos) {
				taskName2 = util.extractToken(line, current_pos, more);
			}

			// set iterators for task 1 and task 2
			std::vector<Task*>::iterator taskIt1 = std::find_if(m_AssemblyLine.begin(), m_AssemblyLine.end(), 
				[&taskName1](const Task* task) {return task->getName().compare(taskName1) == 0; });

			std::vector<Task*>::iterator taskIt2 = std::find_if(m_AssemblyLine.begin(), m_AssemblyLine.end(), 
				[&taskName2](const Task* task) {return task->getName().compare(taskName2) == 0; });

			// define the starting task if it is not defined already
			if (m_startingTask == nullptr && taskIt1 != m_AssemblyLine.end()) {
				m_startingTask = (*taskIt1);
			}
				
			if (taskIt1 != m_AssemblyLine.end() && taskIt2 != m_AssemblyLine.end()) {
				(*taskIt1)->setNextTask(*(*taskIt2));
			}

			//clear the tasknames
			taskName1.clear();
			taskName2.clear();

			// search for final task

			Task* currentTask;

			// check if first task is defined
			if (m_startingTask != nullptr) {

				currentTask = m_startingTask;

				// run loop to find final task
				while (currentTask->getNextTask() != nullptr) {

					currentTask = currentTask->getNextTask();
					
					// if current task's next task was set to itself, set its next task to nullptr
					if (currentTask == currentTask->getNextTask()) {
						Task* tmp = nullptr;
						currentTask->setNextTask(*tmp);
					}
				}
				m_finalTask = currentTask;
			}
		}
	}
}

bool LineManager::run(std::ostream& os) {

	// empty object
	CustomerOrder tmp;

	//start from beginning task
	Task* currentTask = m_startingTask;

	// check if to be filled orders is not empty
	if (m_toBeFilledOrders.size() > 0) {
		*m_startingTask += std::move(m_toBeFilledOrders.front());
		m_toBeFilledOrders.pop_front();
	}

	// run process for each task on assembly line
	for (auto& obj : m_AssemblyLine) {
		obj->runProcess(os);
	}

	// for each size of assembly line...
	for (auto i = 0u; i < m_AssemblyLine.size(); ++i) {
		if (currentTask->moveTask() == true) {
			if (currentTask->getCompleted(tmp) == true) {
				if (!tmp.isEmpty())
					m_completedOrders.push_back(std::move(tmp));
			}
		}

		if (currentTask->getNextTask() != nullptr) {
			currentTask = currentTask->getNextTask();
		}
	}

	// return true if orders have been completed
	return m_completedOrders.size() == m_cntCustomerOrder;
}

// display all the orders that were completed
void LineManager::displayCompleted(std::ostream& os) const {
	std::for_each(m_completedOrders.begin(), m_completedOrders.end(), [&os](const CustomerOrder& order) {
		order.display(os);
	});
}

// validate each task on the assembly line
void LineManager::validateTasks() const {
	std::for_each(m_AssemblyLine.begin(), m_AssemblyLine.end(), [](const Task* task) {
		task->validate(std::cout);
	});
}