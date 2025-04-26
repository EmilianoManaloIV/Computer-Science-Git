// C++ program to demonstrate the use of std::accumulate function
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec = { 5, 10, 15 };
  
  	// Defining range as whole array
  	auto first = vec.begin();
  	auto last = vec.end();

    // Use accumulate to find the sum of elements in the vector
    int sum = accumulate(first, last, 0);
  
    cout << sum << endl;

    return 0;
}
