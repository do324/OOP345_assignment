// Workshop 2 Move and Copy Semantics
// In-Lab
// Name: Doyeon Kim
// Student #: 139766166
// Course: OOP244 Fall 2018
// File: ws2.cpp

#include "Timekeeper.h"

namespace sict {
    Timekeeper::Timekeeper() {
    }

    void Timekeeper::start() {
        ts = std::chrono::steady_clock::now();
    }

    void Timekeeper::stop() {
        te = std::chrono::steady_clock::now();
    }

    void Timekeeper::recordEvent(const char* msg) {
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds> (te - ts);
        if (noRecords < MAX) {
            this->record[noRecords].msg = msg;
            this->record[noRecords].tUnit = " seconds";
            this->record[noRecords].dur = ms;
            noRecords++;
        }
    }

    void Timekeeper::report(std::ostream& os) const {
        os << "\nExecution Times:\n";
        for (int i = 0; i < noRecords; ++i) {
            os << record[i].msg << ' ' << std::setw(5) << record[i].dur.count() / 1000000 << record[i].tUnit << std::endl;
        }
    }

}