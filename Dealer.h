//
//  Dealer.h
//  BlackJack
//
//  Created by Seda Davtyan on 7/20/14.
//  Copyright (c) 2014 Seda Davtyan. All rights reserved.
//

#ifndef BlackJack_Dealer_h
#define BlackJack_Dealer_h

#include "Participant.h"

class Dealer : public Participant
{
public:
    Dealer(int t_val = 17) : target_value(t_val){} //default target value for the dealer is 17, if other value is needed pass it to the constructor
    string nextMove(); // defines the logic for the dealer
private:
    const int target_value; //by default it is 17
};


#endif
