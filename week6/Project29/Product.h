//Doyeon Kim
//139766166
//Product.h
//2019/03/14

#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H

#include <iostream>
#include <fstream>
#include "iProduct.h"

namespace sict
{
	class Product : public iProduct	{
		
		int product_num;
		
		double product_cost;
	
	public:
		
		Product();
		
		explicit Product(int, double);
		
		double price() const override;
		
		void display(std::ostream& os) const override;
	};

	class TaxableProduct : public Product {
		
		double tax_cost;
		
		enum class Tax { HST, PST };
	
	public:
		
		TaxableProduct(int, double, char);
		
		double price() const override;
		
		void display(std::ostream&) const override;
	};

	iProduct* readRecord(std::ifstream& file);
	
	std::ostream& operator<<(std::ostream& os, const iProduct& p);	
}
#endif 
// !SICT_PRODUCT_H