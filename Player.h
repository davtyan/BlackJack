//
//  player.h
//  BlackJack
//
//  Created by Seda Davtyan on 7/20/14.
//  Copyright (c) 2014 Seda Davtyan. All rights reserved.
//

#ifndef BlackJack_player_h
#define BlackJack_player_h

#include "Participant.h"

using namespace std;

class Player : public Participant
{
public:
    Player(int = 100);
    bool bet(int, int, int); // bet a certain number of chips - make sure it is not greater than what player has, and it is within the allowed limits
    double getChips(); // returns the number of remaining chips
    void setChips(double); // calculate the number of chips remaining and set the correct number
    int getBet(); // returns the current bet
    string nextMove(); // next move of the player
private:
    double chips; //initially 100
    int bet_chips; //holds the current bet
};

#endif
