// Workshop 2 Move and Copy Semantics
// In-Lab
// Name: Doyeon Kim
// Student #: 139766166
// Course: OOP244 Fall 2018
// File: ws2.cpp

#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>

namespace sict {
    class Text {
        std::string fileofname;
        std::string* strings;
        size_t recNo;
    public:
        Text();
        Text(const char*);
        Text(const Text &);
        Text& operator=(const Text &);
		////
		Text(Text&&);
		Text& operator=(Text&&);
		////
        ~Text();
        size_t size() const;
    };
}

#endif