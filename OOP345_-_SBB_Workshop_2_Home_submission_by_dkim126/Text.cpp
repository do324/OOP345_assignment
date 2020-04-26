// Workshop 2 Move and Copy Semantics
// In-Lab
// Name: Doyeon Kim
// Student #: 139766166
// Course: OOP244 Fall 2018
// File: ws2.cpp

#include "Text.h"

namespace sict {
    Text::Text() {
    }

    Text::Text(const char *file) {
        std::ifstream f(file);
       
        size_t count = std::count(std::istreambuf_iterator<char>(f), std::istreambuf_iterator<char>(), '\n');
        
  

        strings = new std::string[count];
        if (f.is_open()) {
            while (f.good()) {
                for (size_t i = 0; i < count; ++i) {
                    f >> strings[i];
                }
            }
        }
       
        
		fileofname = file;
        recNo = count;
    }

	//copy construct
    Text::Text(const Text& obj) {
        *this = obj;
    }


	//copy operator
    Text& Text::operator=(const Text &rhs) {
		fileofname = rhs.fileofname;
        recNo = rhs.recNo;
        if (this != &rhs) {
            delete[] strings;
			strings = new std::string[recNo];

            for (size_t i = 0; i < recNo; ++i) {
				strings[i] = rhs.strings[i];
            }
        }
        return *this;
    }

	// move construct
	Text::Text(Text&& src)
	{
		*this = std::move(src);
	}

	// move operator
	Text& Text::operator=(Text&& src)
	{
		if (this != &src)
		{
			fileofname = src.fileofname;
			recNo = src.recNo;

			
			delete[] strings;

			strings = src.strings;
			src.strings = nullptr;
		}
		return *this;
	}


    Text::~Text() {
        delete[] strings;
		strings = nullptr;
    }

    size_t Text::size() const {
        return recNo;
    }
}