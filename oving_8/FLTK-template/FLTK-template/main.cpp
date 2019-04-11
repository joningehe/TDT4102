    //Under er de pre-definerte headersene som skal inkluderes
#include "std_lib_facilities.h"
#include "Graph.h"
#include "GUI.h"
#include "Window.h"
#include "Car.hpp"
#include "Person.hpp"
#include "Meeting.hpp"
#include "MeetingWindow.hpp"

int main() {
    Car bil{5};
    std::cout << bil.hasFreeSeats() << endl;
    
    Person forer{"Jon", "jon@online.ntnu.no"};
    std::cout << forer << endl;;
    Person forer_to{"Marius", "marius@online.ntnu.no"};
    std::cout << forer_to << endl;
    Person forer_tre{"Øyvind", "øyvind@online.ntnu.no"};
    std::cout << forer_tre << endl;
    
    std::cout << Campus::Gjøvik;
    
    //Meeting mote{25, 10, 12, Campus::Trondheim, "Jon", &forer};
    Meeting mote_to{25, 10, 13, Campus::Trondheim, "Marius", &forer_to};
    Meeting mote_tre{25, 12, 14, Campus::Gjøvik, "Øyvind", &forer_tre};
    
    //std::cout << mote << endl;
    std::cout << mote_to << endl;
    std::cout << mote_tre << endl;
    
    Meeting_window test{Graph_lib::Point{100, 100}, 500, 500, "Test"};
    Graph_lib::gui_main();
    test.print_people();
    
    return 0;
};
