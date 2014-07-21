//
//  Participant.cpp
//  BlackJack
//
//  Created by Seda Davtyan on 7/20/14.
//  Copyright (c) 2014 Seda Davtyan. All rights reserved.
//

#include "Participant.h"
#include "Common.h"

Participant::~Participant()
{
    freeHand();
}

//the argument passed to this function will contain the hand value if ace is counted as 11 instead of 1, and it will be 0 if the hand didn't contain any aces; the returned argument will always accout for ace as 1
int Participant::handValue(int& ace, bool& black_jack)
{
    //if participant has an Ace, then the value is either 1 or 11 - ace will be counted as 1 in the returned value and as 11 or 1 in the first argument of the function
    int hand_sum = 0;
    ace = 0;
    black_jack = false;
    
    for (int i=0; i < hand.size(); i++) {
        hand_sum += hand[i].value;
        //if the participant has an ace and the total value of the cards does not exceed BJ_VALUE==21 then calculate the value of ace as 11 and return it in the function argument
        if (hand[i].value != 1) {
            ace += hand[i].value;
        }
        else {
            if (ace + 11 <= BJ_VALUE) {
                ace += 11;
            }
            else ace += 1;
        }
    }
    // If Black Jack
    if ((hand.size() == 2) && (hand_sum == BJ_VALUE || ace == BJ_VALUE) )
        black_jack = true;
   
    return hand_sum;
}

bool Participant::examineState(int& h_val, bool face_up)
{
    int  a_val;
    bool bj;
    
    // calculate the hand value
    h_val = handValue(a_val, bj);
    
    // print the hand of the participant
    if (hand.size() == 2) {
        (face_up) ? hand[0].printFaceUp() : hand[0].printFaceDown();
        cout << " ";
        hand[1].printFaceUp();
        cout << " ***** \n";
        
        if (bj && face_up) {
            cout << "You have a Black Jack!!!\n";
            cout << "**************************\n";
            return true;
        }
    }
    else {
        for (int i=0; i<hand.size(); i++) {
            hand[i].printFaceUp();
            cout << " ";
        }
    }
    
    if (face_up) {
        // print the hand value
        if (a_val != h_val){
            cout << "Hand value can be counted as: " << h_val <<" or "<<a_val << ".\n";
            cout << "**************************\n";
        }
        else {
            cout << "Hand value is: " <<h_val<<".\n";
            cout << "**************************\n";
        }
    }
    
    return false;
}

void Participant::freeHand()
{
    // deallocate the memory that stores the hand - if not empty
    if (!hand.empty()) {
        hand.erase(hand.begin(),hand.end());
    }
    
}

void Participant::addToHand(Playing_Card new_card)
{
    hand.push_back(new_card);
}

int Participant::validHighHand()
{
    int h_val, a_val;
    bool bj;
    h_val = handValue(a_val, bj);
    
    if (h_val > BJ_VALUE)
        return 0; // burnt hand
    else if (a_val > BJ_VALUE)
        return h_val;
    
    return a_val > h_val ? a_val : h_val;
    
}

