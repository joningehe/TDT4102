// Lec2Ex1c.cpp, an improvement of Lec2Ex1c.cpp
#include "Graph.h"
#include "Simple_window.h"
#include "temperatures.hpp"

using namespace Graph_lib;



int main() {
    ifstream temp_file{"temperatur.txt"};
    Temps t;
    temp_file >> t;
    
    Point tl{ 100, 100 }; // tl is Top-Left corner of our window
    Point origo{ 40, 255 };
    Simple_window win(tl, 400, 300, "Exercise 6 task 5");
    Axis ya(Axis::y, origo, yAxisSize, 7, "Celsius (-20 .. +20)");
    win.attach(ya); // attach ya
    ya.set_color(Color::black);

    
    win.wait_for_button();
};
