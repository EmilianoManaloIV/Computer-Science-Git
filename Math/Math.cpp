/* 
 * File:    main.cpp
 * Author:  Emilano Manalo
 * Date:    08/29/2023
 * Purpose: Output Format
 * Version: 1.0
 */

//System Libraries - Post Here
#include <iostream>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    int A, B, C;
    //7 characters or less
    
    //Initialize or input data here
    cin >> A;
    cin >> B;
    cin >> C;
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    cout << "A + B is: " << (A + B) << endl;
    cout << "B + A - C is: " << A + B - C << endl;
    cout << "(A + B) * C is: " << (A + B) * C << endl;
    cout << "(A / B) * C is: " << (A / B) * C << endl;
    cout << "(A * C) / B is: " << (A * C) / B << endl;
    cout << "A % B is: " << A % B << endl;
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}