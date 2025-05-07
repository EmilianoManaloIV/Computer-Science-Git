#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"
#include "PlayingHand.h"
#include <list>
#include <string>
#include <sstream>
class Player
{
private:
    Deck playerDeck;                    //The players whole deck
    PlayingHand playerHand;             //The players want to play hand
    bool isPlayer;                      //Holds if this is AI or not
    list<int> selectFromDeck();        //Helper function that lets you choose elements of a deck
    list<int> selectFromHand(); //Helper function that lets you choose elements of a hand
public:
    Player();
    ~Player();
    //---Specialty Functions---
    void initiatePlayerTurn();
    Deck& getDeck();            // Gives access to the player's deck
    PlayingHand& getHand();     // Gives access to the player's hand
};
//Initiate a player with cards
Player::Player()
{
    //Place holder
}
Player::~Player()
{
    //Place holder
}
//Initiate a player's turn
void Player::initiatePlayerTurn()
{
    cout << "---YOUR TURN---" << endl;
    list<int> testInt = selectFromDeck();
}
//Initiate selection from a deck
list<int> Player::selectFromDeck()
{
    list<Card> temp = playerDeck.getCards();
    list<int> selection;
    string readLine;
    //Display selection options next to each object and index
    cout << "===SELECT CARDS===" << endl;
    int i = 0;
    for (const auto& card : temp)
    {
       cout << i << ". " << "[ ]";
       card.displayCard();
       i++;
       cout << endl;
    }
    cout << "Input the indexes you want to select separated by spaces: ";
    cin.clear(); // clear flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover input
    getline(cin, readLine);

    // Process input
    std::stringstream ss(readLine);
    int index;
    while (ss >> index)
    {
        selection.push_back(index);
    }

    // Confirm selection
    i = 0;
for (const auto& card : temp)
{
    // Check if the current index is in the selection list
    if (find(selection.begin(), selection.end(), i) != selection.end())
    {
        cout << i << ". [X] ";
    }
    else
    {
        cout << i << ". [ ] ";
    }

    card.displayCard();
    cout << endl;
    i++;
}
return selection;
}
Deck& Player::getDeck()
{
    return playerDeck;
}

PlayingHand& Player::getHand()
{
    return playerHand;
}
#endif