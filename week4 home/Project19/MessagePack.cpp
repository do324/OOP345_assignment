//Doyeon Kim
//1396766166
//MESSAGEPACK.CPP
//2019-02-07
#include <iostream>
#include <utility>
#include "Message.h"
#include "MessagePack.h"

namespace sict
{	
	//default construct for safe empty state.
	MessagePack::MessagePack()
		: messages{ nullptr }
		, NumOfElements{ 0 }
	{
	}
	
	
	MessagePack::MessagePack(const MessagePack& obj)
	{
		*this = obj;
	}

	//copy
	MessagePack & MessagePack::operator=(const MessagePack& obj)
	{
		if (this != &obj)  //checking
		{
			delete[] messages;
			
			NumOfElements = obj.NumOfElements;

			for (int i = 0; i < NumOfElements; i++)
				
				messages[i] = obj.messages[i];
		}
		return *this;
	}
	
	
	MessagePack::MessagePack(MessagePack&& obj)
	{
		*this = std::move(obj);
	}
	
	//move
	MessagePack& MessagePack::operator=(MessagePack&& obj)
	{
		if (this != &obj)
		{
			messages = obj.messages;
			NumOfElements = obj.NumOfElements;

			obj.messages = { nullptr };
			obj.NumOfElements = { 0 };
		}
		return *this;
	}
	
	//destructor
	MessagePack::~MessagePack()
	{
		delete[] messages;
		messages = nullptr;
	}

	//receives the address of an array of Message objects and the number of elements in that array.
	MessagePack::MessagePack(Message** Address_ArrayOfMessages, int NumOfMessages)
	{
		if (NumOfMessages > 0 && Address_ArrayOfMessages != nullptr)
		{
			//allocates dynamic memory
			messages = new Message[NumOfMessages];	
			NumOfElements = { 0 };

			// copy
			for (int i = 0; i < NumOfMessages; ++i)
			{
				if (!(*Address_ArrayOfMessages[i]).empty())
					messages[i] = *Address_ArrayOfMessages[i];
				else
					messages[i] = Message();

				NumOfElements++;
			}

			for (int i = 0; i < NumOfElements; ++i)
			{
				//fill the gap
				if (messages[i].empty())
				{
					for (int x = i; x < NumOfElements - 1; ++x)	
						messages[x] = messages[x + 1];

					messages[NumOfElements - 1] = Message();
				}
			}

			NumOfElements--;
		}
	}
	
	//a query that inserts into the output stream os each element in the array of Message objects.
	void MessagePack::display(std::ostream& os) const
	{
		for (int i = 0; i < NumOfElements; i++)
		{
			if (!messages[i].empty())
				messages[i].display(os);
		}
	}
	
	//a query that returns the number of Message objects stored in the current object.
	size_t MessagePack::size() const
	{
		return size_t(NumOfElements);
	}
	
	//inserts into os the contents of the MessagePack object.
	std::ostream& operator<<(std::ostream& os, const MessagePack& m)
	{
		m.display(os);
		return os;
	}
}