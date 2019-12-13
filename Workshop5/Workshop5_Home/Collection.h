// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Oct 19, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>

namespace sdds {

	template<class T>
	class Collection
	{
		// string for name
		std::string m_name;
		// dynamically allocated array of items
		T* m_items;
		// size of the array
		size_t m_size;
		// pointer to a function that returns void, generic ptr
		void (*ptrObserver)(const Collection<T>&, const T&);

		// helper function, finds item and returns an index in a collection
		int findItemIndex(const std::string& Title) const {
			//assume index is not found
			int index = -1;

			//iterate every element (item)
			for (auto i = 0u; i < m_size; ++i) {
				// check if the title matches any of the item titles
				if (m_items[i].title().compare(Title) == 0) {
					index = i;
					break;
				}
			}
			// return -1 if nothing was found, else return index that was set
			return index;
		}

		// helper function, inserts item to a collection
		void addItem(const T& item) {
			if (m_items) {
				//allocate mem for temp
				T* temp = new T[m_size + 1];
				for (auto i = 0u; i < m_size; i++) {
					temp[i] = T(m_items[i]);
				}

				delete[] m_items;

				//set new address for m_items
				m_items = temp;

				//set temp to nullptr
				temp = nullptr;

				m_items[m_size] = item;
				m_size++;
			}
			else {
				m_items = new T[1];
				m_items[0] = item;
				m_size = 1;
			}
		}

	public:
		//default constructor
		Collection() {
			m_name = "null";
			m_items = nullptr;
			m_size = 0u;
			ptrObserver = nullptr;
		}

		//custom constructor
		Collection(std::string name) {
			m_name = name;
			m_items = nullptr;
			m_size = 0u;
			ptrObserver = nullptr;
		}

		//destructor
		~Collection() {
			delete[] m_items;
			m_items = nullptr;
		}

		// query, returns name of collection
		const std::string& name() const {
			return m_name;
		}

		size_t size() const {
			return m_size;
		}

		//pointer function setup
		void setObserver(void(*observer)(const Collection<T>& collectionType, const T& item)) {
			ptrObserver = observer;
		}

		/*  adds a copy of item to the collection, only if the collection doesn't contain an item with the
		same title */
		Collection<T>& operator+=(const T& item) {
			// check if item already exists, if not then add it
			int index = findItemIndex(item.title());

			// if index is -1 then this will trigger
			if (index < 0) {
				addItem(item);

				if (ptrObserver != nullptr) {
					ptrObserver(*this, item);
				}
			}
			return *this;
		}

		T& operator[](size_t idx) const {

			if (idx > (m_size - 1u)) {
				throw std::out_of_range("Bad index [" +
					std::to_string(idx) +
					"]. Collection has [" +
					std::to_string(m_size) +
					"] items.");
			}

			return m_items[idx];
		}

		T* operator[](std::string title) const {
			int index = findItemIndex(title);
			T* temp = nullptr;
			//if index is not -1, return m_items reference at index, otherwise nullptr
			return index != -1 ? &m_items[index] : temp;
		}

		friend std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
			for (auto i = 0u; i < collection.m_size; ++i) {
				os << collection.m_items[i];
			}
			return os;
		}

		//deleted copy operations
		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;

	};

}
#endif