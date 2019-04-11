//
//  player.cpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 15/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#include "player.hpp"
#include "Card.hpp"
#include "Card_deck.hpp"
#include "std_lib_facilities.h"
#include "Board.hpp"

void Player::current_hand(Card new_card){
    hand.emplace_back(new_card);
}

void Player::show_cards() {
    for(Card c : hand) {
        std::cout << c.to_string_short(c.suit(), c.rank()) << setw(5);
    }
    std::cout << "\n";
}

int Player::card_sum() {
    int sum = 0;
    for(int i = 0; i<hand.size(); ++i){
        sum += int(hand[i].rank());
    }
    return sum;
}
