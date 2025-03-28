/* 
 * File:   main.cpp
 * Author: Emiliano Manalo
 * Created on September 9, 2023 12:34 PM
 * Purpose:  Summing, Finding the Max and Min of an integer array
 * Note:  Look at the output for the format for print
 */

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int [],int);
int  stat(const int [],int,int &,int &);
void print(const int [],int,int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    sum=stat(array,sizeIn,max,min);//Output the sum, max and min
    
    //Print the results
    print(array,sizeIn,sum,max,min);//print the array, sum, max and min

    //Exit
    return 0;
}
// Reads the inputs into an array
void read(int arr[], int size) 
{
    for (size_t i = 0; i < size; i++) 
    {
        cin >> arr[i];
    }
}
int stat(const int arr[], int size, int& max, int& min) 
{
    if (size == 0) 
    {
        max = min = 0; 
        return 0;
    }
    int sum = arr[0];
    max = arr[0];
    min = arr[0];

    for (size_t i = 1; i < size; i++) 
    {
        sum += arr[i];
        if (arr[i] > max) 
        {
            max = arr[i];
        }
        if (arr[i] < min) 
        {
            min = arr[i];
        }
    }
    return sum;
}
void print(const int arr[],int size,int sum,int max,int min)
{
    //Print each element in each part of the array
    for(int i = 0; i < size; i++)
    {
        cout << "a[" << i << "]" << " = " << arr[i] << endl;
    }
    // Display Min, Max, and sum
    cout << "Min  = " << min << endl;
    cout << "Max  = " << max << endl;
    cout << "Sum  = " << sum << endl;
}
