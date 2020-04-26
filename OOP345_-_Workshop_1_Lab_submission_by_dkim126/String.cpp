//Doyeon Kim
//139766166
//2019/01/17
#include <iostream>
#include <cstring>
#include "String.h"

namespace sict{
	extern int INITIAL;
	String::String(const char* S){
		if (S){
			strncpy(str, S, MAX);
			str[MAX] = '\0';
		}
		else{
			str[0] = '\0';	
		}
	}
	
	void String::display(std::ostream& os) const{
		
		static int itemNum = INITIAL;
		itemNum++;
		os << itemNum << ": " << this->str;

		}

	std::ostream& operator<<(std::ostream& ostr, const String& out){
	
		out.display(ostr);
		return ostr;
	}
}