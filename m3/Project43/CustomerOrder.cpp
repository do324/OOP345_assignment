//douyeon kim
//139766166
//2019-03-25
#include <ostream>
#include<string>
#include "CustomerOrder.h"
using namespace std;

namespace sict {
    
	unsigned int CustomerOrder::field_width;
    
	CustomerOrder::CustomerOrder() : customer_name{""}, product_name{""}, items{nullptr}, count{0} {}
    
    CustomerOrder::CustomerOrder(const std::string& str) {
        Utilities obj;
        size_t delimit = 0;
        count = std::count(str.begin(), str.end(), obj.getDelimiter()) - 1;  //count # of items in str
        
        
        if (str.find(obj.getDelimiter(), delimit+1) != std::string::npos) {
            customer_name = obj.extractToken(str, delimit);
        }
        
        if (str.find(obj.getDelimiter(), delimit+1) != std::string::npos) {
            product_name = obj.extractToken(str, delimit);
        }
        
        if (delimit != std::string::npos && delimit < str.length()) {
            items = new ItemInfo*[count];
            
            
            for (size_t i = 0; i < count; i++)
                items[i] = new ItemInfo(obj.extractToken(str, delimit));
        }
        else
            throw "No items are found! error!";
        
        
        if (customer_name.length() > field_width)
            field_width = static_cast<int>(customer_name.length()+1);
    }
    
    
    CustomerOrder::~CustomerOrder() {
        delete[] items;
        items = nullptr;
    }
    
    void CustomerOrder::fillItem(ItemSet& obj, std::ostream& os) {
        for (size_t i = 0; i < count; i++) {
            if (obj.getName() == items[i]->item_name) {
                if (obj.getQuantity() > 0 && !items[i]->filled) {
                    items[i]->item_serialnum = obj.getSerialNumber();
                    items[i]->filled = true;
                    os << "Filled " << this->getNameProduct() << "[" << items[i]->item_name << "][" << items[i]->item_serialnum << "]\n";
                    --obj;    
                }
                else if (items[i]->filled) {    
                    os << "Unable to fill " << this->getNameProduct() << "[" << items[i]->item_name << "][" << items[i]->item_serialnum << "] already filled\n";
                }
                else if (obj.getQuantity() == 0) {     
                    os << "Unable to fill " << this->getNameProduct() << "[" << items[i]->item_name << "][" << items[i]->item_serialnum << "] out of stock\n";
                }
            }
        }
    }
    

    bool CustomerOrder::isFilled() const {  //
        bool check = true;
        for (size_t i = 0; i < count; i++) {
            if (!items[i]->filled)
                check = false;
        }
        return check;
    }
    
    
    bool CustomerOrder::isItemFilled(const std::string& obj) const {
        bool tf = true;
        for (size_t i = 0; i < count; i++) {
            if (items[i]->item_name == obj && !items[i]->filled) {
                tf = false;
            }
        }
        return tf;
    }
    
   
    std::string CustomerOrder::getNameProduct() const {
        return customer_name + " [" + product_name + "]";
    }
    
   
    
    CustomerOrder::CustomerOrder(CustomerOrder&& obj) {
        *this = std::move(obj);
    }
    
    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& obj) {
        if (this != &obj) {
            
            customer_name = obj.customer_name;
            product_name = obj.product_name;
            items = obj.items;
            count = obj.count;
            
            obj.customer_name = "";
            obj.product_name = "";
            obj.items = nullptr;
            obj.count = 0;
        }
        return *this;
    }

	void CustomerOrder::display(std::ostream& os, bool showDetail) const {
		if (!showDetail) {
			os << std::setw(field_width) << customer_name << "[" << product_name << "]\n";

			for (size_t i = 0; i < count; i++) {
				os << std::setw(field_width) << " " << items[i]->item_name << std::endl;
			}
		}


		if (showDetail) {
			os << std::setw(field_width) << customer_name << "[" << product_name << "]\n";

			for (size_t i = 0; i < count; i++) {
				os << std::setw(field_width) << " "
					<< "[" << items[i]->item_serialnum << "] "
					<< items[i]->item_name << " – ";

				if (items[i]->filled) os << "FILLED";
				else os << "MISSING";

				os << std::endl;
			}
		}
	}
}
