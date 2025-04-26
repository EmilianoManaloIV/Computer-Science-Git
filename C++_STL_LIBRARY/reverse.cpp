#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    // Reversing the vector
    reverse(v.begin(), v.end());

    for (int i : v) cout << i << " ";
    return 0;
}
