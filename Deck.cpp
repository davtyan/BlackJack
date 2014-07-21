//
//  deck.cpp
//  BlackJack
//
//  Created by Seda Davtyan on 7/20/14.
//  Copyright (c) 2014 Seda Davtyan. All rights reserved.
//

#include "Deck.h"
#include <time.h>
#include <stdlib.h>

// generate a new deck of cards and shuffle it
Deck::Deck(int d_num) : num_decks(d_num)
{
    Playing_Card tmp;

    string suits[] = {"♠︎", "♣︎", "♥︎", "♦︎"};
    string ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10",  "J", "Q", "K"};
    int values[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    //generate the playing deck depending on the number of decks required; by default a deck of 52 cards is used
    for (int n=0; n< d_num; n++){
        for (int i = 0; i < 13; i++){
            tmp.rank = ranks[i];
            tmp.value = values[i];
            for (int j=0; j < 4; j++) {
                tmp.suit = suits[j];
                deck.push_back(tmp);
            }
        }
    }
    //initialize the deck_top as the first card in the deck
    deck_top = 0;
}

void Deck::shuffle()
{
    sranddev();
    
    // shuffle the cards - go through all the cards and place them in a random position in the deck
    int r;
    Playing_Card tmp;
    int deck_size = num_decks*52;
    
    for(int i=0; i < deck_size; i++){
        // select a random position for the i'th card of the deck
        r = rand()%deck_size;
        
        // exchange elements
        tmp = deck[i];
        deck[i] = deck[r];
        deck[r] = tmp;
        
    }
    // initialize the deck_top as the first card in the deck
    deck_top = 0;
}

bool Deck::isEmpty()
{
    // if the end of the deck is reached return true
    if (deck_top == deck.size()-1)
        return true;
    else return false;
}

Playing_Card Deck::deal()
{
    // deal the top card in the deck and change the pointer to the next element
    return deck[deck_top++];
}

//return the size of the deck
const int Deck::deckNum() const
{
    return num_decks;
}