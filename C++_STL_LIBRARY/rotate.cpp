#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    // Rotating vector 2 places to right such that
  	// element at index 2 becomes first element
    rotate(v.begin(), v.begin() + 2, v.end());

    for (int i : v) cout << i << " ";
    return 0;
}
