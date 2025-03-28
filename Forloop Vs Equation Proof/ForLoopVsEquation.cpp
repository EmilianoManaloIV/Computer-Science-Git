//Compare open and closed solution of summation
#include <iostream>                     //Include iostream for input output capabilities
using namespace std;                    //Use standard namespace for syntax

int ForLoopFunction(int, int, int);     //Function prototype for regular for loop summation
int EquationFunction(int, int, int);    //Function prototype for closed solution of summation
int CheckIfNegative(int);               //Function prototype to check for negative bounds

int main()
{
    //Variable declaration
    int constant;
    int upperBound;
    int lowerBound;

    //Ask user for input
    cout << "Please Input A Constant, Lower Bound, & Upper Bound||NOTE: Integers Only" << endl;
    cin >> constant;
    cin >> lowerBound;
    cin >> upperBound;

    //Check if bounds are negative
    lowerBound = CheckIfNegative(lowerBound);
    upperBound = CheckIfNegative(upperBound);

    //Output summations using both methods
    cout << "---------------------------------" << endl;
    cout << "The regular for-loop method is: " << ForLoopFunction(constant, upperBound, lowerBound) << endl;
    cout << "The closed form method is: " << EquationFunction(constant, upperBound, lowerBound) << endl;

    //Hit enter to escape program
    cout << "Hit Enter To Escape";
    cin.ignore();
    cin.get();
    return 0;           //Return that the program ran succesfully
}

//Function that represents the open solution of summation
int ForLoopFunction(int constant, int upperBound, int lowerBound)
{ 
    int summation = 0;
    for(int i = lowerBound; i <= upperBound; i++)
    {
        summation = summation + constant;
    }
    return summation;
}

//Function that represents the closed solution of summation
int EquationFunction(int constant, int upperBound, int lowerBound)
{
    int summation = 0;
    summation = constant*((upperBound - lowerBound) + 1);
    return summation;
}

//Function that checks if the index is negative then flips it
int CheckIfNegative(int numberToCheck)
{
    if(numberToCheck < 0)
    {
        cout << "Negative number detected, changing to a positive!" << endl;
        cout << "The number: " << numberToCheck << " is now: " << numberToCheck*-1 << endl;
        numberToCheck = numberToCheck*-1;
    }
    else
    {
        //Nothing happens
    }
    return numberToCheck;
}

