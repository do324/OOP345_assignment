//Doyeon Kim
//139766166
//2019/01/17
#ifndef STRINGT_H
#define STRINGT_H

#include <iostream>
//#define MAX 3

namespace sict{
	class String{
		//char str[MAX+1];
		char* str;
		
	public:
		String(const char* S);
		void display(std::ostream& os) const;
	};

	std::ostream& operator<<(std::ostream& ostr, const String& out);
}
#endif