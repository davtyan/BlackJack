//
//  Participant.h
//  BlackJack
//
//  Created by Seda Davtyan on 7/20/14.
//  Copyright (c) 2014 Seda Davtyan. All rights reserved.
//

#ifndef BlackJack_Participant_h
#define BlackJack_Participant_h

#include "Deck.h"

class Participant
{
public:
    ~Participant();
    int handValue(int&, bool&); //returns the hand value of the participant - the ace is counted for as 1, the function argument is going to be 0, if there are no aces, or ace will be counted as 11 if the hand value does not exceed 21
    void freeHand(); //discard the cards
    void addToHand(Playing_Card); //add the dealt card to the hand
    bool examineState(int&, bool = true ); //print the state of the participant;  true is passed if the hand needs to be open, otherwise one card will be face down; returns true if it has a black jack, otherwise false
    int validHighHand(); //returns highest hand considering aces that is <= BJ_VALUE==21; returns 0 if both burnt
    virtual bool bet(int = 0, int = 0, int = 0){return false;}
    virtual string nextMove() =0;
    virtual void setChips(double) {}
    virtual int getBet() {return 0;}
    virtual double getChips() {return 0;}
protected:
    vector<Playing_Card> hand;
};

#endif
