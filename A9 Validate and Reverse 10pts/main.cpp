/* 
 * File:   main.cpp
 * Author: Emiliano Manalo
 * Created on Septermber 9, 2023 3:00 PM
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
#include <climits>
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(const char [],unsigned short &);//Output true,unsigned or false
bool  reverse(unsigned short,signed short &);//Output true,short or false
short subtrct(signed short,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short
    
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Now subtract if the result is not negative else don't subtract
    snShort=subtrct(snShort,999);
    
    //Output the result
    cout<<snShort<<endl;
    
    //Exit
    return 0;
}
bool inRange(const char input[], unsigned short &result) 
{
    int checkValue = 0;
    for (size_t i = 0; i < strlen(input); ++i) 
    
    {
        if (!isdigit(input[i])) {
            return false;
        }
    }
    checkValue = atoi(input);
    if(checkValue > USHRT_MAX)
    {
        return false;
    }
    else
    {
    result = atoi(input);
    return true;
    }
}

bool reverse(unsigned short input, signed short &result) 
{
    int checkValue = 0;
    int digitsMissing = 0;
    string inputStr = to_string(input);
    string reversedStr;
    for (int i = inputStr.length() - 1; i >= 0; --i) 
    {
        reversedStr += inputStr[i];
    }
    checkValue = static_cast<int>(stoi(reversedStr));
    if (checkValue <= SHRT_MAX && checkValue >= SHRT_MIN)
    {
        result = static_cast<signed short>(stoi(reversedStr));
        digitsMissing = 5 - inputStr.length();
        for (int i = 0; i < digitsMissing; i++)
        {
            result *= 10;
        }
        return true;
    }
    else
    {
        return false;
    }
}

short subtrct(signed short input, int subtractor) 
{
    if (input - subtractor >= 0) 
    {
        return input - subtractor;
    } else {
        return input; 
    }
}
