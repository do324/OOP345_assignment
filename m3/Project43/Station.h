//douyeon kim
//139766166
//2019-03-25

#ifndef Station_h
#define Station_h

#include <iostream>
#include <deque>
#include "CustomerOrder.h"

using namespace std;

namespace sict {
    class Station {
        std::deque<CustomerOrder> m_customerorders;
        ItemSet* item;
    public:
        Station(const std::string&);
        void display(std::ostream&) const;
        void fill(std::ostream&);
        const std::string& getName() const;
        bool hasAnOrderToRelease() const;
        Station& operator--();
        Station& operator+=(CustomerOrder&&);
        bool pop(CustomerOrder&);
        void validate(std::ostream&) const;
        Station(const Station&) = delete;
        Station(Station&&) = delete;
        Station& operator=(const Station&) = delete;
        Station& operator=(Station&&) = delete;
    };
}
#endif
