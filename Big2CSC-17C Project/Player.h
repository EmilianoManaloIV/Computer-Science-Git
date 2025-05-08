#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"
#include "PlayingHand.h"
#include <string>
class Player
{
private:
string playerName;
bool isAi;
Deck playerDeck;
PlayingHand playerHand;

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

#endif