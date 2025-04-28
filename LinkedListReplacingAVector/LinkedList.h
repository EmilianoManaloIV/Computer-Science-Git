/*  
 * File:   LinkedList.h
 * Author: Dr. Mark E. Lehr
 * Created on March 22nd, 2021, 3:22 PM
 *      Purpose:  Implementation of the previous linked list functions
 */

 #ifndef LINKEDLIST_H
 #define LINKEDLIST_H
 
 #include <iostream>
 using namespace std;
 
 template<class T>
 class LinkedList{
     private:
         struct Link{
             T data;         //Mainly for Objects
             Link *linkPtr;  //Self Reference which when utilized forms a linked list
         };
         Link *front,*next,*temp,*end,*found; //Permanent and Temp pointers
         void endLst();          //Find the end of the list
         void fndLst(const T&);  //Determine address of link that contains the data
     public:
         LinkedList();             // Default constructor
         LinkedList(const T&);      // Constructor with initial element
         ~LinkedList();
         void prntLst();           //Print each data element in the list
         void  addLst(const T&);   //Add data at the end of the list
         int  findLst(const T&);   //Determine what link contains the data
         int   cntLst();           //How many elements are in the list
         T     getObj(int);        //Return the object
 
         //---ADDED METHODS---
         T pop_front();
         T pop_back();
         void push_front(const T&);
         void push_back(const T&);
         void dstryLst();
 };
 
 //---ADDED METHODS IMPLEMENTATION---
 template<class T>
 T LinkedList<T>::pop_front() {
     if (!front) {
         cout << "List is empty. Nothing to pop." << endl;
         exit(EXIT_FAILURE);
     }
     //Extract data from the front
     T poppedData = front->data;
     //Delete popped front data but set new front of element over
     Link *temp = front;
     front = temp->linkPtr;
     delete temp;
     if (!front) end = nullptr; // if list is now empty, update end
     return poppedData;
 }
 
 template<class T>
 T LinkedList<T>::pop_back() {
     if (!front) {
         cout << "List is empty. Nothing to pop." << endl;
         exit(EXIT_FAILURE);
     }
     if (front == end) { // Only one element
         T poppedData = front->data;
         delete front;
         front = nullptr;
         end = nullptr;
         return poppedData;
     }
     //Extract data from the back
     temp = front;
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
 void LinkedList<T>::push_front(const T &Element) {
     Link *newLink = new Link;
     newLink->data = Element;
     newLink->linkPtr = front;
     front = newLink;
     if (!end) end = front; // If list was empty, set end
 }
 
 template<class T>
 void LinkedList<T>::push_back(const T &Element) {
     Link *newLink = new Link;
     newLink->data = Element;
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
 void LinkedList<T>::dstryLst() {
     while (front != nullptr) {
         temp = front->linkPtr;
         delete front;
         front = temp;
     }
     end = nullptr;
 }
 
 //---CONSTRUCTORS---
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
 
 //---STANDARD METHODS---
 template<class T>
 void LinkedList<T>::prntLst() {
     next = front; //Create a pointer to the list
     cout << endl << "The Beginning of the List" << endl;
     do {
         cout << next->data << endl; //Print the contents of the link
         next = next->linkPtr;        //Go to the next link in the list
     } while (next != NULL);          //Loop until reaching the end
     cout << "The End of the List" << endl << endl;
 }
 
 template<class T>
 LinkedList<T>::~LinkedList() {
     dstryLst();
 }
 
 template<class T>
 void LinkedList<T>::endLst() {
     temp = front;
     do {
         end = temp;
         temp = temp->linkPtr;
     } while (temp != NULL);
 }
 
 template<class T>
 void LinkedList<T>::addLst(const T &data) {
     push_back(data);
 }
 
 template<class T>
 int LinkedList<T>::findLst(const T &value) {
     int n = 0;
     temp = front;
     do {
         if (temp->data == value) return n;
         n++;
         temp = temp->linkPtr;
     } while (temp != NULL);
     return -1;
 }
 
 template<class T>
 void LinkedList<T>::fndLst(const T &value) {
     found = front;
     do {
         if (found->data == value) return;
         found = found->linkPtr;
     } while (found != NULL);
     found = NULL;
 }
 
 template<class T>
 int LinkedList<T>::cntLst() {
     int n = 0;
     temp = front;
     while (temp != NULL) {
         n++;
         temp = temp->linkPtr;
     }
     return n;
 }
 
 template<class T>
 T LinkedList<T>::getObj(int indx) {
     int n = 0;
     temp = front;
     while (temp != NULL) {
         if (n == indx) return temp->data;
         n++;
         temp = temp->linkPtr;
     }
     cout << "Index out of range." << endl;
     exit(EXIT_FAILURE);
 }
 
 #endif /* LINKEDLIST_H */
 