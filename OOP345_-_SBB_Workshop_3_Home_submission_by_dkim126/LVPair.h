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

		virtual void display(std::ostream& os) const {
			os << m_l << " : " << m_v << std::endl;
		}


		L getLabel() const { return m_l; }
		V getValue() const { return m_v; }

	};

	template<typename L, typename V>
	std::ostream& operator<< (std::ostream& os, const LVPair<L,V>& pair) {
		pair.display(os);
		return os;
	}

	//athome
	template<typename L, typename V>
	class SummableLVPair : public LVPair<L, V> {
		static V init;				///holds the initial value for starting a summation
		static size_t fieldwidth;	///holds the minimum field width
	public:
		SummableLVPair() {}

		SummableLVPair(const L& label, const V& v) : LVPair<L, V>(label, v) {
			if (fieldwidth < label.size())
				fieldwidth = label.size();
		}
		
		static const V& getInitialValue() { return init; }


		V sum(const L& label, const V& sum) const {
			V result = LVPair<L, V>::getValue() + sum;
			return result;
		}

		virtual void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(fieldwidth);
			os << LVPair<L, V>::getLabel() << " : " << LVPair<L, V>::getValue() << std::endl;
			os.unsetf(std::ios::left);
		}
	};

	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& v) const {
		std::string result = v + " " + LVPair<std::string, std::string>::getValue();
		return result;
	}

}
#endif // LVPAIR_H

