/* 
 * File:        main.cpp
 * Author:      Emiliano Manalo
 * Created on:  08/29/2023
 * Purpose:  To tell the Truth
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
char IS(bool);
char NOT(bool);
char AND(bool,bool);
char OR(bool,bool);
char XOR(bool, bool);
char XORX(bool,bool);
char XORY(bool,bool);
char NOTXANDY(bool,bool);
char NOTXORNOTY(bool, bool);
char NOTXORY(bool, bool);
char NOTXANDNOTY(bool, bool);
void DisplayTruthTableFor(bool,bool);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    bool x,y;
    bool tempx, tempy;
    bool isDuplicateInput = false;
    bool isFirstInput = true;
   
    
    //Display the Heading
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y "<<
          " !(X||Y) !X&&!Y"<<endl;
          
    //Display all pementation for boolean pair until duplicate input
  do 
  {
      cin >> x >> y;
      if(isFirstInput)
      {
          DisplayTruthTableFor(x,y);
          tempx = x;
          tempy = y;
          isFirstInput = false;
      }
      else
      {
          if(x==tempx&&y==tempy)
          {
              isDuplicateInput = true;
          }
          else
          {
              DisplayTruthTableFor(x,y);
              tempx = x;
              tempy= y;
          }
      }
      
  }while(!isDuplicateInput);
  cout << endl;
  
  // End The Program
    return 0;
}
char IS(bool var1)
{
    return var1?'T':'F';
}
char NOT( bool var1)
{
    return !var1?'T':'F';
}
char AND(bool var1, bool var2)
{
    return var1&&var2?'T':'F';
}
char OR(bool var1, bool var2)
{
    return var1||var2?'T':'F';
}
char XOR(bool var1, bool var2)
{
    return var1^var2?'T':'F';
}
char XORX(bool var1, bool var2)
{
    return var1^var2^var1?'T':'F';
}
char XORY(bool var1, bool var2)
{
    return var1^var2^var2?'T':'F';
}
char NOTXANDY(bool var1, bool var2)
{
    return !(var1&&var2)?'T':'F';
}
char NOTXORNOTY(bool var1, bool var2)
{
    return !var1||!var2?'T':'F';
}
char NOTXORY(bool var1, bool var2)
{
    return !(var1||var2)?'T':'F';
}
char NOTXANDNOTY(bool var1, bool var2)
{
    return !var1&&!var2?'T':'F';
}
void DisplayTruthTableFor(bool varx, bool vary)
{
     cout<<IS(varx)<<" "
        <<IS(vary)<<"  "
        <<NOT(varx)<<"  "
        <<NOT(vary)<<"   "
        <<AND(varx,vary)<<"    "
        <<OR(varx,vary) <<"   "
        <<XOR(varx,vary) <<"    "
        <<XORX(varx,vary)<<"     "
        <<XORY(varx,vary)<<"       "
        <<NOTXANDY(varx,vary)<<"      "
        <<NOTXORNOTY(varx,vary)<<"        "
        <<NOTXORY(varx,vary)<<"      "
        <<NOTXANDNOTY(varx,vary) <<endl;
}