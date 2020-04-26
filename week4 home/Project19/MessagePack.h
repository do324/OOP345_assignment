//Doyeon Kim
//1396766166
//messagePACK.h
//2019-02-07
#ifndef SICT_MESSAGEPACK
#define SICT_MESSAGEPACK

#include <iostream>
#include "Message.h"

namespace sict
{
	class MessagePack
	{
		Message* messages;
		int NumOfElements;
	public:
		MessagePack();
		MessagePack(Message**, int);
		MessagePack(const MessagePack&);
		MessagePack& operator=(const MessagePack&);
		MessagePack(MessagePack&&);
		MessagePack& operator=(MessagePack&&);
		~MessagePack();
		void display(std::ostream& os) const;
		size_t size() const;
	};

	std::ostream& operator<<(std::ostream&, const MessagePack&);
}

#endif // !SICT_MESSAGEPACK


