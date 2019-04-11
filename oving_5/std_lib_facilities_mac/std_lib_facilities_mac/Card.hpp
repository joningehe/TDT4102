//
//  Card.hpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 13/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#pragma once
#ifndef Card_hpp
#define Card_hpp
#include "Card_deck.hpp"
#include <stdio.h>
#include "std_lib_facilities.h"


//enum class containing the different suits in our card deck together with their char value
enum class Suit {
  clubs='C', diamonds='D', hearts='H', spades='S'
};

//enum class containing the different ranks in our card deck together with their char value
//don't know how to handle ace, give switch between 1 and 14?
enum class Rank {
    two=2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace
};

//Struct no longer needed, validated through testing, moving onto classes
/*
struct Card_struct {
    Suit s;
    Rank r;
};
*/

//string functions found in Card.cpp, these return the value of our objects as proper output strings
string suit_to_string(Suit &s);
string rank_to_string(Rank &r);
    //string suit_to_string_switch(Suit& kort);
//string toString(const Card_struct &card);
//string to_string_short(const Card_struct &card);

//The class card declares the two class objects s and r as variables from the enum classes Suit and Rank
//bool valid should check whether the input from user isalpha and in the enumerators
class Card {
    Suit s;
    Rank r;
    bool valid;
public:
    Card(); //invalid
    Card(Suit, Rank);
    Suit suit();
        //Suit pubs = suit();
    Rank rank();
        //Rank pubr = rank();
    bool isValid(Suit s,Rank r);
    string to_string(const Suit s, const Rank r);
    string to_string_short(const Suit s, const Rank r);
};

//string to_string(const Card &current_card);
//string to_string_short(const Card &current_card);

#endif /* Card_hpp */
