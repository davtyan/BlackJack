//
//  main.cpp
//  BlackJack
//
//  Created by Seda Davtyan on 7/20/14.
//  Copyright (c) 2014 Seda Davtyan. All rights reserved.
//

#include <iostream>
#include "Game.h"

using namespace std;


int main(int argc, const char * argv[])
{
    Game* g = new Game();
    
    g -> startNewGame();
    
    return 0;
}

