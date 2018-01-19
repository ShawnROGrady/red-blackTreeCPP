//
//  main.cpp
//  RedBlackTree
//
//  Created by Shawn O'Grady on 12/21/17.
//  Copyright © 2017 Shawn O'Grady. All rights reserved.
//
/*
 For now the main function is just responsible for testing
    -later will be taking user input
 reference: http://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/
 reference: https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
 */
#include <iostream>
#include "red-BlackTree.hpp"

//test function:

int main(int argc, const char * argv[]) {
    redBlackTree *tree=new redBlackTree();
    /*
     Cases to test for when inserting a node:
        1. new node is root
        2. new node's parent is red
            a) new nodes uncle is red
            b) new node's uncle is black
                i) new node is left child to parent and parent is left child to grandparent (left-left)
                ii) new node is right child to parent and parent is left child to grandparent (left-right)
                iii) new node is right child to parent and parent is right child to grandparent (right-right)
                iv) new node is left child to parent and parent is right child to grandparent (right-left)
     */
    /*
    //Case 1:
    tree->insertNode(2);
    tree->traverseAndPrintPreorder(tree->getRoot()); //2 black
     */
    /*
    //Case 2.a:
    tree->insertNode(2);
    tree->insertNode(1);
    tree->insertNode(3);
    //tree->traverseAndPrintPreorder(tree->getRoot()); //2 black, 1 red, 3 red
    tree->insertNode(4);
    tree->traverseAndPrintPreorder(tree->getRoot()); //2 black, 1 black, 3 black, 4 red
     */
    /*
    //Case 2.b.i:
    for(int i=4; i>0; i--){
        tree->insertNode(i);
    }
    //tree->traverseAndPrintPreorder(tree->getRoot());    //3 black, 2 black, 1 red, 4 black
    tree->insertNode(0);
    tree->traverseAndPrintPreorder(tree->getRoot());    //3 black, 1 black, 0 red, 2 red, 4 black
     */
    /*
    //Case 2.b.ii:
    tree->insertNode(6);
    tree->insertNode(4);
    //tree->traverseAndPrintPreorder(tree->getRoot()); //6 black, 4 red
    tree->insertNode(5);
    tree->traverseAndPrintPreorder(tree->getRoot()); //5 black, 4 red, 6 red
     */
    /*
    //Case 2.b.iii:
    tree->insertNode(1);
    tree->insertNode(2);
    tree->insertNode(3);
    tree->insertNode(4);
    //tree->traverseAndPrintPreorder(tree->getRoot());    // 2 black, 1 black, 3 black, 4 red
    tree->insertNode(5);
    tree->traverseAndPrintPreorder(tree->getRoot()); //2 black, 1 black, 4 black, 3 red, 5 red
     */
    //Case 2.b.iv:
    tree->insertNode(4);
    tree->insertNode(6);
    //tree->traverseAndPrintPreorder(tree->getRoot()); //4 black, 6 red
    tree->insertNode(5);
    tree->traverseAndPrintPreorder(tree->getRoot()); //5 black, 4 red, 6 red
    /*
     Cases to test for when removing node:
        1. replacement or target is red
        2. replacement and target both black
            a) sibling is black and one of sibling's children is red
                i) sibling is left child to parent and siblings red child is the left child
                ii) sibling is left child to parent and siblings red child is the right child
                iii) sibling is right child to parent and siblings red child is the right child
                iv) sibling is right child to parent and siblings red child is the left child
            b) sibling is black and both of siblings children are black
            c)sibling is red
                i) sibling is left child to parent
                ii) sibling is right child to parent
     Got help coming up with test cases from: https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/
     */
    /*
    //Case 1:
    tree->insertNode(30);
    tree->insertNode(20);
    tree->insertNode(40);
    tree->insertNode(10);
    //tree->traverseAndPrintPreorder(tree->getRoot());    //30 black, 20 black, 10 red, 40 black
    tree->removeNode(20);
    tree->traverseAndPrintPreorder(tree->getRoot());    //30 black, 10 black, 40 black
     */
    /*
    //Case 2.a.i:
    tree->insertNode(30);
    tree->insertNode(20);
    tree->insertNode(40);
    tree->insertNode(10);
    tree->insertNode(25);
    //tree->traverseAndPrintPreorder(tree->getRoot());    //30 black, 20 black, 10 red, 25 red, 40 black
    tree->removeNode(40);
    tree->traverseAndPrintPreorder(tree->getRoot());    //20 black, 10 black, 30 black, 25 red
     */
    /*
    //Case 2.a.ii:
    tree->insertNode(30);
    tree->insertNode(20);
    tree->insertNode(40);
    tree->insertNode(25);
    //tree->traverseAndPrintPreorder(tree->getRoot());    //30 black, 20 black, 25 red, 40 black
    tree->removeNode(40);
    tree->traverseAndPrintPreorder(tree->getRoot());    //25 black, 20 black, 30 black
     */
    /*
    //Case 2.a.iii:
    tree->insertNode(30);
    tree->insertNode(20);
    tree->insertNode(40);
    tree->insertNode(35);
    tree->insertNode(50);
    //tree->traverseAndPrintPreorder(tree->getRoot());    //30 black, 20 black, 40 black, 35 red, 50 red
    tree->removeNode(20);
    tree->traverseAndPrintPreorder(tree->getRoot());    //40 black, 30 black, 35 red, 50 black
    */
    /*
    //Case 2.a.iv:
    tree->insertNode(30);
    tree->insertNode(20);
    tree->insertNode(40);
    tree->insertNode(35);
    //tree->traverseAndPrintPreorder(tree->getRoot());    //30 black, 20 black, 40 black, 35 red
    tree->removeNode(20);
    tree->traverseAndPrintPreorder(tree->getRoot());    //35 black, 30 black, 40 black
    */
    /*
    //Case 2.b:
    for(int i=1; i<11; i++){
        tree->insertNode(i);
    }
    //tree->traverseAndPrintPreorder(tree->getRoot()); //4 black, 2 black, 1 black, 3 black, 6 black, 5 black, 8 red, 7 black, 9 black, 10 red
    tree->removeNode(1);
    tree->traverseAndPrintPreorder(tree->getRoot()); //6 black, 4 black, 2 blCK, 3 red, 5 black, 8 black, 7 black, 9 black, 10 black
    */
    /*
    //Case 2.c.i:
    for(int i=10; i>0; i--){
        tree->insertNode(i);
    }
    //tree->traverseAndPrintPreorder(tree->getRoot()); //7 black, 5 black, 3 red, 2 black, 1 red, 4 black, 6 black, 9 black, 8 black, 10 black
    tree->removeNode(6);
    tree->traverseAndPrintPreorder(tree->getRoot()); //7 black, 3 black, 2 black, 1 red, 5 black, 4 red, 9 black, 8 black, 10 black
     */
    /*
    //Case 2.c.ii:
    for(int i=1; i<11; i++){
        tree->insertNode(i);
    }
    //tree->traverseAndPrintPreorder(tree->getRoot()); //4 black, 2 black, 1 black, 3 black, 6 black, 5 black, 8 red, 7 black, 9 black, 10 red
    tree->removeNode(5);
    tree->traverseAndPrintPreorder(tree->getRoot()); //4 black, 2 black, 1 black, 3 black, 8 black, 6 black, 7 red, 9 black, 10 red
     */
    return 0;
}
