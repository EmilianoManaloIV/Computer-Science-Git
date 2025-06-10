#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
using namespace std;
struct customer
{
    int inLine;
};
float getItime(customer);
int main()
{
    queue<customer> line;
    vector<float> times;
    int amountOfTeller1 = 1;
    for(int i = 0; i < 1000; i++)
    {
        if(i % 240 == 0) 
        {
            customer temp;
            temp.inLine = i;
            line.push(temp);
        }
        if(i % 60 == 0)
        {
            for(int j = 0; j < amountOfTeller1; j++)
            {
                times.push_back(i - getItime(line.front()));
                line.pop();
            }
        }
        if(i % 120 == 0) 
        {
            times.push_back(i - getItime(line.front()));
            line.pop();
        }
        if(i % 105 == 0) 
        {
            times.push_back(i - getItime(line.front()));
            line.pop();
        }
        if(line.size() > 4) amountOfTeller1++;
        if(line.size() == 0) amountOfTeller1--;
    }
    float sum = accumulate(times.begin(),times.end(),0.0f);
    cout << "AVERAGE WAIT TIME (S): " << sum/times.size();
    return 0;
}
float getItime(customer c)
{
    return c.inLine;
}

