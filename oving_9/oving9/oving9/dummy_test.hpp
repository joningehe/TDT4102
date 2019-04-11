//
//  dummy_test.hpp
//  oving9
//
//  Created by Jon H on 13/03/2019.
//  Copyright © 2019 JonH. All rights reserved.
//

#ifndef dummy_test_hpp
#define dummy_test_hpp

#include <stdio.h>
#include <utility>

class Dummy{
public:
    int *num;
    Dummy(){num=new int{0};}
    //This is the copy-constructor
    Dummy(const Dummy &other) : num{nullptr} {this->num = new int{}; *num = *other.num;}
    //This is a copy-and-swap operator
    Dummy &operator=(Dummy rhs){std::swap(num, rhs.num); return *this;}
    ~Dummy(){delete num;}
};

void dummy_test();
void matrix_test();
void matrix_add_test();

#endif /* dummy_test_hpp */
