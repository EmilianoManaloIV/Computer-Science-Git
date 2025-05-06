#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "PlayingHand.h"
using namespace std;
int main()
{
    Deck* TestDeck = new Deck;
    PlayingHand TestHand;

    TestHand.addToHand(Card(9,1));
    TestHand.addToHand(Card(10,1));
    TestHand.addToHand(Card(6,1));
    TestHand.addToHand(Card(2,1));
    TestHand.addToHand(Card(9,1));
    //TestHand.addToHand(Card(3,2));

    TestHand.evaluateHand();

    cout << "What is the deck type?: " << TestHand.getHandType() << endl;
    cout << "What is the highest rank?: " << TestHand.getHighestCardRank() << endl;
    cout << "What is the highest suit?: " << TestHand.getHighestHandSuit() << endl;

    delete TestDeck;
    return 0;
}