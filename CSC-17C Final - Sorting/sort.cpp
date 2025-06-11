#include <algorithm>
#include <chrono>
#include <iostream>
#include <list>
#include <random>
#include <vector>
using namespace std;
//---RNG VALUE---
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<short> shortIntDist(0, 32767);
//---GLOBAL VALUES---
int mergeSortOpp = 0;
int selectionSortOpp = 0;
// Merge function for merge sort
void merge(list<short int> &lst, list<short int> &left,
list<short int> &right) {
lst.clear();
mergeSortOpp++;
auto leftIt = left.begin();
auto rightIt = right.begin();
while (leftIt != left.end() && rightIt != right.end()) {
mergeSortOpp++;
if (*leftIt <= *rightIt) {
lst.push_back(*leftIt);
++leftIt;
} else {
lst.push_back(*rightIt);
++rightIt;
}
}
// Append remaining elements
while (leftIt != left.end()) {
lst.push_back(*leftIt);
++leftIt;
mergeSortOpp++;
}
while (rightIt != right.end()) {
lst.push_back(*rightIt);
++rightIt;
mergeSortOpp++;
}
}
// Complete merge sort
void mergeSort(list<short int> &lst) {
if (lst.size() <= 1)
return;
mergeSortOpp++;
// Split the list into two halves
list<short int> left;
list<short int> right;
auto slow = lst.begin();
auto fast = lst.begin();
// Use fast/slow iterator technique to find middle
while (fast != lst.end()) {
++fast;
if (fast != lst.end()) {
++fast;
++slow;
}
}
// Move elements from lst to left and right
left.splice(left.begin(), lst, lst.begin(), slow);
right.splice(right.begin(), lst, lst.begin(), lst.end());
// Recursively sort the halves
mergeSort(left);
mergeSort(right);
// Merge sorted halves back into lst
merge(lst, left, right);
}
// Partial selection sort - only sort first p elements
void partialSelectionSort(list<short int> &lst, int p) {
if (p <= 0 || lst.empty())
return;
auto end_pos = lst.begin();
advance(end_pos, min(p, (int)lst.size()));
for (auto pos = lst.begin(); pos != end_pos; ++pos) {
auto minIt = pos;
for (auto it = next(pos); it != lst.end(); ++it) {
selectionSortOpp++;
if (*it < *minIt) {
minIt = it;
}
}
if (minIt != pos) {
swap(*pos, *minIt);
selectionSortOpp++;
}
}
}
// Get top p elements using merge sort
list<short int> getTopPMergeSort(list<short int> arr, int p) {
mergeSortOpp = 0;
mergeSort(arr);
list<short int> result;
auto it = arr.begin();
for (int i = 0; i < p && it != arr.end(); ++i, ++it) {
result.push_back(*it);
}
return result;
}
// Get top p elements using partial selection sort
list<short int> getTopPSelectionSort(list<short int> arr, int p) {
selectionSortOpp = 0;
partialSelectionSort(arr, p);
list<short int> result;
auto it = arr.begin();
for (int i = 0; i < p && it != arr.end(); ++i, ++it) {
result.push_back(*it);
}
return result;
}
int main() {
const int ARRAY_SIZE = 100000;
vector<int> p_values;
for (int i = 1; i <= 8; i++)
p_values.push_back(i);
cout << "Sorting Algorithm Performance Analysis" << endl;
cout << "Array Size: " << ARRAY_SIZE << " elements" << endl;
cout << "========================================" << endl;
for (int p : p_values) {
cout << "\nAnalyzing for p = " << p << " elements:" << endl;
cout << "----------------------------------------" << endl;
// Run multiple trials for better accuracy
const int TRIALS = 5;
long long totalMergeTime = 0, totalSelectionTime = 0;
long long totalMergeOps = 0, totalSelectionOps = 0;
for (int trial = 0; trial < TRIALS; trial++) {
// Generate random data
list<short int> arr;
for (int i = 0; i < ARRAY_SIZE; i++) {
arr.push_back(shortIntDist(gen));
}
// Test Merge Sort
auto start = chrono::high_resolution_clock::now();
list<short int> mergeResult = getTopPMergeSort(arr, p);
auto end = chrono::high_resolution_clock::now();
auto mergeTime =
chrono::duration_cast<chrono::nanoseconds>(end - start).count();
totalMergeTime += mergeTime;
totalMergeOps += mergeSortOpp;
// Test Selection Sort
start = chrono::high_resolution_clock::now();
list<short int> selectionResult = getTopPSelectionSort(arr, p);
end = chrono::high_resolution_clock::now();
auto selectionTime =
chrono::duration_cast<chrono::nanoseconds>(end - start).count();
totalSelectionTime += selectionTime;
totalSelectionOps += selectionSortOpp;
}
// Calculate averages
long long avgMergeTime = totalMergeTime / TRIALS;
long long avgSelectionTime = totalSelectionTime / TRIALS;
long long avgMergeOps = totalMergeOps / TRIALS;
long long avgSelectionOps = totalSelectionOps / TRIALS;
// Display results
cout << "Merge Sort - Time: " << avgMergeTime
<< " ns, Operations: " << avgMergeOps << endl;
cout << "Selection Sort - Time: " << avgSelectionTime
<< " ns, Operations: " << avgSelectionOps << endl;
// Analysis
if (avgMergeTime < avgSelectionTime) {
cout << "Winner: Merge Sort (faster by "
<< ((double)avgSelectionTime / avgMergeTime) << "x)" << endl;
} else {
cout << "Winner: Selection Sort (faster by "
<< ((double)avgMergeTime / avgSelectionTime) << "x)" << endl;
}
// Time complexity analysis
cout << "Time Complexity Analysis:" << endl;
cout << " Merge Sort: O(n log n) = O(" << ARRAY_SIZE << " * log("
<< ARRAY_SIZE << ")) O("
<< (long long)(ARRAY_SIZE * log2(ARRAY_SIZE)) << ")" << endl;
cout << " Selection Sort (partial): O(p * n) = O(" << p << " * "
<< ARRAY_SIZE << ") = O(" << (long long)p * ARRAY_SIZE << ")" << endl;
}
cout << "\n========================================" << endl;
cout << "ANALYSIS SUMMARY:" << endl;
cout << "- Selection Sort is better for small p values" << endl;
cout << "- Merge Sort becomes better as p increases" << endl;
cout << "- Crossover point depends on implementation and data" << endl;
cout << "- Selection Sort: O(p*n), Merge Sort: O(n log n)" << endl;
return 0;
}