/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  To Test and Modify the Simple Vector
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "LinkedList.h"

// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   //Adding 4 functions Push front/back, Pop front/back
   void pshFrnt(T);
   void pshBack(T);
   T popFrnt();
   T popBack();
};

//*******************************************
//Student to code these functions
//*******************************************

template <class T>
void SimpleVector<T>::pshFrnt(T val)
{
  //Allocate a new array
   T *nptr = new T [arraySize+1];

   //Copy the contents of the old array to the new
   for (int count = 0; count < arraySize; count++)
      *(nptr + count + 1) = *(aptr + count);

   //Add the new value into the new array
   nptr[0]=val;
   
   //Delete the old memory and increment the arraySize
   arraySize++;
   delete [] aptr;
   
   //Set the old to the new and done
   aptr=nptr;
}


template <class T>
void SimpleVector<T>::pshBack(T val)
{
   //Allocate a new array
   T *nptr = new T [arraySize+1];

   //Copy the contents of the old array to the new
   for (int count = 0; count < arraySize; count++)
      *(nptr + count) = *(aptr + count);

   //Add the new value into the new array
   nptr[arraySize]=val;
   
   //Delete the old memory and increment the arraySize
   arraySize++;
   delete [] aptr;
   
   //Set the old to the new and done
   aptr=nptr;
}

template <class T>
T SimpleVector<T>::popFrnt()
{
    //Allocate a new array
   T *nptr = new T [arraySize-1];

   //Copy the contents of the old array to the new
   for (int count = 0; count < arraySize-1; count++)
      *(nptr + count) = *(aptr + count + 1);
   
   //Delete the old memory and decrement the arraySize
   arraySize--;
   T retVal=aptr[0];
   delete [] aptr;
   
   //Set the old to the new, return popped value and done
   aptr=nptr;
   return retVal;
   return 65;
}

template <class T>
T SimpleVector<T>::popBack()
{
   //Allocate a new array
   T *nptr = new T [arraySize-1];

   //Copy the contents of the old array to the new
   for (int count = 0; count < arraySize-1; count++)
      *(nptr + count) = *(aptr + count);
   
   //Delete the old memory and decrement the arraySize
   arraySize--;
   T retVal=aptr[arraySize];
   delete [] aptr;
   
   //Set the old to the new, return popped value and done
   aptr=nptr;
   return retVal;
   return 65;
}

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}
#endif

//Global Constants

//Function prototypes
int mrkRand(int seed=0);
void fillVec(SimpleVector<char> &);
void prntVec(SimpleVector<char> &,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int size;
    cout<<"Input the Size of the Array 10-200"<<endl;
    cin>>size;
    cout<<"The array Size = "<<size<<endl;
    LinkedList<char> *charLnkList;
    charLnkList = new LinkedList<char>(mrkRand()%26+65);
    for(int i = 1; i < size; i++) // Start from 1, not 3
    {
        charLnkList->addLst(mrkRand()%26+65);
    }
    
    charLnkList->prntLst();

    //Add a value to the array
    char vlFrnt=mrkRand()%26+65;
    char vlBack=mrkRand()%26+65;
    cout<<"The value added to the front is = "<<vlFrnt<<endl;
    cout<<"The value added to the back  is = "<<vlBack<<endl;
    //sv.pshFrnt(vlFrnt);
    //sv.pshBack(vlBack);
    charLnkList->push_front(vlFrnt);
    charLnkList->push_back(vlBack);
    
    //Print the Vector
    charLnkList->prntLst();
    
    //Remove 2 from the Front and 2 from the back
    cout<<endl;
    cout<<"Remove 2 from the front and back"<<endl;
    cout<<"Front Removed = "<<charLnkList->pop_front()<<endl;
    cout<<"Front Removed = "<<charLnkList->pop_front()<<endl;
    cout<<"Back  Removed = "<<charLnkList->pop_back()<<endl;
    cout<<"Back  Removed = "<<charLnkList->pop_back()<<endl;
    
    //Print the Vector
    charLnkList->prntLst();

    return 0;
}

void prntVec(SimpleVector<char> &sv,int perLine){
    cout<<endl;
    for(int i=0;i<sv.size();i++){
        cout<<sv[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillVec(SimpleVector<char> &sv){
    for(int i=0;i<sv.size();i++){
        sv[i]=mrkRand(sv.size())%26+65;
    }
}

int mrkRand(int seed){
    //Xn+1 = (aXn + c) mod m
    //where X is the sequence of pseudo-random values
    //m, 0 < m  - modulus 
    //a, 0 < a < m  - multiplier
    //c, 0 ≤ c < m  - increment
    //x0, 0 ≤ x0 < m  - the seed or start value
    unsigned int a=31051;      //Short Prime
    unsigned int c=997;        //Another Prime
    unsigned int shrt=1<<15-1; //Range of positive signed short
    unsigned int m=1<<31-1;    //Range of positive signed int
    static int Xn=30937;       //Short Prime
    static int cnt=0;          //Initialize the seed
    if(cnt==0&&seed<=shrt)Xn=seed;
    cnt++;
    Xn=(a*Xn+c)%m;
    return Xn;
}