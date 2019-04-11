#include "std_lib_facilities.h"
#include "File_manager.hpp"
#include "Course_catalog.hpp"
#include "temperatures.hpp"

int main(){
    /*//Emnekatalog
    Course_catalog test;
    for(int i{0}; i < 3; ++i){
        test.addCourse();
    }
    test.removeCourse();
    test.getCourse();   //denne skal brukes i oppgave e
    cout << test;
    test.write();
    test.read();
    */
    //Lesing av en strukturert fil
    ifstream temp_file{"temperatur.txt"};
    Temps t;
    vector<Temps> temps;
    while(temp_file >> t){  //hjelp i r1, strømmer og filer
        temps.push_back(t);
    }
    
    return 0;
}
