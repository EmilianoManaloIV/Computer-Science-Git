#include <bits/stdc++.h>
using namespace std;

int main() {
    
    // Creating a map of integer keys
    // and string values
    map<int, string> m {{1, "Geeks"},
             {2,"For"}, {3,"Geeks"}};

    for (auto& p : m)
        cout << p.first << " " << p.second
        << "\n";
    return 0;
}
