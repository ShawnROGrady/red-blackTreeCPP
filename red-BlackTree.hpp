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

//Insert
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
    checkInsert(newNode);   //recolor and/or rotate if neccessary
    
}
void redBlackTree::checkInsert(redBlackNode *newNode){
    //this function checks if recoloring or rotation needs to occur for an insertion
    if(root==newNode){
        newNode->setBlack(true);    //root is black (rule 2)
    }
    redBlackNode *parent=newNode->getParent();
    if((!parent->getBlack())||newNode!=root){
        //if newNode's parent is not black or x is not root
        redBlackNode *grandparent=newNode->getGrandParent();
        redBlackNode *uncle=newNode->getUncle();
        if(!uncle->getBlack()){
            //newNode's uncle is red, need to recolor
            parent->setBlack(true);
            uncle->setBlack(true);
            grandparent->setBlack(false);
            //swap newNode and newNode's grandparent
            int newNodeValue=newNode->getValue();
            newNode->setValue(grandparent->getValue());
            grandparent->setValue(newNodeValue);
            //repeat
            checkInsert(grandparent);
        }
        else{
            //newNode's uncle is black, four cases to consider
        }
    }
}

//Traverse+Print Algorithms
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
