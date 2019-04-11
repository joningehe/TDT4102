//
//  Board.cpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 15/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#include "std_lib_facilities.h"
#include "Board.hpp"
#include "Card.hpp"
#include "Card_deck.hpp"
#include "player.hpp"

bool Board::check_state(int &sum_dealer, int &sum_player){
    if(sum_dealer > 21 || sum_player > 21){
        return false;
    }
    else {
        return true;
    }
}

void Board::player_turn(char &decision, bool &game_state){
    std::cout << "Draw (D), Pass (P) or Quit (Q)" << endl;
    std::cin >> decision;
    switch (decision) {
        case 'D':
            break;
        case 'P':
            decision = 'P';
            break;
        case 'Q':
            game_state = false;
            break;
        default:
            std::cout << "Feil, skriv inn på nytt" << endl;
        }
}

bool Board::check_winner(int &sum_dealer, int &sum_player) {
    if((sum_player > sum_dealer) && (sum_player <= 21)){
        return true;
    }
    else{
        return false;
    }
}
