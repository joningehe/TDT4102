//
//  Card_deck.hpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 14/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#pragma once
#ifndef Card_deck_hpp
#define Card_deck_hpp
#include <stdio.h>
#include "Card.hpp"
#include "std_lib_facilities.h"

class Card_deck {
    vector<class Card> card;
    int current_card_index;
    void swap(int &card_a, int &card_b);
public:
    Card_deck();
    void print();
    void print_short();
    void shuffle();
    const Card& draw_card();
};



#endif /* Card_deck_hpp */
