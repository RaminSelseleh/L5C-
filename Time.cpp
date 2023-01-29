/*
 * Time.cpp
 */

#include "Time.h"
#include <iostream>
#include <ostream>

/**
 * @brief Construct a new Time:: Time object
 * 
 */
Time::Time() : hour(0), minute(0), second(0) {

}

/**
 * @brief Construct a new Time:: Time object
 * 
 * @param hour  hour value
 * @param minute  minute value
 * @param second  second value
 */
Time::Time(unsigned int hour, unsigned int minute, unsigned int second) {
    if (hour < 24) {
        this->hour = hour;
    } else {
        this->hour = 0;
    }
    
    if (minute < 60) {
        this->minute = minute;
    } else {
        this->minute = 0;
    }

    if (second < 60) {
        this->second = second;
    } else {
        this->second = 0;
    }

}

Time::~Time() {
    
}

unsigned int Time::get_hour() {
    return hour;
}

unsigned int Time::get_minute() {
    return minute;
}

unsigned int Time::get_second() {
    return second;
}

void Time::set_24Hour(bool display24) {
    this->display24 = display24;
}



/**
 * @brief 
 * 
 * @param rhs 
 * @return true 
 * @return false 
 */
bool Time::operator==(const Time &rhs) {
    return this->time_to_seconds() == rhs.time_to_seconds();

}

/**
 * @brief 
 * 
 * @param os 
 * @param time 
 * @return std::ostream& 
 */
std::ostream& operator <<(std::ostream& os, const Time& time) {
    //bool display24;
    if (time.display24) {
        // is true, output 24 time
        os << time.hour << ":" << time.minute << ":" << time.second;
        
    }
    else {
        // output 12 time
        if (time.hour > 12) {
            int rr;
            rr = time.hour - 12;
            os << rr << ":" << time.minute << ":" << time.second << " PM";
        }
        if (time.hour <= 12) {
            int zz;
            zz = time.hour;
            if (zz == 0) {
                zz = 12;
            }
            os << zz << ":" << time.minute << ":" << time.second << " AM"; 

        } 
        return os;
    }
    return os;

}

unsigned int Time::time_to_seconds() const {
    return second + (minute * 60) + (hour * 3600);
}
