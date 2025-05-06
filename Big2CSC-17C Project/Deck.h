#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <iostream>
#include <deque>
#include <map>
#include <algorithm>
#include <random>
using namespace std;

class Deck
{
private:
    deque<Card> Cards;
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
    {13, "2"}};
    map<int, char> cardSuitesRef = 
    {{1, '&'},
    {2, '^'},
    {3, 'V'},
    {4, 'O'}};
    random_device rd;
    mt19937 g;
public:
    Deck();
    ~Deck();
    //---SPECIAL FUNCTIONS---
    void shuffleDeck();
    void sortDeck();
    void displayDeck();
    Card takeTopFromDeck();
    Card takeBottomFromDeck();
    Card takeRandomFromDeck();
    int amountOfCards();
};
//Creates a 52 deck without jokers at instantiation
Deck::Deck() 
{
    for(int i=1; i <= 4; i++)
    {
        for(int j=1; j <= 13; j++)
        {
            Cards.push_back(Card(j,i));
        }
    }
}
Deck::~Deck()
{
   //Objects delete automatically;
}
//Shuffles the deck using shuffle function
void Deck::shuffleDeck()
{
    shuffle(Cards.begin(), Cards.end(), g);
}
//Sorts the deck to be neat again
void Deck::sortDeck()
{
    sort(Cards.begin(), Cards.end(),
    [](const Card& a, const Card& b) {
        if (a.getSuit() != b.getSuit()) {
            return a.getSuit() < b.getSuit();  // Sort by suit first: 1=&, 2=^, etc.
        }
        return a.getCard() < b.getCard();      // Then by rank within suit: 1=3 ... 13=2
    });
}
//Uses maps to display the character & string oriented with numbered index
void Deck::displayDeck()
{
    for(const auto& card : Cards)
    {
        cout << cardRankRef[card.getCard()] << " of " << cardSuitesRef[card.getSuit()] << endl;
    }
}
//Takes a card from the top of the deck
Card Deck::takeTopFromDeck()
{
    Card C = Cards.front();
    Cards.pop_front();
    return C;
}
//Takes a card from the bottom of the deck
Card Deck::takeBottomFromDeck()
{
    Card C = Cards.back();
    Cards.pop_back();
    return C;
}
//Takes a card at random from any part of the deck
Card Deck::takeRandomFromDeck()
{
    uniform_int_distribution<size_t> dist(0, Cards.size() - 1);
    size_t randomIndex = dist(g);

    Card C = Cards.at(randomIndex);
    Cards.erase(Cards.begin() + randomIndex);  // Remove from deck

    return C;
}
//Returns the amount of cards this deck has
int Deck::amountOfCards()
{
    return Cards.size();
}
#endif 