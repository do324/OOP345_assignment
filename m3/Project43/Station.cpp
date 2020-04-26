//douyeon kim
//139766166
//2019-03-25

#include "Station.h"
#include<string>

namespace sict {
    
    Station::Station(const std::string& str) {
        item = new ItemSet(str);
    }
    
    void Station::display(std::ostream& os) const {
        item->display(os, true);
    }
    
    void Station::fill(std::ostream& os) {
        if (m_customerorders.size() != 0) {
            if (!m_customerorders.back().isItemFilled(getName())) {
                m_customerorders.back().fillItem(*item, os);
            }
        }
    }
    
    const std::string& Station::getName() const {
        return item->getName();
    }
    
    bool Station::hasAnOrderToRelease() const {
        
        if (m_customerorders.size() == 0) {
            return false;
        }
        else if (m_customerorders.front().isFilled() || item->getQuantity() == 0) {
            return true;
        }
        else return false;
    }
    
    Station& Station::operator--() {
        item->operator--();
        return *this;
    }
    
    Station& Station::operator+=(CustomerOrder&& order) {
        m_customerorders.push_back(std::move(order));
        return *this;
    }
    
    bool Station::pop(CustomerOrder& ready) {
        if (m_customerorders.size() == 0) {
            return false;
        }
    
        else {
            ready = std::move(m_customerorders.front());
            m_customerorders.pop_front();
            return true;
        }
    }
    
    void Station::validate(std::ostream& os) const {
        os << "getName(): " << item->getName() << std::endl;
        os << "getSerialNumber(): " << item->getSerialNumber() << std::endl;
        os << "getQuantity(): " << item->getQuantity() << std::endl;
    }
}
