#include <iostream>
#include <set>
using namespace std;

int main() {
    
    // Creating a set of integers
    set<int> s = {3, 5, 2, 1};
    
    for (auto x : s)
        cout << x << " ";
    return 0;
}
