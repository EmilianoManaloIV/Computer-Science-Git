#include <iostream>
#include "Card.h"
#include "Deck.h"
using namespace std;
int main()
{
    Deck* TestDeck = new Deck;
    TestDeck->displayDeck();
    cout << endl;
    TestDeck->shuffleDeck();
    TestDeck->displayDeck();
    cout << endl;
    TestDeck->sortDeck();
    TestDeck->displayDeck();
    cout << endl;
    TestDeck->takeTopFromDeck();
    TestDeck->takeBottomFromDeck();
    TestDeck->displayDeck();
    cout << endl;
    TestDeck->takeRandomFromDeck();
    TestDeck->takeRandomFromDeck();
    TestDeck->takeRandomFromDeck();
    TestDeck->displayDeck();
    cout << endl << "The amount of cards we now have is: " << TestDeck->amountOfCards();

    delete TestDeck;
    return 0;
}