//
//  Card.cpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 13/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#include "std_lib_facilities.h"
#include "Card.hpp"
#include "Card_deck.hpp"

//Based on my understanding of enums and map<>, this should be the proper way to structure both functions
//Returns a string suit type based on individual card
const std::map<Suit, string> suit_string = {
    {Suit::clubs, "Clubs"},
    {Suit::diamonds, "Diamonds"},
    {Suit::hearts, "Hearts"},
    {Suit::spades, "Spades"}
};

//Can't use pass by reference here... why?!
//Possibly because the return value changes the value in the local scope of the function which calls it.
string suit_to_string(Suit s) {
        return suit_string.at(s);
}

//Returns a string rank type based on individual card
const std::map<Rank, string> rank_string = {
    {Rank::two, "Two"},
    {Rank::three, "Three"},
    {Rank::four, "Four"},
    {Rank::five, "Five"},
    {Rank::six, "Six"},
    {Rank::seven, "Seven"},
    {Rank::eight, "Eight"},
    {Rank::nine, "Nine"},
    {Rank::ten, "Ten"},
    {Rank::jack, "Jack"},
    {Rank::queen, "Queen"},
    {Rank::king, "King"},
    {Rank::ace, "Ace"}
};

string rank_to_string(Rank r) {
    return rank_string.at(r);
}

//Samme som suit_to_string, men med en switch versjon jeg tror vil funke
/*string suit_to_string_switch(Suit& card) {
    switch (card) {
        case Suit::clubs:
            return "Clubs";
        case Suit::diamonds:
            return "Diamonds";
        case Suit::hearts:
            return "Hearts:";
        case Suit::spades:
            return "Spades";
        default:
            return "Error";
            break;
    }
    return 0;
}*/

//No longer needed as class is worked at
/*string toString(const Card_struct &card) {
    return (rank_to_string(card.r) + " of " + (suit_to_string(card.s)));
}

string to_string_short(const Card_struct &card) {
    return (std::to_string(int(card.r)) + char(card.s));
}*/


Card::Card(Suit suit, Rank rank)
{
    s = suit;
    r = rank;
}

Suit Card::suit()
{
    return s;
}

Rank Card::rank()
{
    return r;
}

bool Card::isValid(Suit s, Rank r)
{
    if(s==Suit::clubs || s==Suit::diamonds || s==Suit::hearts || s==Suit::spades) {
        if(r>=Rank::two && r<=Rank::ace){
            return true;
        }
    }
    else{
        return false;
    }
    return 0;
}

//Så det jeg har gjort feil her er å opprette nye variabler som blir public i classen, dette er feil
//Disse variablene skla opprettes inni stringen her og funksjonene skal benyttes fra card, da trenger jeg strengt talt ikke sende noen variabler til stringen her da den bare kan aksessere den publice funksjonen som får tilgang til r/s fra den private
string Card::to_string(const Suit s, const Rank r) {
    return(rank_to_string(r) + " of " + (suit_to_string(s))); //må få disse som ny variabel?
}

string Card::to_string_short(const Suit s, const Rank r) {
    return(std::to_string(int(r)) + char(s));
}
