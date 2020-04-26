//Doyeon Kim
//1396766166
//MESSAGEPACK.CPP
//2019-02-07
#include <iostream>
#include <utility>
#include "Notifications.h"

namespace sict
{

	//default constructor for safe empty
	Notifications::Notifications()
		: Pointer_ArrayOfAddress{nullptr}
		, Max_NumOfAddress{0}
		, NumOfAddressStored{0}
	{
	}

	Notifications::Notifications(const Notifications& obj)
	{
		*this = obj;
	}
	
	//copy operator
	Notifications& Notifications::operator=(const Notifications& obj)
	{
		if (this != &obj) //checking
		{
			delete[] Pointer_ArrayOfAddress;

			Max_NumOfAddress = obj.Max_NumOfAddress;
			NumOfAddressStored = obj.NumOfAddressStored;

			for (int i = 0; i < obj.NumOfAddressStored; i++)
				Pointer_ArrayOfAddress[i] = obj.Pointer_ArrayOfAddress[i];
		}
		return *this;
	}
	
	Notifications::Notifications(Notifications&& obj)
	{
		*this = std::move(obj);
	}
	
	//move
	Notifications& Notifications::operator=(Notifications&& obj)
	{
		if (this != &obj)
		{
			Pointer_ArrayOfAddress = obj.Pointer_ArrayOfAddress;
			Max_NumOfAddress = obj.Max_NumOfAddress;
			NumOfAddressStored = obj.NumOfAddressStored;

			obj.Pointer_ArrayOfAddress = { nullptr };
			obj.Max_NumOfAddress = { 0 };
			obj.NumOfAddressStored = { 0 };
		}
		return *this;
	}
	
	//destructor
	Notifications::~Notifications()
	{
		delete[] Pointer_ArrayOfAddress;
		Pointer_ArrayOfAddress = { nullptr };
	}
	
	///If the number of messages is positive-valued, 
	///your function allocates dynamic memory for the specified number of pointers to Message objects. 
	///Otherwise, your function places the object in a safe empty state. 
	Notifications::Notifications(int MaxNumOfElements) //for allocation memory
	{
		if (MaxNumOfElements > 0)
		{
			//allocate dynamic memory
			Pointer_ArrayOfAddress = new const Message*[MaxNumOfElements];
			Max_NumOfAddress = MaxNumOfElements;
			NumOfAddressStored = { 0 };
		}
		else
			*this = Notifications();
	}
	
	////a modifier that receives a reference to an unmodifiable Message object. 
	Notifications& Notifications::operator+=(const Message& msg)
	{	
		//if space is avaliable
		bool space_available = NumOfAddressStored < Max_NumOfAddress;
		
		if (!msg.empty() && space_available)	{
			
			// store the address
			Pointer_ArrayOfAddress[NumOfAddressStored] = &msg;	
			
			++NumOfAddressStored;
		}

		return *this;
	}
	//Your function searches the current object for the address of the Message object.
	//If your function finds the address stored in the current object, 
	//it removes that object from the aggregation(replaces its address with nullptr).
	//Otherwise, your function does nothing.In any case, your function returns a reference to the current object.
	Notifications& Notifications::operator-=(const Message& msg)
	{	
		//searching
		for (int i = 0; i < NumOfAddressStored; i++)
		{
			bool address_found = Pointer_ArrayOfAddress[i] == &msg;

			if (address_found)
			{
				Pointer_ArrayOfAddress[i] = { nullptr }; //removes that object from the aggregation

				// fill the gap
				for (int x = i; x < NumOfAddressStored - 1; ++x)
					Pointer_ArrayOfAddress[x] = Pointer_ArrayOfAddress[x + 1];

				Pointer_ArrayOfAddress[NumOfAddressStored - 1] = { nullptr };
			}
		}

		NumOfAddressStored--;

		return *this;
	}

	//a query that inserts into the output stream os each element in the array of Message objects. 
	void Notifications::display(std::ostream& os) const
	{
		for (int i = 0; i < NumOfAddressStored; i++)
			(*Pointer_ArrayOfAddress[i]).display(os);
	}
	
	size_t Notifications::size() const
	{
		return NumOfAddressStored;
	}
	
	std::ostream & operator<<(std::ostream & os, Notifications & nf)
	{
		nf.display(os);
		return os;
	}
}
