//
//  temperatures.cpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 20/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#include "std_lib_facilities.h"
#include "temperatures.hpp"
istream& operator>> (istream& is, Temps& t){
    double a, b;
    while (is >> a >> b)
    {
        t.max = a;
        t.maxtemp.push_back(t.max);
        t.min = b;
        t.mintemp.push_back(t.min);
    }
    return is;
}
