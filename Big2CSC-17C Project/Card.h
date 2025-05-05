#define CARD_H
#ifdef CARD_H
class Card
{
private:
    int* card;         //Determines type of card BASIC: 2-10,J,Q,K,A
    char* suit;        //Determines suit - BASIC:& (clubs), ^ (spades), V (hearts), O (diamonds)
public:
    //---GENERAL FUNCTIONS---
    Card(int, char);   //Instantiation constructor
    ~Card();           //Destructor
    //---SPECIAL FUNCTIONS---
    int getCard();
    char getSuit();
};
//Dynamic constructor
Card::Card(int CARD, char SUIT)
{
    card = new int(CARD);
    suit = new char(SUIT);
}
//Dynamic destructor
Card::~Card()
{
    delete card;
    delete suit;
}
//Get Functions
int Card::getCard()
{
    return *card;
}
char Card::getSuit()
{
    return *suit;
}
#endif 