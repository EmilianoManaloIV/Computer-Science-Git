#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "PlayingHand.h"
#include "Player.h"
using namespace std;
int main()
{
    Deck* TestDeck = new Deck;
    PlayingHand TestHand;
     
    Player TestPlayer;
    TestPlayer.getDeck().placeCardIntoDeck(TestDeck->takeRandomFromDeck());
    TestPlayer.getDeck().placeCardIntoDeck(TestDeck->takeRandomFromDeck());
    TestPlayer.getDeck().placeCardIntoDeck(TestDeck->takeRandomFromDeck());
    TestPlayer.getDeck().placeCardIntoDeck(TestDeck->takeRandomFromDeck());
    TestPlayer.getDeck().placeCardIntoDeck(TestDeck->takeRandomFromDeck());
    TestPlayer.getDeck().placeCardIntoDeck(TestDeck->takeRandomFromDeck());
    TestPlayer.getDeck().placeCardIntoDeck(TestDeck->takeRandomFromDeck());
    TestPlayer.getDeck().placeCardIntoDeck(TestDeck->takeRandomFromDeck());
    TestPlayer.getDeck().placeCardIntoDeck(TestDeck->takeRandomFromDeck());
    TestPlayer.getDeck().placeCardIntoDeck(TestDeck->takeRandomFromDeck());
    TestPlayer.getDeck().placeCardIntoDeck(TestDeck->takeRandomFromDeck());
    TestPlayer.getDeck().placeCardIntoDeck(TestDeck->takeRandomFromDeck());
    TestPlayer.getDeck().placeCardIntoDeck(TestDeck->takeRandomFromDeck());
    
    TestPlayer.initiatePlayerTurn();
    
    delete TestDeck;
    return 0;
}