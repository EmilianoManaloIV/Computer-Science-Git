/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 */

//Libraries
#include <cstdlib>//Random number seed
#include <ctime>//Set the seed
#include <iostream>//I/O
#include <set>
#include <map>
#include <vector>
using namespace std;

//No Global Constants

//Function Prototypes
int *fillAry(int,int);
void prntAry(int *,int,int);
void prntMod(int *);
void swap(int *,int *);
void minPos(int *,int,int);
void mrkSort(int *,int);
int *mode(const int *,int);
int *copy(const int *,int);
int *modeSet(const int *, int);
int *modeMap(const int *, int);

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize=15;
    int modNum=10;
    int *ary=fillAry(arySize,modNum);
    
    //Print the initial array
    cout << "Original Array:" << endl;
    prntAry(ary,arySize,10);
    
    //Test all three implementations
    cout << "\nTesting Original Mode Function:" << endl;
    int *modeAry1 = mode(ary,arySize);
    prntMod(modeAry1);
    
    cout << "\nTesting Set-based Mode Function:" << endl;
    int *modeAry2 = modeSet(ary,arySize);
    prntMod(modeAry2);
    
    cout << "\nTesting Map-based Mode Function:" << endl;
    int *modeAry3 = modeMap(ary,arySize);
    prntMod(modeAry3);
    
    //Delete allocated memory
    delete []ary;
    delete []modeAry1;
    delete []modeAry2;
    delete []modeAry3;
    
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

int *mode(const int *array,int arySize){
    //Copy the array
    int *ary=copy(array,arySize);
    //Sort the ary
    mrkSort(ary,arySize);
    //Sort the copy
    //Find the max Freq
    int count=0,maxFreq=0;
    for(int i=0;i<arySize-1;i++){
        if(ary[i]==ary[i+1]){
            count++;
            if(maxFreq<count)maxFreq=count;
        }else{
            count=0;
        }
    }
    //Find the number of modes
    count=0;
    int nModes=0;
    for(int i=0;i<arySize-1;i++){
        if(ary[i]==ary[i+1]){
            count++;
            if(maxFreq==count)nModes++;
        }else{
            count=0;
        }
    }
    //Allocate the mode array
    int *modeAry=new int[nModes+2];
    //Fill the mode array
    modeAry[0]=nModes;
    modeAry[1]=maxFreq+1;
    count=0;
    int indx=2;
    for(int i=0;i<arySize-1;i++){
        if(ary[i]==ary[i+1]){
            count++;
            if(maxFreq==count)modeAry[indx++]=ary[i];
        }else{
            count=0;
        }
    }
    //Delete the allocated copy and return
    delete []ary;
    return modeAry;
}

int *modeSet(const int *array, int arySize) {
    //Create a set to store unique values and their frequencies
    set<pair<int, int>> freqSet;
    
    //Count frequencies
    for(int i = 0; i < arySize; i++) {
        int count = 0;
        for(int j = 0; j < arySize; j++) {
            if(array[i] == array[j]) count++;
        }
        freqSet.insert({count, array[i]});
    }
    
    //Find max frequency
    int maxFreq = freqSet.rbegin()->first;
    
    //Count modes
    int nModes = 0;
    for(auto it = freqSet.rbegin(); it != freqSet.rend(); it++) {
        if(it->first == maxFreq) nModes++;
        else break;
    }
    
    //Create result array
    int *modeAry = new int[nModes + 2];
    modeAry[0] = nModes;
    modeAry[1] = maxFreq;
    
    //Fill modes
    int idx = 2;
    for(auto it = freqSet.rbegin(); it != freqSet.rend() && idx < nModes + 2; it++) {
        if(it->first == maxFreq) modeAry[idx++] = it->second;
    }
    
    return modeAry;
}

int *modeMap(const int *array, int arySize) {
    //Create a map to store value frequencies
    map<int, int> freqMap;
    
    //Count frequencies in a single pass
    for(int i = 0; i < arySize; i++) {
        freqMap[array[i]]++;
    }
    
    //Find max frequency
    int maxFreq = 0;
    for(const auto &pair : freqMap) {
        maxFreq = max(maxFreq, pair.second);
    }
    
    //Count modes and create result array
    int nModes = 0;
    for(const auto &pair : freqMap) {
        if(pair.second == maxFreq) nModes++;
    }
    
    int *modeAry = new int[nModes + 2];
    modeAry[0] = nModes;
    modeAry[1] = maxFreq;
    
    //Fill modes
    int idx = 2;
    for(const auto &pair : freqMap) {
        if(pair.second == maxFreq) modeAry[idx++] = pair.first;
    }
    
    return modeAry;
}

void prntMod(int *ary){
    cout<<endl;
    cout<<"The number of modes = "<<
            ary[0]<<endl;
    cout<<"The max Frequency = "<<
            ary[1]<<endl;
    if(ary[0]==0){
        cout<<"The mode set = {null}"<<endl;
        return;
    }
    cout<<"The mode set = {";
    for(int i=2;i<ary[0]+1;i++){
        cout<<ary[i]<<",";
    }
    cout<<ary[ary[0]+1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        minPos(array,n,i);
    }
}

void minPos(int *array,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(*(array+pos)>*(array+i))
            swap(array+pos,array+i);
    }
}

void swap(int *a,int *b){
    //Swap in place
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

void prntAry(int *array,int n,int perLine){
    //Output the array
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(array+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n, int modNum){
    //Allocate memory
    int *array=new int[n];
    
    //Fill the array with 2 digit numbers
    for(int i=0;i<n;i++){
        *(array+i)=i%modNum;
        //*(array+i)=rand()%modNum;
    }
    
    //Exit function
    return array;
}