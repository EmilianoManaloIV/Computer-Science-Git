#include <iostream>
#include <set>
using namespace std;

int main() {
    
    // Creating a set of integers
    multiset<int> ms = {5, 1, 3, 3};

    for (auto i : ms)
        cout << i << " ";
    return 0;
}
