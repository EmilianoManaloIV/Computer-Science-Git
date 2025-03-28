/* 
 * File:   main.cpp
 * Author: Emiliano Manalo
 * Created on September 10, 2023 10:00 PM
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}
// Read Function that takes in rows, collumns, and inputs
void read(int arr[][COLMAX], int &row, int &col) {
    cout << "Input a table and output the Augment row,col and total sums." << endl;
    cout << "First input the number of rows and cols. <20 for each";
    cin >> row;
    cin >> col;
    cout << "\nNow input the table." << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }
}
// Sums function that copies and places values into the modified array
void sum(const int arr[][COLMAX], int row, int col, int augArr[][COLMAX]) {
    for (int i = 0; i <= row; i++) {
        for (int j = 0; j <= col; j++) {
            augArr[i][j] = 0;
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            augArr[i][j] = arr[i][j];
        }
    }

    for (int i = 0; i < row; i++) {
        int rowSum = 0;
        for (int j = 0; j < col; j++) {
            rowSum += arr[i][j];
        }
        augArr[i][col] = rowSum;
    }

    for (int j = 0; j < col; j++) {
        int colSum = 0;
        for (int i = 0; i < row; i++) {
            colSum += arr[i][j];
        }
        augArr[row][j] = colSum;
    }

    int grandSum = 0;
    for (int i = 0; i < row; i++) {
        grandSum += augArr[i][col];
    }
    augArr[row][col] = grandSum;
}
// Display the result
void print(const int arr[][COLMAX], int row, int col, int width) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << setw(width) << arr[i][j];
        }
        cout << endl;
    }
}