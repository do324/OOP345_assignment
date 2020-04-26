// Workshop 3 
// In-Lab
// Name: Doyeon Kim
// Student #: 139766166
// Course: OOP345 Fall 2018
// File: List.h

#ifndef LIST_H
#define LIST_H

#include <string>
#include <vector>

using namespace std;

namespace sict {

	template<typename T, int N>
	class List
	{
		std::vector<T> m_List;
	
	public:
		
		List()
		{
			m_List.reserve(N);
		}
		
		size_t size() const						// returns the number of elements stored in the array
		{
			return m_List.size();
		}
		
	

		const T& operator[](size_t i) const    //returns a reference to the unmodifiable object stored at that index of the array
		{
			return m_List.at(i);
		}

		
		void operator+=(const T& t) 
		{
			bool space = (this->size() < N);
			if (space)
			m_List.push_back(t);
			
		}
	};

}
#endif // LIST_H