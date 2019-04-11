//
//  fibonacciNumbers.cpp
//  oving9
//
//  Created by Jon H on 12/03/2019.
//  Copyright © 2019 JonH. All rights reserved.
//
#include <iostream>
#include "fibonacciNumbers.hpp"

//Finnes kanskje en mer ellegant måte å gjøre denne på.
void fillInFibonacciNumbers(int result[], int length) {
    int temp{0};
    int temp2{1};
    int next{0};
    result[0] = temp;
    for(int i{1}; i < length; i++){
        result[i] = next;
        next = temp + temp2;
        temp = temp2;
        temp2 = next;
    }
}

void printArray(int arr[], int length) {
    for(int i{0}; i < length; i++){
        std::cout << arr[i] << ", ";
    }
}

void createFibonacci() {
    std::cout << "Enter the length of your Fibonacci sequence: ";
    int length;
    std::cin >> length;
    
    int *arr = new int[length] {};
    
    fillInFibonacciNumbers(arr, length);
    printArray(arr, length);
    
    delete[] arr;
    arr = nullptr;
}
