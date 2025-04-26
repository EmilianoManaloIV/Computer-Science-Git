#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v1 = {1, 5, 6, 8};
    vector<int> v2(v1.size());

    // Incrementing all elements of vector by 1
    transform(v1.begin(), v1.end(), v2.begin(),
              [](int a) { 
                return a + 1;
              });

    for (auto i : v2)
        cout << i << " ";
    return 0;
}
