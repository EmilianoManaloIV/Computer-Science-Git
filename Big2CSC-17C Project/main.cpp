#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "PlayingHand.h"
#include "Player.h"
using namespace std;
int main()
{
    Deck* TestDeck = new Deck(52);
    PlayingHand TestHand;
    Player* TestPlayer = new Player;

    TestPlayer->addToPlayerHand(TestDeck->getCards());
    TestPlayer->playerTurn();
     
    delete TestDeck;
    return 0;
}