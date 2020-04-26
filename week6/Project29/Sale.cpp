//Doyeon Kim
//139766166
//Sale.cpp
//2019/03/14

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Sale.h"
#include "Product.h"

extern int FW;

namespace sict
{
	//constructor for reading
	Sale::Sale(const char* file)
	{
		if (file != nullptr && file[0] != '\0')
		{
			std::string buffer;
			size_t count = {0};
			std::ifstream fs;
			fs.open(file);
			if (fs.is_open())
			{
				while (std::getline(fs, buffer))
					count++;
				fs.clear();
				fs.seekg(0, std::ios::beg);
				for (size_t i = 0; i < count; i++)
					allproducts.push_back(readRecord(fs));
				fs.close();
			}
			else
				//error
				throw "File cannot be opened";
		}
		else
			//error
			throw "File does not exist";
	}

	//display
	void Sale::display(std::ostream & os) const
	{
		os << "\nProduct No" << std::setw(FW) << "Cost" << ' ' << "Taxable" << std::endl;
		double total_price = { 0.0 };
		for (auto& i : allproducts)
		{
			os << *i;
			os << std::fixed << std::setprecision(2);
			total_price += i->price();
			os << std::endl;
		}
		os << std::setw(FW) << "Total" << std::setw(FW) << total_price << std::endl;
	}
}

