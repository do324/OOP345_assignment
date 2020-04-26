#ifndef _W4_MESSAGE_H
#define _W4_MESSAGE_H

#include <fstream>
#include <string>


using String = std::string;

namespace sict
{
	class Message
	{
		std::string user, reply, tweet;
		
	public:
		Message();
		//Message(String user, String tweet, String reply);
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;
	
	};
}

#endif // !_W4_MESSAGE_H