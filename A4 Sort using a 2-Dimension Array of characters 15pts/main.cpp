/* 
 * File:   main.cpp
 * Author: Emiliano Manalo
 * Created on September 10, 2023 9:11 PM
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int);//Sort by row
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}
// Read the the lines and input values into array
int read(char array[][COLMAX], int &rowDet) {
    int colDet = 0;
    int i = 0;
    int rowC = 0;
    while(cin>>array[i])
    {
        if(strlen(array[i])>colDet)
        {
            colDet = strlen(array[i]);
        }
        i++;
        rowC++;
    }

    return colDet;
}
// Sort the array by row
void sort(char array[][COLMAX], int rowDet, int colDet) {
    for (int i = 0; i < rowDet - 1; i++) {
        for (int j = 0; j < rowDet - i - 1; j++) {
            if (strcmp(array[j], array[j + 1]) > 0) {
                char temp[COLMAX];
                strcpy(temp, array[j]);
                strcpy(array[j], array[j + 1]);
                strcpy(array[j + 1], temp);
            }
        }
    }
}
// Print out row 
void print(const char array[][COLMAX], int rowDet, int colDet) {
    for (int i = 0; i < rowDet; i++) {
        cout << array[i] << endl;
    }
}
