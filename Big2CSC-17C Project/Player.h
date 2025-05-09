#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"
#include "PlayingHand.h"
#include <string>
#include <sstream>
#include <iostream>
class Player
{
private:
string playerName;
bool isAi;
Deck playerDeck;
PlayingHand playerHand;

list<int> handSelection();

public:
void addToPlayerHand(list<Card>);
void addToPlayerHand(Card);
//---Instantiation Routines---
Player();
Player(bool);
~Player();
//---Operator Overloads---
bool operator==(const Player&) const;
bool operator!=(const Player&) const;
bool operator<(const Player&) const;
bool operator>(const Player&) const;
bool operator<=(const Player&) const;
bool operator>=(const Player&) const;

//---Turn Routines---
void playerTurn();
void aiTurn();
};
Player::Player()
{
    //Make sure this is a player
    isAi = false;
}
Player::Player(bool b)
{
    if(b == true)
    {
        isAi = true;
    }
}
Player::~Player()
{
    //Does nothing because the STL automatically deletes itself
}
void Player::addToPlayerHand(list<Card> Cs)
{
    playerDeck.placeCardsIntoDeck(Cs);
}
void Player::addToPlayerHand(Card C)
{
    playerDeck.placeCardIntoDeck(C);
}
bool Player::operator==(const Player& other) const {
    return playerHand == other.playerHand;
}

bool Player::operator!=(const Player& other) const {
    return !(*this == other);
}

bool Player::operator<(const Player& other) const {
    return playerHand < other.playerHand;
}

bool Player::operator>(const Player& other) const {
    return playerHand > other.playerHand;
}

bool Player::operator<=(const Player& other) const {
    return !(*this > other);
}

bool Player::operator>=(const Player& other) const {
    return !(*this < other);
}
void Player::playerTurn()
{
    cout << "[[-----YOUR TURN-----]]" << endl;
    handSelection();
}
list<int> Player::handSelection()
{
     // First display all cards
     cout << "---YOUR CARDS---" << endl;
     int i = 0;
     for (const auto& card : playerDeck.getCards())
     {
         cout << i << ". [ ] ";
         card.displayCard();
         cout << endl;
         ++i;
     }
 
     // Ask for input
     cout << "Select Cards By Typing Their Index: ";
 
     string inputLine;
     getline(cin, inputLine);
 
     istringstream iss(inputLine);
     list<int> selectedIndices;
     int index;
     while (iss >> index) {
         selectedIndices.push_back(index); // Store selected indices
     }
 
     // Display selected cards again with [X] indicator
     cout << "---SELECTED CARDS---" << endl;
     i = 0;
     for (const auto& card : playerDeck.getCards())
     {
         // Check if current index is selected
         bool selected = (find(selectedIndices.begin(), selectedIndices.end(), i) != selectedIndices.end());
         cout << i << ". [" << (selected ? "X" : " ") << "] ";
         card.displayCard();
         cout << endl;
         ++i;
     }
 
     return selectedIndices;
}
#endif