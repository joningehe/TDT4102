//
//  tests.cpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 31/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#include "std_lib_facilities.h"
#include "tests.hpp"
#include "utilities.hpp"
void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    std::cout << "v0: " << v0 << " increment: " << increment << " iterations: " << iterations << " result: " << result << endl;
}

void testCallByReference() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, increment, iterations);
    std::cout << "v0: 5" << " increment: " << increment << " iterations: " << iterations << " result: " << v0 << endl;
}

void testSwapNumbers() {
    std::cout << "Skriv inn tall 1: " << endl;
    int value1;
    std::cin >> value1;
    
    std::cout << "Skriv inn tall 2: " << endl;
    int value2;
    std::cin >> value2;
    
    value1 = swapNumbers(value1, value2);
    std::cout << "value1 er: " << value1 << " value2 er: " << value2 << endl;
}

void testVectorSorting() {
    vector<int> percentages {};
    randomizeVector(percentages);
    swapNumbers(percentages[0], percentages[1]);
}

void randomizeVector(vector<int>& percentages) {
    for(int i = 0; i < 10; ++i) {
        srand(static_cast<unsigned int>(time(nullptr)));
        percentages.push_back(rand() % 100 + 0); //kunne også brukt randint()
    }
}
