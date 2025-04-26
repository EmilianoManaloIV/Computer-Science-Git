#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 3, 5};

    // Remove all occurrences of 3 from vector v
    auto ne = remove(v.begin(), v.end(), 3);
  	v.erase(ne, v.end());

    for (auto i: v)
        cout << i << " ";
    return 0;
}
