// Workshop 3 
// In-Lab
// Name: Doyeon Kim
// Student #: 139766166
// Course: OOP345 Fall 2018
// File: LVpair.h

#ifndef LVPAIR_H
#define LVPAIR_H

#include <iostream>

namespace sict {
	
	template <typename L, typename V>
	class LVPair
	{
		L m_l;  //the type of the label
		V m_v;  //the type of the value
	
	public:
		
		LVPair()    //default constructor 
			: m_l{}
			, m_v{}
		{
		}
												//constructor
		LVPair(const L& label, const V& value)  //copies the values received in its parameters into the instance variables. 
			: m_l{ label }
			, m_v{ value }
		{
		}

		void display(std::ostream& os) const {
			if (m_v > 0) {
				os << m_l << " : " << m_v << std::endl;
			}
		}

	};

	template<typename L, typename V>
	std::ostream& operator<< (std::ostream& os, const LVPair<L,V>& pair) {
		pair.display(os);
		return os;
	}


	
	
	
}
#endif // LVPAIR_H

