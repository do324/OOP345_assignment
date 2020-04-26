//douyeon kim
//139766166
//2019-03-25
#ifndef Utilities_h
#define Utilities_h
#include <iostream>
#include<string>
using namespace std;
namespace sict {
    class Utilities {
        unsigned int FieldWidth;
        static char Delimiter_Character;
    public:
        Utilities();
        const std::string extractToken (const std::string, size_t&);
        const char getDelimiter() const;
        size_t getFieldWidth() const;
        static void setDelimiter(const char);
        void setFieldWidth(size_t);
        
        
        Utilities(const Utilities&) = delete;
        Utilities& operator=(const Utilities&) = delete;
        Utilities& operator=(Utilities&&) = delete;
    };
}
#endif
