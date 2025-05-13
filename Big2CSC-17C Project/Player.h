#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"
#include "PlayingHand.h"
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <set>
class Player
{
private:
map<int,string> handType =
{
    {0, "Skip"},
    {1,"High Card"},
    {2, "Pair"},
    {3, "Two Pair"},
    {4, "Three Of A Kind"},
    {5, "Straight"},
    {6, "Flush"}, 
    {7, "Full House"},
    {8, "Four Of A Kind"},
    {9, "Straight Flush"},
    {10,"Royal Flush"}
};
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
   cout << "===---[[Your Turn]]---===" << endl;
   char selection;
   do
   {
        playerHand.addToHand(playerDeck.selectCardsAndTakeFromDeck(handSelection()));
        playerHand.evaluateHand();
        cout << "===HAND BEING PLAYED===" << endl;
        cout << "HAND:" << handType[playerHand.getHandType()] << endl;
        cout << "RANK: " << cardRankRef[playerHand.getHighestCardRank()] << endl;
        cout << "SUIT: " << cardSuitesRef[playerHand.getHighestHandSuit()] << endl;
        cout << "Type o to confirm, type anything else to reselect: ";
        cin >> selection;
        if(selection != 'o')
        {
            playerDeck.placeCardsIntoDeck(playerHand.discardHand());
            playerDeck.sortDeck();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
   } while (selection != 'o');
   
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
     set<int> cleanedInput(selectedIndices.begin(), selectedIndices.end());
     list<int> output(cleanedInput.begin(), cleanedInput.end());
     return output;
}
#endif