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
    tree->insertNode(10);
    tree->insertNode(20);
    tree->insertNode(30);
    //std::cout<<tree->getRoot()->getValue();
    tree->insertNode(15);
    //tree->traverseAndPrintInorder(tree->getRoot()); // 10 15 20 30
    tree->traverseAndPrintPreorder(tree->getRoot()); // 20 10 15 30
    //tree->traverseAndPrintPostorder(tree->getRoot()); // 30 15 10 20
    return 0;
}
