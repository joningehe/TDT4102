//
//  File_manager.cpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 19/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#include "std_lib_facilities.h"
#include "File_manager.hpp"

//Following function let's the user write words to new lines.
void write_words_to_file(){
    std::cout << "Enter the name of the file you want to open: ";
    std::string oname;
    std::cin >> oname;
    std::ofstream ost{oname};
    if(!ost) error("can't open file ", oname);
    
    std::string input_string;
    
    std::string word;
    do{
        std::cin >> word;
        if(word != "quit"){input_string += word+"\n";};
    }while(word != "quit");
    
    ost << input_string;
}

//Following function let's the user write words to a complete text.
void write_text_to_file(){
    std::cout << "Enter the name of the file you want to open: ";
    std::string oname;
    std::cin >> oname;
    std::ofstream ost{oname};
    if(!ost) error("can't open file ", oname);
    
    std::string input_string = "";
    
    std::string word;
    do{
        std::cin >> word;
        if(word != "quit"){
            for(char c : word){
                input_string.push_back(c);
            }
            input_string.push_back(32);
        }
    }while(word != "quit");
    
    ost << input_string;
}

//Reads from one file and writes them to another
void read_from_file() {
    //Reads from any given file
    std::cout << "Enter the name of the file you want to open: ";
    std::string iname;
    std::cin >> iname;
    std::ifstream ist{iname};
    if(!ist) error("can't open file ", iname);
    
    //Creates a new file in the same directory
    std::ofstream ost{"lest_fra_fil.txt"};
    
    //Writes from one file to another
    
    std::string temporary;
    int line {1};
    while(std::getline(ist, temporary)){
        ost << to_string(line) << temporary << "\n";
        line += 1;
    }
}


//tegnstatistikk
void character_count(string filename){
    //Map of all characters in the alphabet and their values (how many times they have been counted), could also have created this using a loob and upping the char with 'a'+n
    std::map<const char, int> alphabet {{'a', 0}, {'b', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0}, {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0}, {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0}};
    
    std::ifstream ist{filename};
    char c;
    while(ist.get(c)){
        c = std::tolower(c);
        if(isalpha(c)){alphabet[c] += 1;}
    }
    
    for (auto& x: alphabet) {
        std::cout << x.first << ": " << x.second << endl;
    }
}
