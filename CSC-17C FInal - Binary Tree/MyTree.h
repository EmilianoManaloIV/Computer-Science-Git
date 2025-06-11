#ifndef MYTREE_H
#define MYTREE_H

// Include other needed classes
#include "AVLTree.h"
#include <cstdlib>
#include <ctime>
using namespace std;

class MyTree {
private:
  AVLTree AVLTree;

public:
  MyTree();         // Done
  MyTree(int);      // Done
  void insert(int); // Done
  void remove(int); // Done
  void balance();   // Done
  void print();     // Done
  void fill(int);   // Done
  int countNodes() { return AVLTree.countNodes(AVLTree.root); }
  int getHeight();
};

MyTree::MyTree() {
  // Doesn't do anything and just exists
}
MyTree::MyTree(int numberOfElements) { fill(numberOfElements); }
void MyTree::fill(int N) {
  srand(time(0));
  for (int i = 0; i < N; i++) {
    int insertVal =
        rand() % 100 + 1; // Generates a random number between 1 and 100
    AVLTree.root = AVLTree.insert(AVLTree.root, insertVal);
  }
}
void MyTree::remove(int key) { AVLTree.deleteBNT(AVLTree.root, key); }

void MyTree::insert(int key) {
  AVLTree.root = AVLTree.insert(AVLTree.root, key);
}
void MyTree::balance() { AVLTree.root = AVLTree.balance(AVLTree.root); }
void MyTree::print() {
  cout << "Tree Structure:" << endl;
  AVLTree.display(AVLTree.root, AVLTree.height(AVLTree.root));
}
int MyTree::getHeight() { return AVLTree.height(AVLTree.root); }

#endif /* MYTREE_H */