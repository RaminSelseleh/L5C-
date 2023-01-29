/**
 * Main
 */

#include <iostream>
#include <assert.h>
#include <sstream>
#include "Time.h"
//#include "Time.cpp"


using namespace std;

int main() {

    Time zeroTime;
    assert(zeroTime.get_hour() == 0);
    assert(zeroTime.get_minute() == 0);
    assert(zeroTime.get_second() == 0);

    Time TimeA(1, 1, 1);
    assert(TimeA.get_hour() == 1);
    assert(TimeA.get_minute() == 1);
    assert(TimeA.get_second() == 1);

    Time badTime(99, 99, 99);
    assert(badTime.get_hour() == 0);
    assert(badTime.get_minute() == 0);
    assert(badTime.get_second() == 0);

    Time TimeB(12, 14, 43);
    assert(TimeB.get_hour() == 12);
    assert(TimeB.get_minute() == 14);
    assert(TimeB.get_second() == 43);

    Time badTime2(25, 70, 60);
    assert(badTime2.get_hour() == 0);
    assert(badTime2.get_minute() == 0);
    assert(badTime2.get_second() == 0);

    Time maxTime(23, 59, 59);
    assert(maxTime.get_hour() == 23);
    assert(maxTime.get_minute() == 59);
    assert(maxTime.get_second() == 59);

    Time badTime3(20, 70, 99);
    assert(badTime3.get_hour() == 20);
    assert(badTime3.get_minute() == 0);
    assert(badTime3.get_second() == 0);

    // testing == operator
    Time anotherZero;
    assert(zeroTime.get_hour() == 0);
    assert(zeroTime.get_minute() == 0);
    assert(zeroTime.get_second() == 0);

    assert(zeroTime == anotherZero);


    // convert object output so we can compare with a string
    std::stringstream buffer;
    zeroTime.set_24Hour(true);
    buffer.str(""); // since we are reusing the buffer we need to clear it before using
    buffer << zeroTime;
    assert(buffer.str().compare("0:0:0") == 0);

    zeroTime.set_24Hour(false);
    buffer.str("");
    buffer << zeroTime;
    assert(buffer.str().compare("12:0:0 AM") == 0);


    maxTime.set_24Hour(true);
    buffer.str(""); 
    buffer << maxTime;
    assert(buffer.str().compare("23:59:59") == 0);


    maxTime.set_24Hour(false);
    buffer.str(""); 
    buffer << maxTime;
    assert(buffer.str().compare("11:59:59 PM") == 0);

    return 0;
}
