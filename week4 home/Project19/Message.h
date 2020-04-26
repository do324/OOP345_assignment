//Doyeon Kim
//1396766166
//message.h
//2019-02-07

#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H

#include <fstream>
#include <string>

namespace sict
{
	class Message
	{
		std::string user, reply, tweet;
		
	public:
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;
	
	};
}

#endif // !MESSAGE_H