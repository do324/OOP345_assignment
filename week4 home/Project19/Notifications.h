//Doyeon Kim
//1396766166
//NOTIFICATION.h
//2019-02-07
#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H

#include <iostream>
#include "Message.h"

namespace sict
{
	class Notifications
	{
		const Message** Pointer_ArrayOfAddress;	
		int Max_NumOfAddress;
		int NumOfAddressStored;
	public:
		Notifications();
		Notifications(const Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications(Notifications&&);
		Notifications& operator=(Notifications&&);
		~Notifications();

		Notifications(int);
		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(std::ostream& os) const;
		size_t size() const;
	};

	std::ostream& operator<<(std::ostream& os, Notifications& nf);
}

#endif // !SICT_NOTIFICATIONS_H


