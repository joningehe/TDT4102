//
//  Car.cpp
//  FLTK-template
//
//  Created by Jon H on 05/03/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//
#include "std_lib_facilities.h"
#include "Car.hpp"
bool Car::hasFreeSeats() const{
    return freeSeats;
}

void Car::reserveFreeSeat(){
    if (hasFreeSeats()){
        std::cout << "How many seats would you like to reserve?" << endl;
        int temp;
        std::cin >> temp;
        while(temp > freeSeats){
            std::cout << "Sorry, it's not possible to reserve that many seats. Please enter a valid number:" << endl;
            std::cin >> temp;
        }
        freeSeats -= temp;
    }
    else{
        std::cout << "No seats available." << endl;
    }
}
