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
 
 */
#include <iostream>
#include "red-BlackTree.hpp"

//test function:

int main(int argc, const char * argv[]) {
    redBlackTree *tree=new redBlackTree();
    tree->insertNode(4);
    tree->insertNode(2);
    tree->insertNode(1);
    tree->insertNode(3);
    tree->insertNode(6);
    tree->insertNode(5);
    tree->insertNode(7);
    //tree->traverseAndPrintInorder(tree->getRoot()); // 1 2 3 4 5 6 7
    //tree->traverseAndPrintPreorder(tree->getRoot()); // 4 2 1 3 6 5 7
    tree->traverseAndPrintPostorder(tree->getRoot()); // 1 3 2 5 7 6 4
    return 0;
}
