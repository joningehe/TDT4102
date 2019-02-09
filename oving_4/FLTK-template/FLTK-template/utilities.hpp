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
#include "std_lib_facilities.h"
#include <stdio.h>

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);

void swapNumbers(int& value1, int& value2);

void sortVector(vector<int>& liste);

double medianOfVector(vector<int> liste);

string randomizeString(int length, int lowerBound, int upperBound);
string reatInputToString(int length, int lowerBound, int upperBound);

int countChar(string streng, char kar);

#endif /* utilities_hpp */
