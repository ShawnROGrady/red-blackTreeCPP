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
#include "red-blackNode.hpp"

//test function:
void printInorder(redBlackNode *root){
    if(root==NULL){
        return;
    }
    else{
        printInorder(root->getLeftChild());
        std::cout<<root->getValue();
        std::cout<<std::endl;
        printInorder(root->getRightChild());
    }
}
int main(int argc, const char * argv[]) {
    redBlackNode *node1=new redBlackNode(4);
    redBlackNode *node2=new redBlackNode(2);
    redBlackNode *node3=new redBlackNode(1);
    redBlackNode *node4=new redBlackNode(3);
    node1->setLeftChild(node2);
    node2->setParent(node1);
    node2->setLeftChild(node3);
    node3->setParent(node2);
    node2->setRightChild(node4);
    node4->setParent(node2);
    
    printInorder(node1);  //1 2 3 4
    return 0;
}
