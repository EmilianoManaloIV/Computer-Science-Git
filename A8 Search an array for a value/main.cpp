/* 
 * File:   main.cpp
 * Author: Emiliano Manalo
 * Created on September 10, 2023 3:12 PM
 * Purpose:  Searching an array for a value 
 */

//System Libraries Here
#include <iostream>
#include <cstring>
using namespace std;
//Function Prototypes Begins Here
int srch1(const char [], const char [], int );
void srchAll(const char [], const char [], int []);
void print(const char []);
void print(const int []);
// Program execution starts Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE = 81;
    char sntnce[LINE], pattern[LINE];
    int match[LINE];
    //Input or initialize values Here
    cout << "Match a pattern in a sentence." << endl;
    cout << "Input a sentence" << endl;
    cin.getline(sntnce, LINE);
    cout << "Input a pattern." << endl;
    cin.getline(pattern, LINE);

    srchAll(sntnce, pattern, match);

    cout << endl << "The sentence and the pattern" << endl;
    print(sntnce);
    print(pattern);
    cout << "The positions where the pattern matched" << endl;
    print(match);
    // Exist stage right
    return 0;
}
// Is there a positon or not?
int srch1(const char sentence[], const char pattern[], int startPos) 
{
    int sentenceLength = strlen(sentence);
    int patternLength = strlen(pattern);

    for (int i = startPos; i <= sentenceLength - patternLength; i++) {
        bool found = true;
        for (int j = 0; j < patternLength; j++) {
            if (sentence[i + j] != pattern[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i; 
        }
    }

    return -1; 
}
// Search for the one occurence of a match
void srchAll(const char sentence[], const char pattern[], int match[]) 
{
    int sentenceLength = strlen(sentence);
    int patternLength = strlen(pattern);
    int count = 0; 

    int startPos = 0; 

    while (true) {
        int position = srch1(sentence, pattern, startPos);
        if (position != -1) {
            match[count] = position;
            count++;
            startPos = position + 1; 
        } else {
            break; 
        }
    }
    match[count] = -1; 
}
// Print a char array
void print(const char arr[]) 
{
    cout << arr << endl;
}
// Print an integer array or return none if no match found
void print(const int arr[]) 
{
    for (int i = 0; arr[i] != -1; i++) {
        cout << arr[i] << endl;
    }
    if(arr[0]==-1)
    {
        cout << "None" << endl;
    }
}

