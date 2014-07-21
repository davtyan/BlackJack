//
//  Dealer.cpp
//  BlackJack
//
//  Created by Seda Davtyan on 7/20/14.
//  Copyright (c) 2014 Seda Davtyan. All rights reserved.
//

#include "Dealer.h"
#include "Common.h"

string Dealer::nextMove()
{
    string s;
    int h_value, a_value;
    bool bj;
    
    h_value = handValue(a_value, bj);
    
    // if dealer has a black jack
    if (bj)
        return "black jack";
    // dealers hand burnt
    if (h_value > BJ_VALUE) {
        cout <<"Dealer's hand burnt!";
        return "burnt";
    }
    if (a_value < target_value) { // dealer's hand is smaller than 17
        cout <<"The dealer is taking another card.\n";
        return "hit";
    }
    // dealer's hand is less than target_value=17
    if (h_value < target_value && a_value > BJ_VALUE) {
        cout <<"The dealer is taking another card.\n";
        return "hit";
    }
    // h_value >= target_value(17)
    cout <<"The dealer is done taking cards.\n";
    return "stand";
}

