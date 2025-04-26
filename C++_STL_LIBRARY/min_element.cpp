// C++ program to illustrate the use of
// std::min_element()
#include <bits/stdc++.h>
using namespace std;

bool comp (int a, int b) {
    return a < b;
}

int main()
{
    vector<int> v = {2, 1, 17, 10};
    int arr[4] = {33, 87, 1, 71};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Min element in vector
    cout << *min_element(v.begin(), v.end())
    	<< endl;

    // Min element in array
    cout << *max_element(v.begin(), v.end());

    return 0;
}
