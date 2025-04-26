#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    
    // Creating an unordered_map with
    // integer keys and string values
    unordered_multimap<int, string> umm =
                   {{1, "Geeks"}, {2, "For"},
                   {3, "C++"}, {1, "STL"}};
    for (auto x : umm) 
        cout << x.first << ": " << x.second
        << endl;
    return 0;
}
