//
//  player.hpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 15/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#pragma once
#ifndef player_hpp
#define player_hpp
#include "Card_deck.hpp"
#include "Card.hpp"
#include <stdio.h>
#include "Board.hpp"


//Player will be defined by name and whether they have priority or not (who wins at a draw/who gets top card)
class Player {
    string name;
    bool priority;
    vector<class Card> hand;
public:
    Player(string navn, bool prioritet) {
        name = navn;
        priority = prioritet;
    }
    void current_hand(Card new_card);
    void show_cards();
    int card_sum();
};

#endif /* player_hpp */
