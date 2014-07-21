//
//  game.h
//  BlackJack
//
//  Created by Seda Davtyan on 7/20/14.
//  Copyright (c) 2014 Seda Davtyan. All rights reserved.
//

// multiple player option is not fully implemented; be default one player is playing

#ifndef BlackJack_game_h
#define BlackJack_game_h

#include "Player.h"
#include "Dealer.h"

using namespace std;

class Game{
public:
    Game(int = 1, int = 2, int = 10); // specify the deck size (default is 1); specify the number of participants (by default 1 dealer and 1 player); the third argument is the maximum number of chips allowed to bet default is 10
    ~Game();
    void initialDeal(); //deal two cards to the player and to the Dealer
    void dealerMove();
    void startNewGame();
    void announceWinner(bool = false);
    void quitGame();
    void printPlayerState();
    void printRules(); //prints the rules of the game
    Playing_Card hit(); 
    void split(); // this method is optional
    bool anotherPlay();
private:
    Participant** players;
    int participants_num;
    Deck* game_deck;
    const int min_bet; //need to beet at least one chip
    const int max_bet; // maximum allowed bet is 10 times the minimum
    enum game_outcome {won, lost, push, black_jack};
};

#endif
