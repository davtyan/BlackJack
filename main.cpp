//
//  main.cpp
//  BlackJack
//
//  Created by Seda Davtyan on 7/20/14.
//  Copyright (c) 2014 Seda Davtyan. All rights reserved.
//

#include <iostream>
#include "Game.h"
#include <stdlib.h>

using namespace std;


int main(int argc, const char * argv[])
{
    int m_bet = 10; // maximum allowed bet, default is 10
    
    if (argc > 1)
        m_bet = atoi(argv[1]) <= 100 ? atoi(argv[1]) : 10;
    
    // use 1 deck, 2 participants and maximum bet is m_bet
    Game* g = new Game(1, 2, m_bet);
    
    g -> startNewGame();
    
    return 0;
}


