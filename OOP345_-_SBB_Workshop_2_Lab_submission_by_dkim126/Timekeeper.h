// Workshop 2 Move and Copy Semantics
// In-Lab
// Name: Doyeon Kim
// Student #: 139766166
// Course: OOP244 Fall 2018
// File: Timekeeper.h

#ifndef TIME_KEEPER_H
#define TIME_KEEPER_H
#include <iostream>
#include <chrono>
#include <iomanip>

namespace sict {
    const int MAX = 10;
    class Timekeeper {
        int noRecords {0};
        typename std::chrono::steady_clock::time_point ts;
        typename std::chrono::steady_clock::time_point te;
        struct {
            const char *msg;
            const char *tUnit;
            std::chrono::steady_clock::duration dur;
        } record[MAX];
    public:
        Timekeeper();
        void start();
        void stop();
        void recordEvent(const char*);
        void report(std::ostream&) const;
    };
}

#endif