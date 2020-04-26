//douyeon kim
//139766166
//2019-03-25

#include <string>
#include <iostream>
#include "Utilities.h"

namespace sict {
    char Utilities::Delimiter_Character;
    
	Utilities::Utilities() : FieldWidth{0} {}
    
    const std::string Utilities::extractToken(const std::string str, size_t& next_pos) {
        
		std::string token;
        
        if (next_pos <= str.length()) {
            size_t pos_delimit = str.find(getDelimiter(), next_pos);
            
            if (pos_delimit != std::string::npos) {
                token = str.substr(next_pos, (pos_delimit-next_pos));
                next_pos = pos_delimit+1;
            }
            else {
                token = str.substr(next_pos);
                next_pos = str.length()+1;
            }
            
            if (token.length() == 0)
                throw "error!no token!";
            
            if (FieldWidth > token.length())
                FieldWidth = static_cast<int>(token.length());
            
        }
        return token;
    }
    
    const char Utilities::getDelimiter() const {
        return Delimiter_Character;
    }
    
    size_t Utilities::getFieldWidth() const {
        return FieldWidth;
    }
    
    void Utilities::setDelimiter(const char d) {
        Delimiter_Character = d;
    }
    
    void Utilities::setFieldWidth(size_t t) {
        FieldWidth = static_cast<int>(t);
    }
}
