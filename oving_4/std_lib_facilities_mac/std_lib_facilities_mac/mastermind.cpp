//
//  mastermind.cpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 07/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "mastermind.hpp"
#include "utilities.hpp"
#include "std_lib_facilities.h"

int checkCharactersAndPosition(const int size, const string code, string guess);
int checkCharacters(const int size, const string code, string guess);

void playMastermind() {
    constexpr int size = 4;
    constexpr int letters = 6;
    //constexpr brukes når vi trenger å si noe om verdien til et objekt før programmet har kjørt til det punktet den skal brukes, const bruker vi når verdien ikke nødvendigvis er kjent på forhånd, men programmet skal ikke ha lov til å endre på objektets verdi etter at den har mottatt det
    string code = randomizeString(size, 1, letters);
    std::cout << "Gjett hvilken kode på 4 bokstaver du har fått (A-F)" << endl;
    string guess = readInputToString(size, 1, letters);
    int posCount = checkCharactersAndPosition(size, code, guess);
    int totalCount = checkCharacters(size, code, guess);
    int forsok = 0;
    if(posCount != size) {
        while(forsok < 3){
            forsok += 1;
            std::cout << "Du har gjettet " << totalCount << " riktige bokstaver." << endl;
            std::cout << "Du klarte desverre ikke å gjette alle bokstavene i koden riktig, vil du prøve på nytt (Y/N)" << endl;
            char svar;
            std::cin >> svar;
            if (svar == 'Y') {
                std::cin >> guess;
                checkCharactersAndPosition(size, code, guess);
                checkCharacters(size, code, guess);
            }
            else{
                std::cout << "Game over :(" << endl;
                return;
            }
        }
    }
    else if(posCount == size) {
        std::cout << "Gratulerer du har gjettet " << posCount << " av " << size << " bokstaver riktig." << endl;
    }
    else {
        std::cout << "Du er tom for forsøk, game over :(" << endl;
    }
}

int checkCharactersAndPosition(const int size, const string code, string guess) {
    int count {0};
    for(int i {0}; i < size; ++i){
        if(code[i] == guess[i]) {
            count += 1;
        }
    }
    return count;
}

int checkCharacters(const int size, const string code, const string guess) {
    int count {0};
    for(int i {0}; i < size; ++i){
        if(countChar(code, guess[i]) >= 1) {
            count += 1;
    }
    return count;
}

    set<char>
    
/*
 //assert()
 */
