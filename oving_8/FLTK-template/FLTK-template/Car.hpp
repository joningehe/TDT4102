//
//  Car.hpp
//  FLTK-template
//
//  Created by Jon H on 05/03/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//
#pragma once
#ifndef Car_hpp
#define Car_hpp

#include <stdio.h>

class Car {
    int freeSeats;
public:
    Car(int seats) {freeSeats = seats;}
    bool hasFreeSeats() const;
    void reserveFreeSeat();
};


#endif /* Car_hpp */
