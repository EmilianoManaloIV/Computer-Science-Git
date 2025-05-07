#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "PlayingHand.h"
using namespace std;
int main()
{
    Deck* TestDeck = new Deck;
    PlayingHand TestHand;

    TestDeck->displayDeck();
    TestHand.addToHand(TestDeck->takeRandomFromDeck());
    TestHand.addToHand(TestDeck->takeRandomFromDeck());
    TestHand.addToHand(TestDeck->takeRandomFromDeck());
    TestHand.addToHand(TestDeck->takeRandomFromDeck());
    TestHand.addToHand(TestDeck->takeRandomFromDeck());
    cout << endl;
    TestDeck->displayDeck();
    cout << endl << "MY HAND: " << endl;
    TestHand.displayHand();
    cout << endl << "Discard whole hand:" << endl;
    TestDeck->placeCardsIntoDeck(TestHand.discardHand());
    TestHand.displayHand();
    cout << endl << "Should be added back to primary deck" << endl;
    TestDeck->displayDeck();


   
    //TestHand.addToHand(Card(3,2));

   

    

    delete TestDeck;
    return 0;
}