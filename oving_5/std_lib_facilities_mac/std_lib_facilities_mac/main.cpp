#include "std_lib_facilities.h"
#include "Card.hpp"
#include "Card_deck.hpp"
#include "player.hpp"
#include "Board.hpp"


int main(){
    srand(static_cast<unsigned int>(time(nullptr)));
    //Test of struct, success so moving on to classes
    /*Card_struct test;
    test.s = Suit::spades;
    test.r = Rank::ace;
    
    std::cout << toString(test) << endl;
    std::cout << to_string_short(test) << endl;
     */
    
    Card_deck deck_test;
    deck_test.print();
    deck_test.print_short();
    
    std::cout << setw(20) << "Velkommen til Blackjack" << endl;
    std::cout << "Begge spillerne får utdelt to kort til å starte med. Etter dette vil man få muligheten til å øke med et kort per runde, eller holde på det man har. Det er om å gjøre å være så nært 21 som mulig, 21 er det største kortet. Verdiene er fra 2-14 hvor A er det høyeste og 2 det laveste." << endl;
    
    //Creates the board and the players
    Board brett(true);
    Player dealer("Dealer", true);
    Player player1("Spiller", false);
    //Creates the deck and shuffles it
    Card_deck deck;
    deck.shuffle();
    deck.print_short();
    //Game order
    dealer.current_hand(deck.draw_card());
    player1.current_hand(deck.draw_card());
    dealer.current_hand(deck.draw_card());
    player1.current_hand(deck.draw_card());
    int sum_dealer = dealer.card_sum();
    int sum_player = player1.card_sum();
    brett.check_state(sum_dealer, sum_player);
    
    while(brett.check_state(sum_dealer, sum_player)) {
        
        dealer.show_cards();
        std::cout << "Dealer: " << sum_dealer << endl;
        player1.show_cards();
        std::cout << "Spiller: " << sum_player << endl;
        
        bool game_state = brett.check_state(sum_dealer, sum_player);
        char decision = 'D';
        brett.player_turn(decision, game_state);
        //brett.check_state();
        
        if(sum_dealer < 17){
            dealer.current_hand(deck.draw_card());
            sum_dealer = dealer.card_sum();
        }
        if(decision == 'D'){
            player1.current_hand(deck.draw_card());
            sum_player = player1.card_sum();
        }
        if(game_state == false){
            break;
        }
    }
    
    std::cout << "Dealer: " << sum_dealer << setw(10) << "Spiller: " << sum_player << endl;
    std::cout << "Spillet er over." << endl;
    
    //bool vant = brett.check_winner(sum_dealer, sum_player);
    if((sum_player > sum_dealer) && (sum_player < 22)) {
        std::cout << "Du vant." << endl;
    }
    else if (sum_dealer > 21){
        std::cout << "Du vant." << endl;
    }
    else {
        std::cout << "Du tapte." << endl;
    }
    
    return 0;
}
