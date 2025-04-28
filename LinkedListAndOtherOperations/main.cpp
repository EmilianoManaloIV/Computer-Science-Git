#include <iostream>
#include "LinkedList.h" // Include the LinkedList header file

using namespace std;

int main() {
    // Create a LinkedList of integers
    LinkedList<int> myList;

    // Add elements to the list
    myList.addList(10);
    myList.addList(5);
    myList.addList(15);
    myList.addList(1);
    myList.addList(20);

    // Print the original list
    cout << "Original List: ";
    myList.printList();

    // Sort the list using the markSort method
    myList.markSort();

    // Print the sorted list
    cout << "Sorted List: ";
    myList.printList();

    // Test other methods like popFront and popBack
    cout << "Popped from front: " << myList.popFront() << endl;
    cout << "Popped from back: " << myList.popBack() << endl;

    // Print the list after popping elements
    cout << "List after pops: ";
    myList.printList();

    // Prioritize a list item (move item 15 to the front)
    myList.prioritizeList(15);

    // Print the list after prioritizing
    cout << "List after prioritizing 15: ";
    myList.printList();

    return 0;
}
