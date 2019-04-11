//
//  temperatures.hpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 20/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#pragma once
#include "std_lib_facilities.h"

class Temps {
    double max;
    double min;
public:
    vector<double> maxtemp;
    vector<double> mintemp;
    friend istream& operator>> (istream& is, Temps& t);
};
