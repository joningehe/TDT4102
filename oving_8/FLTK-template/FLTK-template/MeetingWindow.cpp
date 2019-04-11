//
//  MeetingWindow.cpp
//  FLTK-template
//
//  Created by Jon H on 07/03/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//
#include "std_lib_facilities.h"
#include "MeetingWindow.hpp"
#include "Window.h"
#include "GUI.h"

using namespace Graph_lib;

void Meeting_window::cb_quit(Address, Address pw){
    reference_to<Meeting_window>(pw).hide();
}

void Meeting_window::cb_new_person(Address, Address pw){
    reference_to<Meeting_window>(pw).add_person();
}

void Meeting_window::add_person(){
    Person *temp = new Person{person_name.get_string(), person_email.get_string()};
    people.push_back(*temp);
}

void Meeting_window::print_people(){
    for(auto c : people){
        std::cout << *c << endl;
    }
}
