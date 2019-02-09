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
#include "masterVisual.h"

int checkCharactersAndPosition(const int size, const string code, string guess);

void playMastermind() {
    constexpr int win_w = 400;
    constexpr int win_h = 600;
    constexpr int size = 4;
    constexpr int letters = 6;
    //Bruker constexpr fordi disse variabelene bør kompileres først som en følge av at de vil påvirke parameterne i de sentrale funksjonene som brukes i spillet
    //Kunne brukt const om disse variabelene ble brukt på et senere tidspunkt etter at andre funksjoner alt hadde begynt å kjørt da
    //constexpr brukes når vi trenger å si noe om verdien til et objekt før programmet har kjørt til det punktet den skal brukes, const bruker vi når verdien ikke nødvendigvis er kjent på forhånd, men programmet skal ikke ha lov til å endre på objektets verdi etter at den har mottatt det
    string code = randomizeString(size, 0, letters-1);
    std::cout << "Gjett hvilken kode på 4 bokstaver du har fått (A-F)" << endl;
    string guess;
    std::cin >> guess;
    int forsok = 0;
    MastermindWindow mwin{Point{900, 20}, win_w, win_h, "Mastermind"};
    addGuess(MastermindWindow& mwin, code, size, guess[0], forsok);
    int count = checkCharactersAndPosition(size, code, guess);
    if(count != size) {
        forsok += 1;
        while(forsok < 3){
            std::cout << "Du klarte desverre ikke å gjette alle bokstavene i koden riktig, vil du prøve på nytt (Y/N)" << endl;
            char svar;
            std::cin >> svar;
            if (svar == 'Y') {
                std::cin >> guess;
                checkCharactersAndPosition(size, code, guess);
            }
            else{
                std::cout << "Game over :(" << endl;
            }
        }
    }
    else if(count == size) {
        std::cout << "Gratulerer du har gjettet " << count << " av " << size << " bokstaver riktig." << endl;
    }
    else {
        std::cout << "Du er tom for forsøk, game over :(" << endl;
    }
}


//Aight så funksjonen her er ganske dirty, men den looper basically gjennom de to strengene først og kutter av om den finner liknende bokstaver, deretter sjekker den om posisjon, henholdsvis i og j, samsvarer. I begge situasjonene legger den til +1 på count for riktig.
//Denne kan effektiviseres med gjenbruk, bruk først countChar og deretter lag en ny som kun sjekker posisjon, dette er mer effektivt da mindre kan fucke seg
int checkCharactersAndPosition(const int size, const string code, string guess) {
    int count = 0;
    for(int i = 0; i < size; ++i){
        int j = 0;
        while((j < size) and (code[i] != guess[j])){
            if(code[i] == guess[j]) {
                break;
            }
            j += 1;
        }
        if ((code[i] == guess[j]) and (i == j)) {
            std::cout << "Bokstaven " << code[i] << "er en del av spillet og du har gjettet riktig posisjon." << endl;
            count += 1;
        }
        else if((code[i] == guess[j]) and (i != j)) {
            std::cout << "Bokstaven " << code[i] << "er en del av spillet, men du har gjettet feil posisjon." << endl;
            count += 1;
        }
        else {
            std::cout << "Bokstaven er ikke en del av spillet." << endl;
        }
    }
    if(count != size) {
        std::cout << "Du har desverre gjettet feil kode, prøv på nytt." << endl;
        return count;
    }
    else {
        return count;
    }
    return 0;
}

//Aight todo her er å fikse programmet helt, legg på error-handling og clean up koden vesentlig da den er ganske stygg, se også på hva mer som kan gjøres.
