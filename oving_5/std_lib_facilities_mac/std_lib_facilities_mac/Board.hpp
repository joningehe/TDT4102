//
//  Board.hpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 15/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#pragma once
#ifndef Board_hpp
#define Board_hpp
#include "player.hpp"
#include "Card.hpp"
#include "Card_deck.hpp"
#include "std_lib_facilities.h"
#include <stdio.h>

class Board {
    bool game_state;
public:
    Board(bool state) {
        game_state = state;
    }
    void player_turn(char &decision, bool &game_state);
    bool check_state(int &sum_dealer, int &sum_player);
    bool check_winner(int &sum_dealer, int &sum_player);
};

//Fikk ikke nok tid så endte opp med å skrive det i main fila
/*struct Rules {
    
}*/
#endif /* Board_hpp */
