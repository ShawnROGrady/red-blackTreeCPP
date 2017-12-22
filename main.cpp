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
    /*
    for(int i=1; i<8; i++){
        tree->insertNode(i);
    }
    //tree->traverseAndPrintInorder(tree->getRoot()); // 1 2 3 4 5 6 7
    //tree->traverseAndPrintPreorder(tree->getRoot()); // 2 1 4 3 6 5 7
    tree->traverseAndPrintPostorder(tree->getRoot()); // 1 3 5 7 6 4 2
    */
    for(int i=1; i<9; i++){
        tree->insertNode(i);
    }
    //tree->traverseAndPrintInorder(tree->getRoot()); // 1 2 3 4 5 6 7 8
    //tree->traverseAndPrintPreorder(tree->getRoot()); // 4 2 1 3 6 5 7 8
    tree->traverseAndPrintPostorder(tree->getRoot()); // 1 3 2 5 8 7 6 4
    /*
    tree->insertNode(10);
    tree->insertNode(20);
    tree->insertNode(30);
    //std::cout<<tree->getRoot()->getValue();
    tree->insertNode(15);
    //tree->traverseAndPrintInorder(tree->getRoot()); // 10 15 20 30
    tree->traverseAndPrintPreorder(tree->getRoot()); // 20 10 15 30
    //tree->traverseAndPrintPostorder(tree->getRoot()); // 30 15 10 20
     */
    return 0;
}
