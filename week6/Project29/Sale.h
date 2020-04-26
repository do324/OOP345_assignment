//Doyeon Kim
//139766166
//Sale.h
//2019/03/14

#ifndef SICT_SALE_H
#define SICT_SALE_H

#include <vector>
#include "Product.h"

namespace sict
{
	class Sale	{
		std::vector<iProduct*> allproducts;
	
	public:
		
		explicit Sale(const char*);
		
		void display(std::ostream& os) const;
	};
}

#endif // SICT_SALE_H

