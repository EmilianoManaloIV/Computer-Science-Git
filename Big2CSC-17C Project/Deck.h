#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <list>
#include <iostream>
#include <deque>
#include <map>
#include <algorithm>
#include <random>
#include <vector>
using namespace std;

class Deck
{
private:
    deque<Card> Cards;              //Used to store all the card objects
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
    random_device rd;   //Random number generator using STL
    mt19937 g;
public:
    Deck();                         //Automatically creates a basic 52 hand without jokers
    Deck(int);                      //Creates a deck with 0 cards in it
    Deck(Card);                     //Creates a deck with one card in it
    Deck(list<Card>);               //Creates a deck out of a given amount of cards
    ~Deck();                        //Destroys the deck
    //---SPECIAL FUNCTIONS---
    void shuffleDeck();
    void sortDeck();
    void displayDeck();

    Card takeTopFromDeck();
    Card takeBottomFromDeck();
    Card takeRandomFromDeck();
    Card takeCardFromDeck(int);
    list<Card> selectCardsAndTakeFromDeck(list<int>);
    list<Card> getCards() const;
    int amountOfCards();
    void placeCardIntoDeck(Card);
    void placeCardsIntoDeck(list<Card>);
};
//Creates a 52 deck without jokers at instantiation
Deck::Deck() 
{
    Cards.clear();
}
Deck::Deck(int i)
{
    if(i == 52)
    for(int i=1; i <= 4; i++)
    {
        for(int j=1; j <= 13; j++)
        {
            Cards.push_back(Card(j,i));
        }
    }
}     
//Instantiates the deck with a single card specicifed
Deck::Deck(Card C)
{
    Cards.push_back(C);
}
//Instantiates the deck with another set of cards
Deck::Deck(list<Card> Cs)
{
    Cards = deque<Card>(Cs.begin(), Cs.end());
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
//Sort the deck to be neat again
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
//Takes a certain card out of a specified index in the deck
Card Deck::takeCardFromDeck(int I)
{
    Card C = Cards.at(I);
    Cards.erase(Cards.begin() + I);

    return C;
}
//Returns the amount of cards this deck has
int Deck::amountOfCards()
{
    return Cards.size();
}
//Places a card into the deck
void Deck::placeCardIntoDeck(Card C)
{
    Cards.push_back(C);
}
//Places a list of cards into the deck
void Deck::placeCardsIntoDeck(list<Card> Cs)
{
    Cards.insert(Cards.end(),Cs.begin(),Cs.end());
}
//Selects cards then take them out of the deck
list<Card> Deck::selectCardsAndTakeFromDeck(list<int> selection)
{
    std::list<Card> temp;

    // Convert selection of indices to actual Card objects
    auto it = Cards.begin();
    for (const auto& i : selection)
    {
        std::advance(it, i);  // Move iterator to the desired index
        temp.push_back(*it);  // Add the selected card to temp
        it = Cards.begin();  // Reset iterator to beginning for next selection
    }

    // Now remove selected cards from the original deck
    for (const auto& card : temp)
    {
        auto removeIt = std::find(Cards.begin(), Cards.end(), card);
        if (removeIt != Cards.end()) {
            Cards.erase(removeIt);  // Remove the card from the deck
        }
    }

    return temp;  // Return the list of selected cards
}
list<Card> Deck::getCards() const
{
    return list<Card>(Cards.begin(), Cards.end());
}
#endif 