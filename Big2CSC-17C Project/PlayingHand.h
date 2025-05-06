#ifndef PLAYINGHAND_H
#define PLAYINGHAND_H
#include "Card.h"
#include <list>
#include <unordered_map>
#include <algorithm>
using namespace std;
class PlayingHand
{
private:
list<Card> Cards;                       //Stores the actual cards that are played
list<int> Sequence;                     //Stores the rank sequence of the cardss 
unordered_map<int,int> CardRankAmount;  //Indicates how much a rank shoes up in a given hand
unordered_map<int,int> CardSuitAmount;  //Indicates how much a suit shoes up in a given hand

int handType;           //Indicates the hand type singles, royal flush      (10-0)
int highestCardRank;    //Indicates the highest card rank (when applicable) (1-13)
int highestHandSuit;    //Indicates the highest hand suit (when applicable) (1-4)

//---HELPER FUNCTIONS---
bool isHighCard();      //Determines if the hand is a high card
bool isPair();          //Detemines if the hand is a pair
bool isTwoPair();       //Detemines if the hand is a two pair
bool isThreeOfAKind();  //Detemines if the hand is three of a kind
bool isStraight();      //Determines if the hand is a straight
bool isFlush();         //Detemines if the hand is a flush
bool isFullHouse();     //Determines if the hand is a fullhouse
bool isFourOfAKind();   //Determines if the hand is a four of kind
bool isStraightFlush(); //Determines if the hand if a straight flush
bool isRoyalFlush();    //Determines if the hand is a royal flush

int evaluateHandType();            //Evaluates the hand type
int evalHighestCardRank();         //Evaluates the highest card rank in the hand
int evalHighestCardSuit();         //Evaluates the highest card suit

public:
PlayingHand();          //Instantiates the playinghand object
~PlayingHand();         //Destroys the intance of the playing hand object
int getHandType();
int getHighestCardRank();
int getHighestHandSuit();
//---SPECIAL FUNCTIONS---
void addToHand(Card);       //Adds a card to the hand that is playing
Card removeFromPlay(int);   //Returns the card to another object of the selected index 
void evaluateData();
void evaluateHand();
};
//Default constructor as a placeholder
PlayingHand::PlayingHand()
{

}
//Default destructor as a placeholder
PlayingHand::~PlayingHand()
{

}
//Adds a card to the hand
void PlayingHand::addToHand(Card C)
{
    Cards.push_back(C);
}
//Removes a certain card out of the hand
Card PlayingHand::removeFromPlay(int I)
{
    if(I >= 0 && I < Cards.size())
    {
        list<Card>::iterator it = Cards.begin();
        advance(it, I);
        return *it;
    }
}
//Checks if this is a high card
bool PlayingHand::isHighCard()
{
    bool isHighCard;
    if(Cards.size() == 1)
    {
        isHighCard = true;
    }
    return isHighCard;
}
//Checks if this is a pair
bool PlayingHand::isPair()
{
    bool isPair = false;
    for(const auto& Check : CardRankAmount)
    {
        if(Check.second == 2)
        {
            isPair = true;
        }
    }
    return isPair;
}
//Checks if this is a two pair
bool PlayingHand::isTwoPair()
{
    int amountOfPairs = 0;
    bool isTwoPair = false;
    for(const auto& Check : CardRankAmount)
    {
        if(Check.second == 2)
        {
            amountOfPairs++;
        }
    }
    if(amountOfPairs == 2)
    {
        isTwoPair = true;
    }
    return isTwoPair;
}
//Checks if the hand is a three of a kind
bool PlayingHand::isThreeOfAKind()
{
    bool isThreeOfAKind = false;
    for(const auto& Check : CardRankAmount)
    {
        if(Check.second == 3)
        {
            isThreeOfAKind = true;
        }
    }
    return isThreeOfAKind;
}
//Checks if the hand is a straight
bool PlayingHand::isStraight()
{
    list<int> temp = Sequence;
    bool isStraight = true;
    temp.sort();
    temp.unique();
    //Checks if this is indeed a five carder straight
    if(temp.size() < 5) isStraight = false;
    //Now check if this is a valid sequence
    auto it = temp.begin();
    auto next = std::next(it);
    while(next != temp.end())
    {
        if(*next != *it + 1) isStraight = false;
        ++it;
        ++next;
    }
    return isStraight;
}
//Checks if this hand is a flush
bool PlayingHand::isFlush()
{
    bool isFlush = false;
    for(const auto& Check : CardSuitAmount)
    {
        if(Check.second == 5)
        {
            isFlush = true;
        }
    }
    return isFlush;
}
//Checks if this hand is a full house
bool PlayingHand::isFullHouse()
{
    bool isFullHouse = false;
    if(isThreeOfAKind() == true && isPair() == true)
    {
        isFullHouse = true;
    }
    return isFullHouse;
}
//Check if this hand is a four of a kind
bool PlayingHand::isFourOfAKind()
{
    bool isFourOfAKind = false;
    for(const auto& Check : CardRankAmount)
    {
        if(Check.second == 4)
        {
            isFourOfAKind = true;
        }
    }
    return isFourOfAKind;
}
//Checks if the hand is a straight flush
bool PlayingHand::isStraightFlush()
{
    bool isStraightFlush = false;
    if(isStraight() == true && isFlush() == true)
    {
        isStraightFlush = true;
    }
    return isStraightFlush;
}
//Checks if the hand is a royal flush
bool PlayingHand::isRoyalFlush()
{
    bool isRoyal = false;
    bool isRoyalFlush = false;
    for(const auto& Check : CardRankAmount)
    {
        if(Check.first > 8 && Check.second == 1)
        {
            isRoyal = true;
        }
    }
    if(isRoyal == true && isStraightFlush())
    {
        isRoyalFlush = true;
    }
    return isRoyalFlush;
}
//Takes the cards data and extracts key data for evaluation
void PlayingHand::evaluateData()
{
    for(const auto& Card : Cards)
    {
        Sequence.push_back(Card.getCard());
        CardRankAmount[Card.getCard()]++;
        CardSuitAmount[Card.getSuit()]++;
    }
}
//Evaluates the hand to return the type of hand is played, hand rank, and hand suit rank
int PlayingHand::evaluateHandType()
{
    //Check hand type
    int hand;
    if(isRoyalFlush())
    {
        hand = 10;
    }
    else if (isStraightFlush())
    {
        hand = 9;
    }
    else if (isFourOfAKind())
    {
        hand = 8;
    }
    else if (isFullHouse())
    {
        hand = 7;
    }
    else if (isFlush())
    {
        hand = 6;
    }
    else if (isStraight())
    {
        hand = 5;
    }
    else if (isThreeOfAKind())
    {
        hand = 4;
    }
    else if (isTwoPair())
    {
        hand = 3;
    }
    else if (isPair())
    {
        hand = 2;
    }
    else if (isHighCard())
    {
        hand = 1;
    }
    else 
    {
        hand = 0;
    }
    return hand;
}
//Gets certain values used for comparisons and debugging
int PlayingHand::getHandType()
{
    return handType;
}
int PlayingHand::getHighestCardRank()
{
    return highestCardRank;
}
int PlayingHand::getHighestHandSuit()
{
    return highestHandSuit;
}
//Evaluates highest card rank
int PlayingHand::evalHighestCardRank()
{
    switch (handType)
    {
        case 1: // High card
            return *max_element(Sequence.begin(), Sequence.end());

        case 2: // Pair
        case 3: // Two Pair
        case 4: // Three of a Kind
        case 7: // Full House
        case 8: // Four of a Kind:
        {
            int maxRank = -1;
            for (const auto& pair : CardRankAmount)
            {
                if (pair.second > 1 && pair.first > maxRank)
                    maxRank = pair.first;
            }
            return maxRank;
        }

        case 5: // Straight
        case 9: // Straight Flush
        case 10: // Royal Flush
            return *max_element(Sequence.begin(), Sequence.end());

        case 6: // Flush
        {
            int dominantSuit = evalHighestCardSuit();
            int maxFlushRank = -1;
            for (const auto& card : Cards)
            {
                if (card.getSuit() == dominantSuit && card.getCard() > maxFlushRank)
                    maxFlushRank = card.getCard();
            }
            return maxFlushRank;
        }

        default:
            return -1;
    }
}
//Evaluates highest suit rank
int PlayingHand::evalHighestCardSuit()
{
    if (CardSuitAmount.empty()) return -1;

    auto maxIt = max_element(CardSuitAmount.begin(), CardSuitAmount.end(),
        [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second)
                return a.second < b.second; // compare by count
            return a.first < b.first; // tie-break by higher suit value
        });

    return maxIt->first; // returns the suit (key) with the highest count (value)
}
void PlayingHand::evaluateHand()
{
    evaluateData();
    handType = evaluateHandType();
    highestCardRank = evalHighestCardRank();
    highestHandSuit = evalHighestCardSuit();
}
#endif