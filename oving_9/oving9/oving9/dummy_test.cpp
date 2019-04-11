//
//  dummy_test.cpp
//  oving9
//
//  Created by Jon H on 13/03/2019.
//  Copyright © 2019 JonH. All rights reserved.
//
#include <iostream>
#include "dummy_test.hpp"
#include "Matrix.hpp"

void dummy_test() {
    Dummy a;
    *a.num = 4;
    Dummy b{a};
    Dummy c;
    c=a;
    std::cout << "a: " << *a.num << "\n";
    std::cout << "b: " << *b.num << "\n";
    std::cout << "c: " << *c.num << "\n";
    
    *b.num = 3;
    *c.num = 5;
    
    std::cout << "a: " << *a.num << "\n";
    std::cout << "b: " << *b.num << "\n";
    std::cout << "c: " << *c.num << "\n";
    
    std::cin.get();
}

void matrix_test() {
    Matrix a(5, 5);
    Matrix b(a);
    Matrix c;
    c = a;
    std::cout << "a: " << a << "\n\n";
    std::cout << "b: " << b << "\n\n";
    std::cout << "c: " << c << "\n\n";
    
    b.set_matrix(0, 0, 10.0110);
    c.set_matrix(0, 0, 11.1111);
    
    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
    std::cout << "c: " << c << "\n";
}

void matrix_add_test(){
    Matrix a(15,15);
    Matrix b(15, 15);
    Matrix c(15, 15);
    a.set_matrix(0, 0, 10);
    a.set_matrix(0, 1, 5);
    b.set_matrix(0, 0, 20);
    b.set_matrix(0, 1, 7);
    c.set_matrix(0, 0, 100);
    c.set_matrix(0, 1, 500);
    a+=b;
    std::cout << a;
    b=a+c;
    std::cout << b;
}
