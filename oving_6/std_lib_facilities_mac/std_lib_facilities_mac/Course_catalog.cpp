//
//  Course_catalog.cpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 19/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#include "std_lib_facilities.h"
#include "Course_catalog.hpp"           

void Course_catalog::addCourse(){
    std::cout << "Type in the short name of the subject to add: ";
    std::string emnekode;
    std::cin >> emnekode;
    std::cout << "Type in the full name of the subject too add:" << endl;
    std::string emnenavn;
    std::cin >> emnenavn;
    
    //Updates the map with course code and name through .insert() function
    /*
    std::map<std::string,std::string>::iterator it = emne_liste.begin();
    emne_liste.insert (it, std::pair<std::string,std::string>(emnekode, emnenavn));
    emne_liste.at("TDT4102") = "C++";
    */
    
    //Updates the map with course code and name through operator[]
    emne_liste[emnekode] = emnenavn;
    
    //Usikker på hva oppgaven mener så velger bare å gjøre det slik:
    if(emnekode == "TDT4102"){
        emne_liste["TDT4102"] = "C++";
    }
        

    //One way to do it, this is optimal if we want to add stuff automatically based on other vectors, but it is a bit too specific for our use so use above method
    /*emne_liste.insert(std::pair<std::string, std::string>(emnekode, emnenavn));
    std::pair<std::map<std::string,std::string>::iterator,bool> emner;
    emner = emne_liste.insert ( std::pair<std::string,std::string>(emnekode, emnenavn) );
    if (emner.second==false) {
        std::cout << "element" << emnekode << "already existed";
        std::cout << " with a value of " << emner.first->second << '\n';
    }*/
 
}
 
void Course_catalog::removeCourse(){
    std::cout << "Type in the short name of the subject to remove: ";
    std::string emnekode;
    std::cin >> emnekode;
    emne_liste.erase(emnekode);
}

std::string Course_catalog::getCourse(){
    std::cout << "Type in the short name of the subject you want to find: ";
    std::string emne;
    std::cin >> emne;
    std::cout << emne_liste[emne] << endl;;
    return emne_liste[emne];
}

ostream& operator << (ostream& output, const Course_catalog& emner){
    for (auto const& emne : emner.emne_liste) {
        output << emne.first << ": " << emne.second << endl;
    }
    return output;
}

//Leser fra file
void Course_catalog::read(){
    std::string filename = "emneliste.txt";
    ifstream ist {filename};
    char c;
    while(ist.get(c)){
        std::cout << c;
    }
}

//Skriver til file
void Course_catalog::write(){
    std::string filename = "emneliste.txt";
    ofstream ost {filename};
    for(auto const &emne : emne_liste){
        ost << emne.first << ": " << emne.second << ", ";
    }
}

//Usikker på hvordan oppgaven skulle løses, men alternativet her er å løse oppgaven ved å behandle teksten som blir lest inn, legge til nøkler-values i temp map, legge til nye fra 'write' i temp map og skrive hele temp map til filen (oveskrive forrige), enklere å bare appende doe
//Legger til file
void Course_catalog::read_and_write(){
    fstream file;
    file.open("emneliste.txt", fstream::app);
    if(file.is_open()){
        for(auto const& emne : emne_liste){
            file << emne.first << ": " << emne.second << ", ";
        }
        file.close();
    }
}
