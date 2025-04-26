#include <iostream>
#include <forward_list>
using namespace std;

int main() {
    
    // Create a forward list with 4 elements
    forward_list<int> fl = {1, 5, 3, 4};

    for (auto i : fl) 
        cout << i << " ";
    return 0;
}
