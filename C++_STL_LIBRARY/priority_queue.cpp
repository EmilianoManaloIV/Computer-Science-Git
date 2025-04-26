#include <iostream>
#include <queue>
using namespace std;

int main() {
    
    // Creating a priority queue of integers
    priority_queue<int> pq;
    pq.push(9);
    pq.push(10);
    pq.push(6);
    
    cout << pq.top() << " ";
    return 0;
}
