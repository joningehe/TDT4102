//
//  MeetingWindow.hpp
//  FLTK-template
//
//  Created by Jon H on 07/03/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//
#pragma once
#ifndef MeetingWindow_hpp
#define MeetingWindow_hpp
#include "std_lib_facilities.h"
#include "Person.hpp"
#include "Window.h"
#include "GUI.h"

using namespace Graph_lib;

class Meeting_window : public Graph_lib::Window{
    Graph_lib::Point xy;
    int w;
    int h;
    const std::string title;
    
    static constexpr int pad{50};
    static constexpr int btnW{30};
    static constexpr int btnH{15};
    static constexpr int fieldW{100};
    static constexpr int fieldH{20};
    static constexpr int fieldPad{75};
    
    Button quit_button;
    Button person_new_btn;
    bool button_pushed;
    static void cb_quit();
    static void cb_new_person();
    
    In_box person_name;
    In_box person_email;
    
    Vector_ref<Person> people;
    
public:
    Meeting_window(Graph_lib::Point xy, int w, int h, const std::string &title) : Window
    {xy, w, h, title},
    quit_button{Point{x_max()-pad, y_max()-(y_max()-pad)}, btnW, btnH, "Quit", cb_quit},
    person_new_btn{Point{x_max()-400, y_max()-100}, btnW, btnH, "Add person", cb_new_person},
    button_pushed{false},
    person_name{Point{x_max()-(x_max()-fieldPad), y_max()-(y_max()-pad)}, fieldW, fieldH, "Name:"},
    person_email{Point{x_max()-(x_max()-fieldPad*4), y_max()-(y_max()-pad)}, fieldW, fieldH, "Email:"}
    {
        attach(quit_button);
        attach(person_new_btn);
        attach(person_name);
        attach(person_email);
    };
    
    static void cb_quit(Address, Address pw);
    static void cb_new_person(Address, Address pw);
    
    void add_person();
    
    void print_people();
};

#endif /* MeetingWindow_hpp */
