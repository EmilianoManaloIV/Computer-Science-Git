#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    
    // Creating unordered multiset of
    // integers
    unordered_multiset<int> ums =
                          {5, 1, 3, 4, 1};

    for (auto x : ums)
        cout << x << " ";
    return 0;
}
