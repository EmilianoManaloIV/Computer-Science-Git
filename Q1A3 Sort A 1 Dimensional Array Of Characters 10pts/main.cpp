/* 
 * File:   main.cpp
 * Author: Emiliano Manalo
 * Created on September 9, 2023 11:12 AM
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    string numberInput;
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    //Turn the string of integers into an array of characters
    cin>>numberInput;
     for (size_t i = 0; i < numberInput.length(); ++i) 
     {
        array[i] = numberInput[i];
    }
    sizeDet=read(array);//Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    //Exit
    return 0;
}
// Determine size of the array given
int read(char arr[]) {
    int size = 0;
    while (arr[size] != '\0') 
    {
        size++;
    }
    return size;
}
// Sort with bubble sort alogithim
void sort(char arr[], int length) 
{
    for (int i = 0; i < length - 1; i++) 
    {
        for (int j = 0; j < length - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// Dispaly the array
void print(const char arr[], int length) 
{
    for (int i = 0; i < length; i++) 
    {
        cout << arr[i];
    }
    cout << endl;
}
