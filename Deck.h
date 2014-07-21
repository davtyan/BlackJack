//
//  deck.h
//  BlackJack
//
//  Created by Seda Davtyan on 7/20/14.
//  Copyright (c) 2014 Seda Davtyan. All rights reserved.
//

#ifndef BlackJack_deck_h
#define BlackJack_deck_h

#include <vector>
#include <string>
#include <iostream>

using namespace std;

//define a new type for a playing card
struct Playing_Card
{
    // 'S' for Spade, 'C' for Club, 'H' for Heart and 'D' for Diamond
    string suit; // {'S', 'C', 'H', 'D'};
    string rank; // card rank
    int value; // the value of the playing card
    void printFaceUp(){
        cout << suit <<rank ;
    }
    void printFaceDown(){
            cout << "X" ; // hidden card
    }
    
};

class Deck
{
public:
    // default constructor
    Deck(int = 1);
    void shuffle(); // shuflle the deck
    Playing_Card deal(); // deal the top card of the deck
    const int deckNum() const; // returns number of decks used
    bool isEmpty(); // checks whether deck is empty
private:
    int num_decks; // number of decks in the play - 1 by default
    vector<Playing_Card> deck;
    int deck_top; // refers to the current card in the deck, inititally 0
 };


#endif
