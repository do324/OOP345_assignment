//Doyeon Kim
//1396766166
//message.cpp
//2019-02-07

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Message.h"

using namespace std;

namespace sict
{


	//A default constructor that places the object in a safe empty state.
	Message::Message() {
		user = "";
		reply = "";
		tweet = "";
	}

	Message::Message(const std::string& str) {
		
		string line = str;
		
		auto pos = line.find(' ');
		
		if (pos != std::string::npos) {
			user.assign(line.substr(0, pos));
			line.erase(0, pos + 1);

			if (line.find('@') == 0) {
				pos = line.find_first_of(' ');
				reply.assign(line.substr(1, pos - 1));
				line.erase(0, pos + 1);
			}
			//tweet.assign(line);
			tweet = line.substr(0);
		}
		
	}



	bool Message::empty() const
	{
		return (user.empty() && tweet.empty() && reply.empty());
	}

	void Message::display(std::ostream & os) const
	{
		if (!tweet.empty())
		{
			os << ">User  : " << user << std::endl;

			if (!reply.empty()) {
				os << " Reply : " << reply << std::endl;
			}

			os << " Tweet : " << tweet << "\n";
		}
	}


}
