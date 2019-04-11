//
//  Person.cpp
//  FLTK-template
//
//  Created by Jon H on 05/03/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//
#include "std_lib_facilities.h"
#include "Person.hpp"
#include "Car.hpp"
std::string Person::getName() const{
    return name;
}

std::string Person::getEmail() const{
    return email;
}

void Person::setEmail(){
    std::cout << "Enter email:" << endl;
    std::cin >> email;
}

bool Person::hasAvailableSeats() const{
    return car->hasFreeSeats();
}

std::ostream &operator<<(std::ostream &os, const Person& p){
    return std::cout << p.name << "\n" << p.email << endl; //må få denne til å vise innholdet i p
}
