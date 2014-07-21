//
//  game.cpp
//  BlackJack
//
//  Created by Seda Davtyan on 7/20/14.
//  Copyright (c) 2014 Seda Davtyan. All rights reserved.
//

#include "Game.h"
#include "Common.h"
#include<algorithm>

Game::Game(int d_size, int num_part, int m_bet) : min_bet(1), max_bet(m_bet)
{
    // initialize a new deck, by default 1 deck is used
    game_deck = new Deck(d_size);
    // by default there are 2 paricipants; multiple player option is not fully implemented
    participants_num = num_part;
    
    players = new Participant* [participants_num];
    players[0] = new Dealer();
    for (int i=1; i < participants_num; i++) {
        players[i] = new Player();
    }
}

Game::~Game()
{
    delete [] players;
}

void Game::initialDeal()
{
    Playing_Card tmp;
    
    // prepare the deck for the start of the game
    game_deck->shuffle();
    
    for (int i=0; i<2; i++) {
        // deal the card to the player
        tmp = game_deck -> deal();
        players[1]->addToHand(tmp);
       // tmp.printFaceUp();
        
        //deal the card to the dealer
        tmp = game_deck->deal();
        players[0]->addToHand(tmp);
    }
}

Playing_Card Game::hit()
{
    // deal a card - returns a playing card and moves the head
    return game_deck -> deal();
}

bool Game::anotherPlay()
{
    string s;
    bool coorect_choice = false;
    
    cout << "Do you want to play again? (yes or no): ";
    cin >> s;
    
    transform(s.begin(), s.end(), s.begin(), (int (*)(int))tolower); // cast the last argument to help the comp\iler in resolving to the correct overload                            
    
    while (!coorect_choice) {
        if (s == "yes" || s == "no")
            coorect_choice = true; //acceptable choice have been made
        else
        {
            cout <<s<<" is not a valid option, please enter 'yes' or 'no'!";
            cin >>s;
            transform(s.begin(), s.end(), s.begin(), (int (*)(int))tolower);
        }
    }
    // if yes then player wants to play
    return s == "yes" ? true : false;
}

void Game::announceWinner(bool pl_bj)
{
    bool bj_d, bj_p;
    int hand_val, bet = players[1] -> getBet();;
    int hand_ace_p, hand_ace_d, player_hand, dealer_hand;
    
    if (pl_bj){  //if player has a black jack
        cout <<"***** Dealer's Hand is: ";
        bj_d = players[0]->examineState(hand_val,pl_bj);
        if (bj_d) { //if dealer also has a black jack
            cout <<"PUSH !!! \n";
            // return the bet to the player
            players[1]->setChips(players[1]->getChips()+bet);
            cout <<"You have " << players[1] ->getChips()<<" chips! \n";
        }
        else{// player has a black jack, but dealer does not
            //BJ! set chips as chips+2.5*bet
            players[1]->setChips(players[1]->getChips()+bet*2.5);
            cout <<"The player won! You have " << players[1] ->getChips()<<" chips! \n";
        }
    }
    else{ //announce the winner if player does not have a black jack
        dealer_hand = players[0]->handValue(hand_ace_d, bj_d);
        player_hand = players[1]->handValue(hand_ace_p, bj_p);
        if (bj_d ) { //dealer has a black jack
            cout <<"The player lost! You have " << players[1] ->getChips()<<" chips remaining! \n";
        }
        else{ // neither participant has BJ
            //if both dealer and player burnt
            if (dealer_hand > BJ_VALUE && player_hand >BJ_VALUE) {
                cout << "PUSH !!! \n";
                //return the bet to the player
                players[1]->setChips(players[1]->getChips()+bet);
                cout <<"You have " << players[1]->getChips()<<" chips! \n";

            }
            //if dealer burnt
            else if (dealer_hand > BJ_VALUE) {
                //set chips as chips+2*bet
                players[1] -> setChips(players[1]->getChips()+bet*2);
                cout <<"The player won! You have " << players[1] ->getChips()<<" chips! \n";

            }
            else if (player_hand > BJ_VALUE)
            {
                cout <<"The player hand burnt! You have " << players[1]->getChips()<<" chips remaining! \n";
            }
            else if (players[0]->validHighHand() > players[1]->validHighHand())
                cout <<"The player lost! You have " << players[1]->getChips()<<" chips remaining! \n";
            else if (players[0]->validHighHand() < players[1]->validHighHand()){
                //set chips as chips+2*bet
                players[1] -> setChips(players[1]->getChips()+bet*2);
                cout <<"The player won! You have " << players[1]->getChips()<<" chips! \n";
            }
            else{
                cout << "PUSH !!!";
                //return the bet to the player
                players[1] -> setChips(players[1]->getChips()+bet);
                cout <<"You have " << players[1]->getChips()<<" chips! \n";
            }
        } // end of no BJ
    } // end of player does not have a BJ
}

void Game::startNewGame()
{
    Playing_Card tmp;
    int b, i;
    string s;
    bool bj_p, another_play = true;
    int hand_val;
    
    while (another_play) {
        // free the hands of the Dealer and the player
        players[0]->freeHand();
        for (i=1; i < participants_num; i++) {
            players[i]->freeHand();
        }
        // player needs to bet
        cout << "Player should bet at least " << min_bet << " and at most " << max_bet << " chips. You have " << players[1]->getChips() <<" chips! Please enter the number of chips you would like to bet: ";
        cin >> b;
        
        
        //ask for a new bet until a correct bet is entered
        for (i=1; i < participants_num; i++) {
            while(!players[i]->bet(b, min_bet, max_bet)){
                cout << "Please enter a bet between: " << min_bet <<" and " << max_bet <<" : ";
                cin >> b;
            }
        }
        
        // deal 2 cards to the Dealer and 2 cards to the player
        initialDeal();
        
        // examine the state of the player
        cout <<"***** Player's Hand is: ";
        bj_p = players[1]->examineState(hand_val);
        
        
        if (bj_p) { //player has a black jack
            //examine the state of the dealer; if player has a black jack open the cards
            announceWinner(bj_p);
        }
        
        //if player does not have a black jack
        else {
            //examine the state of the dealer
            cout <<"***** Dealer's Hand is: ";
            players[0]->examineState(hand_val, bj_p);
            
            for (i=participants_num-1; i >= 0; i--) {
                // if the player is the one playing
                if (i != 0) {
                    s = players[i]->nextMove();
                    while (s == "hit") {
                        players[i]->addToHand(hit()); // deal a card and add it to the hand
                        players[i]->examineState(hand_val);
                        if (hand_val <= BJ_VALUE)
                            s = players[i] -> nextMove();
                        else break;
                    }
                }
                if (i == 0) { //dealer is playing
                    cout << "***** Dealer's Hand is: ";
                    players[i]->examineState(hand_val);
                    s = players[i]->nextMove();
                    while (s == "hit") {
                        players[i]->addToHand(hit());
                        players[i]->examineState(hand_val);
                        s = players[i]->nextMove();
                    }
                }
            }
            announceWinner();
        }
        // no chips remaining
        if (players[1]->getChips() == 0)
            another_play = false;
        else
            // ask if player wants to continue to play
            another_play = anotherPlay();
    }
}
