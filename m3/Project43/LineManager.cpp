//douyeon kim
//139766166
//2019-03-25

#include <string>
#include <ostream>
#include "LineManager.h"

using namespace std;

namespace sict {
    
	LineManager::LineManager(std::vector<Station*>& st_add, std::vector<size_t>& size_st, std::vector<CustomerOrder>& cus_or, size_t start, std::ostream& os) {
        
        for (auto& i : cus_or) {
            incomplete.push_front(std::move(i));
        }

        count = incomplete.size();

       
        station.push_back(st_add[start]);  //address
        station.push_back(st_add[0]);
        station.push_back(st_add[2]);
        station.push_back(st_add[1]);
        station.push_back(st_add[3]);
    }
    
   
    void LineManager::display(std::ostream& os) const {
        os << "COMPLETED ORDERS\n";
        for (auto& i : complete) {
            i.display(os, true);
        }
        os << std::endl;
        os << "INCOMPLETE ORDERS\n";
        for (auto& i : incomplete) {
            i.display(os, true);
        }
    }
    
    bool LineManager::run(std::ostream& os) {
		
        static int counting; 
        CustomerOrder customerorders; 
        
        
        while(incomplete.size()) {
            station[counting]->operator+=(std::move(incomplete.back()));
            incomplete.pop_back();
            
            station[counting]->fill(os);
        }
        
        
        for (size_t i = 0; i < count; i++) {
            if (station[counting]->pop(customerorders)) {
                incomplete.push_back(std::move(customerorders));
                
				cout << "--> " << incomplete.back().getNameProduct() << " moved from " << station[counting]-> getName() << " to ";
                
                if (incomplete.back().isFilled()) {
                    os << "Complete Set" << std::endl;
                    complete.push_front(std::move(incomplete.back()));
                    incomplete.pop_back();
                }
                else if (counting < count) {
                    os << station[counting+1]->getName() << std::endl;
                }
                else {
                    os << "Incomplete Set" << std::endl;
                }
            }
        }
        
       counting++;
        
	   if (counting == count+1) {
            return true;
        }
        return false;
    }
}
