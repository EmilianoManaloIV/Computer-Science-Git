#include <iostream>
#include "Card.h"
using namespace std;
int main()
{
    Card* TestCard = new Card(12, '&');
    cout << TestCard->getCard() << endl;
    cout << TestCard->getSuit() << endl;
    delete TestCard;
    return 0;
}