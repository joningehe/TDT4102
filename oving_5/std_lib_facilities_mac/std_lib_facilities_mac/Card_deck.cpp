//
//  Card_deck.cpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 14/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#include "std_lib_facilities.h"
#include "Card_deck.hpp"
#include "Card.hpp"


//Stygg af, sjekk ut hvordan jeg skal gjøre denne fin :))))
/*Card_deck::Card_deck() {
    int i = 0;
    while(i < 52){
        if(i == 0){
            Card_deck::current_card_index = 0;
        }
        int j {2};
        while(i < 13) {
            Rank r = static_cast<Rank>(j);
            Card c(Suit::clubs, r);
            if(c.isValid(Suit::clubs, r)){
                card.push_back(c);
            }
            j += 1;
            i += 1;
        }
        j = 2;
        while(i>=13 && i<26) {
            Rank r = static_cast<Rank>(j);
            Card d(Suit::diamonds, r);
            if(d.isValid(Suit::diamonds, r)){
                card.push_back(d);
            }
            j += 1;
            i += 1;
        }
        j = 2;
        while(i>=26 && i<39) {
            Rank r = static_cast<Rank>(j);
            Card h(Suit::hearts, r);
            if(h.isValid(Suit::hearts, r)){
                card.push_back(h);
            }
            j += 1;
            i += 1;
        }
        j = 2;
        while(i>=39 && i<52) {
            Rank r = static_cast<Rank>(j);
            Card s(Suit::spades, r);
            if(s.isValid(Suit::spades, r)){
                card.push_back(s);
            }
            j += 1;
            i += 1;
        }
        
    }
}

Card_deck::Card_deck() {
    for(int i = 0; i<52; ++i){
        int j{0};
        int k{0};
        Suit s = static_cast<Suit>('C'+j);
        Rank r = static_cast<Rank>(2+k);
        while(k<)
        k += 1;
    }
}*/

Card_deck::Card_deck() {
    current_card_index = 0;
    for (int j{2}; j < 15; j++) {
        card.emplace_back(Card(static_cast<Suit>('C'), static_cast<Rank>(j)));
    }
    for (int j{2}; j < 15; j++) {
        card.emplace_back(Card(static_cast<Suit>('D'), static_cast<Rank>(j)));
    }
    for (int j{2}; j < 15; j++) {
        card.emplace_back(Card(static_cast<Suit>('H'), static_cast<Rank>(j)));
    }
    for (int j{2}; j < 15; j++) {
        card.emplace_back(Card(static_cast<Suit>('S'), static_cast<Rank>(j)));
    }
}

void Card_deck::swap(int &card_a, int &card_b){
    int temp = card_a;
    card_a = card_b;
    card_b = temp;
}
/*
void Card_deck::print() {
    for(int i = 0; i<card.size(); ++i) {
        Suit s = card[i].suit();
        Rank r = card[i].rank();
        //std::cout << card[0].to_string_short(s, r) << endl;
        //cout << card[0].to_string(card[0].suit(), card[0].rank());
    }
}*/

void Card_deck::print() {
    for(Card c : card) {
        std::cout << c.to_string(c.suit(), c.rank()) << endl;
    }
}

void Card_deck::print_short() {
    for(Card c : card) {
        std::cout << c.to_string_short(c.suit(), c.rank()) << setw(5);
    }
    std::cout << "\n";
}

void Card_deck::shuffle() {
    for(int i = 0; i < 52; ++i) {
        auto temp = card[i];
        int random = (rand() % 52 + 0);
        card[i] = card[random];
        card[random] = temp;
    }
}

const Card& Card_deck::draw_card() {
    current_card_index += 1;
    return card[current_card_index-1];
}
