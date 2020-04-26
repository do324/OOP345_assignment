//douyeon kim
//139766166
//2019-03-25
#include <iostream> 
#include <string> 
#include "ItemSet.h"
using namespace std;
namespace sict {
    
	unsigned int ItemSet::field_width;
    
    ItemSet::ItemSet(const std::string& str) {
       
		Utilities uti;
        size_t next_pos = 0;
        
        name = uti.extractToken(str, next_pos);
        
        if (name.length() > field_width)
            field_width = static_cast<int>(name.length());
        
        if (next_pos != std::string::npos)
            serial_num = std::stoi(uti.extractToken(str, next_pos));
        
        if (next_pos != std::string::npos)
            quantity = std::stoi(uti.extractToken(str,next_pos));
        
        if (next_pos != std::string::npos)
            desc = uti.extractToken(str, next_pos);
    }
    
    const std::string& ItemSet::getName() const {
        return name;
    }
    
    const unsigned int ItemSet::getSerialNumber() const {
        return serial_num;
    }
    
    const unsigned int ItemSet::getQuantity() const {
        return quantity;
    }
    
    ItemSet& ItemSet::operator--() {
        if (quantity > 0) {
            quantity--;
            serial_num++;
        }
        return *this;
    }
    
    void ItemSet::display(std::ostream& os, bool full) {
        os << std::setw(field_width) << std::setfill(' ') << std::left << name
        << " [" << std::setw(5) << std::setfill('0') << std::right << serial_num << "] ";
        
        if (full) {
            os << "Quantity " << std::setw(3) << std::setfill(' ') << std::left << quantity
            << "Description: " << desc;
        }
        os << std::endl;
    }
}
