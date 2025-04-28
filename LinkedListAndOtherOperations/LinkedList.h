#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template<class T>
class LinkedList {
private:
    struct Link {
        T data;         // Data element
        Link *linkPtr;  // Pointer to the next node
    };

    Link *front, *end, *temp;

public:
    LinkedList();               // Default constructor
    LinkedList(const T&);        // Constructor with initial element
    ~LinkedList();               // Destructor
    void printList();            // Print the list
    void addList(const T&);      // Add data to the end
    void markSort();             // Sort the list using markSort
    T popFront();                // Pop data from the front
    T popBack();                 // Pop data from the back
    void prioritizeList(const T&); // Prioritize a list element (move it to front)

    // Other functions like size, count, etc., can be added as needed
};

//---CONSTRUCTORS AND DESTRUCTOR---
template<class T>
LinkedList<T>::LinkedList() {
    front = nullptr;
    end = nullptr;
}

template<class T>
LinkedList<T>::LinkedList(const T &data) {
    front = new Link;
    front->data = data;
    front->linkPtr = nullptr;
    end = front;
}

template<class T>
LinkedList<T>::~LinkedList() {
    // Destructor: Cleanup the list by deleting all nodes
    while (front != nullptr) {
        temp = front->linkPtr;
        delete front;
        front = temp;
    }
    end = nullptr;
}

//---MARK SORT IMPLEMENTATION---
template<class T>
void LinkedList<T>::markSort() {
    // Use two pointers: one for the current node (i) and another to find the minimum (j)
    Link* i = front;
    while (i != nullptr) {
        Link* j = i->linkPtr;
        while (j != nullptr) {
            if (i->data > j->data) {
                // Swap the data in the nodes
                T tempData = i->data;
                i->data = j->data;
                j->data = tempData;
            }
            j = j->linkPtr;  // Move to the next node
        }
        i = i->linkPtr;  // Move to the next node
    }
}

//---ADDITIONAL METHODS IMPLEMENTATION---
template<class T>
void LinkedList<T>::addList(const T &data) {
    // Add an element to the end of the list
    Link *newLink = new Link;
    newLink->data = data;
    newLink->linkPtr = nullptr;
    if (!front) {
        front = newLink;
        end = newLink;
    } else {
        end->linkPtr = newLink;
        end = newLink;
    }
}

template<class T>
void LinkedList<T>::printList() {
    Link* current = front;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->linkPtr;
    }
    cout << endl;
}

template<class T>
T LinkedList<T>::popFront() {
    if (!front) {
        cout << "List is empty. Nothing to pop." << endl;
        exit(EXIT_FAILURE);
    }
    T poppedData = front->data;
    Link* temp = front;
    front = front->linkPtr;
    delete temp;
    if (!front) end = nullptr;  // If the list is empty now, update end
    return poppedData;
}

template<class T>
T LinkedList<T>::popBack() {
    if (!front) {
        cout << "List is empty. Nothing to pop." << endl;
        exit(EXIT_FAILURE);
    }
    if (front == end) {  // Only one element
        T poppedData = front->data;
        delete front;
        front = nullptr;
        end = nullptr;
        return poppedData;
    }
    Link* temp = front;
    while (temp->linkPtr != end) {
        temp = temp->linkPtr;
    }
    T poppedData = end->data;
    delete end;
    end = temp;
    end->linkPtr = nullptr;
    return poppedData;
}

template<class T>
void LinkedList<T>::prioritizeList(const T& element) {
    Link* prev = nullptr;
    Link* current = front;

    while (current != nullptr && current->data != element) {
        prev = current;
        current = current->linkPtr;
    }

    if (current != nullptr && prev != nullptr) {
        // Move the found node to the front
        prev->linkPtr = current->linkPtr;
        current->linkPtr = front;
        front = current;
    }
}

//---END OF LINKEDLIST.H---
#endif /* LINKEDLIST_H */
