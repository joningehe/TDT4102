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
    const int increment = 2;
    const int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    std::cout << "v0: " << v0 << " increment: " << increment << " iterations: " << iterations << " result: " << result << endl;
}

void testCallByReference() {
    int v0 = 5;
    const int increment = 2;
    const int iterations = 10;
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
    
    swapNumbers(value1, value2);
    std::cout << "value1 er: " << value1 << " value2 er: " << value2 << endl;
}

/*void testVectorSorting() {
    vector<int> percentages {};
    randomizeVector(percentages);
    std::cout << percentages[0] << " og " << percentages[1] << endl;
    swapNumbers(percentages[0], percentages[1]);
    std::cout << percentages[0] << " og " << percentages[1] << endl;
}*/

void testVectorSorting() {
    vector<int> percentages {};
    randomizeVector(percentages);
    std::cout << medianOfVector(percentages);
    sortVector(percentages);
    std::cout << medianOfVector(percentages);
}

void randomizeVector(vector<int>& percentages) {
    for(int i = 0; i < 10; ++i) {
        srand(static_cast<unsigned int>(time(nullptr)+i));
        percentages.push_back(rand() % 100 + 0); //kunne også brukt randint()
    }
}


void testString() {
    string grades = randomizeString(8, 1, 6);   //1 = "A" og 6 = "F", kunne brukt 0 og 6 uten -1 i formelen på randomizeString, men tror dette er en bedre måte å gjøre det på
    std::cout << grades << endl;
    vector<int> gradeCount {};
    for(int i = 0; i < 5; ++i) {
        gradeCount[0] = countChar(grades, 'A');
        gradeCount[1] = countChar(grades, 'B');
        gradeCount[2] = countChar(grades, 'C');
        gradeCount[3] = countChar(grades, 'D');
        gradeCount[4] = countChar(grades, 'E');
        gradeCount[5] = countChar(grades, 'F');
    }
    double average = (gradeCount[0]*5 + gradeCount[1]*4 + gradeCount[2]*3 + gradeCount[3]*2 + gradeCount[4]*1)/grades.size();
    std::cout << "Gjennomsnittkarakteren er: " << average << endl;
}
