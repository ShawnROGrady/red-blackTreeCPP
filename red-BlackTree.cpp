//
//  red-BlackTree.cpp
//  RedBlackTree
//
//  Created by Shawn O'Grady on 12/21/17.
//  Copyright © 2017 Shawn O'Grady. All rights reserved.
//
/*
 For a red-black tree, every node follows the following rules (along w/ standard BST rules):
    1. Every node has a color (red or black)
    2. Root of the tree is always black
    3. There ar no two adjacent red nodes
        -i.e. a red node can't have a red parent or a red child
    4. Every path from root to a NULL node has same number of black nodes
*/
#include <iostream>
#include "red-BlackTree.hpp"

redBlackTree::redBlackTree(){
    root=NULL;
    blackHeight=0;
}

redBlackNode *redBlackTree::getRoot(){
    return root;
}

void redBlackTree::insertNode(int newEntry){
    redBlackNode *newNode=new redBlackNode(newEntry);
    redBlackNode *tmp=root;
    redBlackNode *parent=nullptr;
    while(tmp!=NULL){
        parent=tmp;
        if(newNode->getValue()<tmp->getValue()){
            tmp=tmp->getLeftChild();
        }else{
            tmp=tmp->getRightChild();
        }
    }
    if(parent==NULL){
        //tree is empty
        newNode->setBlack(true);    //root is black (rule 2)
        blackHeight++;
        root=newNode;
    }
    else if (newNode->getValue()<parent->getValue()){
        parent->setLeftChild(newNode);
        newNode->setParent(parent);
    }
    else{
        parent->setRightChild(newNode);
        newNode->setParent(parent);
    }
}
void redBlackTree::traverseAndPrintInorder(redBlackNode *root){
    if(root==NULL){
        return;
    }
    else{
        traverseAndPrintInorder(root->getLeftChild());
        std::cout<<root->getValue();
        std::cout<<std::endl;
        traverseAndPrintInorder(root->getRightChild());
    }
}
void redBlackTree::traverseAndPrintPreorder(redBlackNode *root){
    if(root==NULL){
        return;
    }
    else{
        std::cout<<root->getValue();
        std::cout<<std::endl;
        traverseAndPrintPreorder(root->getLeftChild());
        traverseAndPrintPreorder(root->getRightChild());
    }
}
void redBlackTree::traverseAndPrintPostorder(redBlackNode *root){
    if(root==NULL){
        return;
    }
    else{
        traverseAndPrintPostorder(root->getLeftChild());
        traverseAndPrintPostorder(root->getRightChild());
        std::cout<<root->getValue();
        std::cout<<std::endl;
    }
}
