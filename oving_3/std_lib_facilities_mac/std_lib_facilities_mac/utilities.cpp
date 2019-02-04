//
//  utilities.cpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 29/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "utilities.hpp"

int randomWithLimits(int lowerLimit, int upperLimit) {
    srand(static_cast<unsigned int>(time(nullptr)));
    int tilfeldig_tall = (rand() % (upperLimit-lowerLimit) + lowerLimit);
    return tilfeldig_tall;
}
//Returns a random number between lower- and upper-limit.
//rand() % (difference in roof anf floor) + floor
