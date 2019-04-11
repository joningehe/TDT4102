//
//  main.cpp
//  oving9
//
//  Created by Jon H on 12/03/2019.
//  Copyright © 2019 JonH. All rights reserved.
//

#include <iostream>
#include "fibonacciNumbers.hpp"
#include "Matrix.hpp"
#include "dummy_test.hpp"

int main(int argc, const char * argv[]) {
    
    //createFibonacci();
    
    Matrix test1;
    Matrix test2(5, 5);
    test2.set_matrix(0, 0, 1.1);
    test2.set_matrix(0, 4, 1.4);
    Matrix test3(5);
    std::cout << test1 << "\n";
    std::cout << test2 << "\n";
    std::cout << test3 << "\n";
    std::cout << test2.is_valid() << "\n";
    
    
       /* Oppgave 3a)
     a: 4
     b: 4
     c: 4
     a: 5
     b: 5
     c: 5
     
     What heppens here is that we create a pointer and give it a value of 4, we then create two new pointers refering to the original one and print the value of a specific address 3 times. We then override 4 with 3 and 3 with 5 before we do the same thing. As all of the pointers share the same address, they will have the same value as well.
     */
    
    //dummy_test();
    
    /*
        Oppgave 3b)
     We initially assign a pointer to a new adress on the assigned memory, every subsequent pointer referes to this originally adress and doesn't ask for a new memory assignment, yet we still try to clean up an address that has already been deleted. We are no longer pointing to an object on the heap, but now on the stack.
     */
    
    /*
        Oppgave 3c)
     Yes, the program writes something different as it now creates a new int with a different address than the first one, it does not save this however
     */
    
    /*
        Oppgave 3d)
     The program now works as we want it to, it swaps the addresses and cleans up after itself so at no point does it try to delete an already cleaned up address and makes sure that every value gets the most recent specified value. We can now create multiple objects with the same value as the original object, without knowing it's value and where on the heap it is, and update each individual object without changing another's value.
     */
    
    matrix_test();
    matrix_add_test();
    
    return 0;
}
