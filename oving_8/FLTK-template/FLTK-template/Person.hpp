//
//  Person.hpp
//  FLTK-template
//
//  Created by Jon H on 05/03/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//
#pragma once
#ifndef Person_hpp
#define Person_hpp
#include "std_lib_facilities.h"
#include <stdio.h>
#include "Car.hpp"

class Person {
    std::string name;
    std::string email;
    Car *car;
public:
    Person(std::string name, std::string email,Car *car = nullptr)  //obs, nullptr må defineres her når pointeren blir deklarert som et parameter i konstruktøren
        : name(name)
        , email(email)
        , car(car)  //denne tok inn 0 når jeg skrev car(nullptr), nullptr skulle i Person()
    {}
    std::string getName() const;
    std::string getEmail() const;
    void setEmail();
    bool hasAvailableSeats() const;
    friend std::ostream &operator<<(std::ostream &os, const Person& p);
};

#endif /* Person_hpp */
