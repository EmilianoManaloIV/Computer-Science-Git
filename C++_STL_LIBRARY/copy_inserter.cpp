// C++ code to demonstrate the working of copy() using inserter() 

#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std; 

int main() 
{ 

	vector<int> v1 = {1, 5, 7, 3, 8, 3}; 
	vector<int>::iterator itr; 
	vector<int> v2; 

	//using inserter() 
	copy(v1.begin(), v1.end(), inserter(v2, itr)); 

	cout << "\nThe new vector elements entered using inserter: "; 
	for (int i = 0; i < v2.size(); i++) 
		cout << v2[i] << " "; 

}
