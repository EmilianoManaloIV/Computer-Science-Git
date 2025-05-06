
#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;

class Card
{
private:
    int card;         //Determines type of card BASIC: 2-10,J,Q,K,A
    char suit;        //Determines suit - BASIC:& (clubs), ^ (spades), V (hearts), O (diamonds)
public:
    //---GENERAL FUNCTIONS---
    Card(int, char);   //Instantiation constructor
    ~Card();           //Destructor
    //---SPECIAL FUNCTIONS---
    int getCard() const;
    char getSuit() const;
    //---DEBUG FUNCTIONS---
    void displayCard() const;
};
//Dynamic constructor
Card::Card(int CARD, char SUIT)
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
char Card::getSuit() const
{
    return suit;
}
void Card::displayCard() const
{
    cout << card << " of " << suit << endl;
}
#endif 
