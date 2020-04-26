//doyeon kim

#ifndef _SICT_CUSTOMER_ORDER_H
#define _SICT_CUSTOMER_ORDER_H

#include <iostream>
#include <algorithm>
#include "ItemSet.h"

namespace sict {
    
    struct ItemInfo {
        std::string item_name;
        unsigned int item_serialnum = 0;
        bool filled = false;
        
        ItemInfo(std::string str) : item_name{str} {}
    };
    
    class CustomerOrder {
       static unsigned int field_width;
        size_t count;
        ItemInfo** items;
		std::string customer_name;
		std::string product_name;
    public:
        CustomerOrder();
        CustomerOrder(const std::string&);
        ~CustomerOrder();
        void fillItem(ItemSet&, std::ostream& os);
        bool isFilled() const;
        bool isItemFilled(const std::string&) const;
        std::string getNameProduct() const;
        void display(std::ostream&, bool = false) const;
        
        CustomerOrder(CustomerOrder&&);
        CustomerOrder& operator=(CustomerOrder&&);
        
        
        CustomerOrder(const CustomerOrder&) = delete;
        CustomerOrder& operator=(const CustomerOrder&) = delete;
    };
}
#endif // !_SICT_CUSTOMER_ORDER_H
