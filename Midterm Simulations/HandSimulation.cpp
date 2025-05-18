#include <iostream>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    deque<int> Cards;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            Cards.push_back(j);
        }
    }
    
    for(int value : Cards) cout << value << endl;
    
    return 0;
}