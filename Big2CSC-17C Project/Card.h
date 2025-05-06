
#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;

class Card
{
private:
    int card;         //Determines type of card BASIC: 2-10,J,Q,K,A
    int suit;        //Determines suit - BASIC:& (clubs), ^ (spades), V (hearts), O (diamonds)
public:
    //---GENERAL FUNCTIONS---
    Card(int, int);   //Instantiation constructor
    ~Card();           //Destructor
    //---SPECIAL FUNCTIONS---
    int getCard() const;
    int getSuit() const;
    //---DEBUG FUNCTIONS---
    void displayCard() const;
};
//Dynamic constructor
Card::Card(int CARD, int SUIT)
{
    card = CARD;
    suit = SUIT;
}
//Dynamic destructor
Card::~Card()
{
   
}
//Get Functions
int Card::getCard() const
{
    return card;
}
int Card::getSuit() const
{
    return suit;
}
//Displays the current card info
void Card::displayCard() const
{
    cout << card << " of " << suit << endl;
}
#endif 
