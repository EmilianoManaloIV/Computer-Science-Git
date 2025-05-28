#ifndef MYTREE_H
#define	MYTREE_H

//Include other needed classes
#include "AVLTree.h"

class MyTree
{
    private:
    AVLTree AVLTree;

    public:
    MyTree();
    MyTree(int);
    void insert(int);
    void remove(int);
    void balance();
    void print();
    void fill(int);
}

MyTree::MyTree()
{
    //Doesn't do anything and just exists
}
MyTree::MyTree(int numberOfElements)
{

}

#endif	/* BNTNODE_H */