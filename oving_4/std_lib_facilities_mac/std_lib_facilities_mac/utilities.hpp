//
//  utilities.hpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 31/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#pragma once
#ifndef utilities_hpp
#define utilities_hpp

#include <stdio.h>

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);
int swapNumbers(int value1, int& value2);

#endif /* utilities_hpp */
