//
//  utilities.cpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 31/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#include "utilities.hpp"

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; ++i) {
        startValue += increment;
    }
}

int swapNumbers(int value1, int& value2) {
    int temp = value2;
    value2 = value1;
    return temp;
}
