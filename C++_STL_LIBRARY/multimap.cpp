#include <iostream>
#include <map>
using namespace std;

int main() {
    
    // Creating a multimap of integer keys and
    // string values
    multimap<int, string> mm = {{1, "Geeks"},
          {2, "For"}, {1, "C++"}, {2, "STL"}};

    for (auto i : mm) 
        cout << i.first << ": " << i.second
        << "\n";
    return 0;
}
