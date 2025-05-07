
#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <map>
using namespace std;

class Card
{
private:
map<int, string> cardRankRef = { 
    {1, "3"},
    {2, "4"},
    {3, "5"},
    {4, "6"},
    {5, "7"},
    {6, "8"},
    {7, "9"},
    {8, "10"},
    {9, "J"},
    {10, "Q"},
    {11, "K"},
    {12, "A"},
    {13, "2"}}; //Map for card rank
    map<int, char> cardSuitesRef = 
    {{1, '&'},
    {2, '^'},
    {3, 'V'},
    {4, 'O'}};  //Map for suit rank

    int card;         //Determines type of card BASIC: 2-10,J,Q,K,A
    int suit;        //Determines suit - BASIC:& (clubs), ^ (spades), V (hearts), O (diamonds)
public:
    //---GENERAL FUNCTIONS---
    Card(int, int);   //Instantiation constructor
    ~Card();           //Destructor
    //---SPECIAL FUNCTIONS---
    int getCard() const;
    int getSuit() const;
    bool operator==(const Card&) const;
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
    cout << cardRankRef.at(card) << " of " << cardSuitesRef.at(suit);
}
//Helps with the equal operator
bool Card::operator==(const Card& other) const
{
    return card == other.card && suit == other.suit;
}
#endif 
