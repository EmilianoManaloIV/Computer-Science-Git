/* 
 * File:
 * Author:
 * Date:
 * Purpose:
 * Version:
 */

//System Libraries - Post Here
#include <iostream>
//Library for our functions utilized in this question.
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here
void displayField_INT(int, int, int);
void displayField_INT(int, int);
void exampleDisplay(int);
//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    int a, b, c, d;
    //7 characters or less
    
    //Initialize or input data here
    cin >> a >> b >> c >> d;
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    exampleDisplay(a);
    cout << endl;
    exampleDisplay(b);
    cout << endl;
    exampleDisplay(c);
    cout << endl;
    exampleDisplay(d);
    
    //Exit stage left
    return 0;
}
void displayField_INT(int n, int w, int p)
{
    cout << setw(w + 1) << showpoint << fixed << setprecision(p) << (double)n;
};
void displayField_INT(int n, int w)
{
    cout << setw(w) << fixed << n;
};
void exampleDisplay(int n)
{
    displayField_INT(n,9);
    displayField_INT(n,9,1);
    displayField_INT(n,9,2);
};
