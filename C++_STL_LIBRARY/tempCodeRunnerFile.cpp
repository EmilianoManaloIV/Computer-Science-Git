// C++ program to illustrate the use of 
// std::max_element()
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {2, 1, 17, 10};
  	int arr[4] = {33, 87, 1, 71};
  	int n = sizeof(arr)/sizeof(arr[0]);
    
  	// Max element in vector
    cout << *max_element(v.begin(), v.end()) << endl;
  
 