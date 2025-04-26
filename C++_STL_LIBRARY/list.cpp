#include <iostream>
#include <list>
using namespace std;

int main() {
    
    // Creating a list of 5 elements
    list<int> l = {1, 3, 2, 8, 9};

    for (auto x : l)
        cout << x << " ";
    return 0;
}
