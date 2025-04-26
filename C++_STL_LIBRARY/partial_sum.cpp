// C++ program to demonstrate the use of std::partial_sum function
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec = {5, 10, 15};
    vector<int> res(vec.size());
  
    // Defining range as the whole array
    auto first = vec.begin();
    auto last = vec.end();
  
    // Use partial_sum to calculate the cumulative sum of elements
    partial_sum(first, last, res.begin());

    for (int val : res)
        cout << val << " ";
    return 0;
}
