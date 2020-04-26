//Doyeon Kim
//139766166
//Product.cpp
//2019/03/14

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "Product.h"

extern int FW;

namespace sict
{
	//default constructor 
	Product::Product()
		: product_num{0}
		, product_cost{0.0}
	{
	}

	//constructor for save
	Product::Product(int productNumber, double cost)
		: product_num{productNumber}
		, product_cost{cost}
	{
	}

	//return price
	double Product::price() const
	{
		return product_cost;
	}
	
	//display
	void Product::display(std::ostream & os) const
	{
		os << std::setw(FW) << product_num << std::setw(FW) << product_cost;
	}

	//derived taxable product module
	//3-argument constructor
	TaxableProduct::TaxableProduct(int productNumber, double price, char status)
		: Product(productNumber, price)
		, tax_cost(status == 'H' ? 0.13 : 0.08)
	{
	}

	//return tex price
	double TaxableProduct::price() const
	{
		return Product::price() * (1 + tax_cost);
	}

	//tax display
	void TaxableProduct::display(std::ostream & os) const
	{
		Product::display(os);

		if (tax_cost == 0.13)
			os << " HST";
		else
			os << " PST";
	}

	
	/*reads a single record from file object file, 
	allocates memory for a product in the hierarchy, 
	stores the information read into the product object 
	and returns its address.*/
	iProduct* readRecord(std::ifstream & file)
	{
		iProduct* product = nullptr;

		int NumOfPro = { 0 };
		double PriceOfPro = { 0 };
		char TaxOfPro = { '\0' };
		std::string line = {};

		while (std::getline(file, line, '\n'))
		{
			size_t count = std::count(line.begin(), line.end(), ' ');		// count how many spaces in line
			std::stringstream stream(line);
			if (count == 2)
			{
				stream >> NumOfPro >> PriceOfPro >> TaxOfPro;
				product = new TaxableProduct(NumOfPro, PriceOfPro, TaxOfPro);
				break;
			}
			else
			{
				stream >> NumOfPro >> PriceOfPro;
				product = new Product(NumOfPro, PriceOfPro);
				break;
			}
		}

		return product;
	}
	std::ostream & operator<<(std::ostream & os, const iProduct & p)
	{
		p.display(os);
		return os;
	}
}