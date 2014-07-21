//
//  player.cpp
//  BlackJack
//
//  Created by Seda Davtyan on 7/20/14.
//  Copyright (c) 2014 Seda Davtyan. All rights reserved.
//

#include "Player.h"
#include <algorithm>

Player::Player(int c)
{
    chips = c;
}


double Player::getChips()
{
    return chips;
}

//bet min 1 and max 10 chips
bool Player::bet(int n_chips, int min_b, int max_b)
{
    //if the bet is greater than the number of chips owned by the player
    if (n_chips > chips) {
        cout << "You do not have enouch chips!\n";
        return false;
    }
    //not a correct bet
    else if (n_chips < min_b || n_chips > max_b){
        cout << "You are allowed to bet minimum " << min_b <<  " and maximum " << max_b << " chips!\n";
        return false;
    }
    //correct bet
    else
    {
        bet_chips = n_chips;
        chips -= bet_chips; //take out the betted number of chips
        return true;
    }
}

void Player::setChips(double reward)
{
    //notise that reward can be negative if the game is lost
    chips = reward;
}

int Player::getBet()
{
    return bet_chips;
}

string Player::nextMove()
{
    string s;
    bool coorect_choice = false;
    
    cout << "Hit or Stand?" <<endl;
    cin >> s;
    
    transform(s.begin(), s.end(), s.begin(), (int (*)(int))tolower); // cast the last argument to help the compiler in resolving to the correct overload
    
    while (!coorect_choice) {
        if (s == "hit" || s == "stand")
            coorect_choice = true; //acceptable choice have been made
        else
        {
            cout <<s<<" is not a valid option, please enter 'hit' or 'stand'!";
            cin >>s;
            transform(s.begin(), s.end(), s.begin(), ::tolower);
        }
    }
    
    return s;
}


