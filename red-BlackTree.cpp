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
 +I currently believe I can:
    -Insert a value
    -search the tree
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
    if(parent!=NULL){
        if((!parent->getBlack())||newNode!=root){
            //if newNode's parent is not black or x is not root
            redBlackNode *grandparent=newNode->getGrandParent();
            if(grandparent!=NULL){
                redBlackNode *uncle=newNode->getUncle();
                if(uncle!=NULL){
                    if(!uncle->getBlack()){
                        //newNode's uncle is red, need to recolor
                        parent->setBlack(true);
                        uncle->setBlack(true);
                        grandparent->setBlack(false);
                        /*
                        //swap newNode and newNode's grandparent
                        int newNodeValue=newNode->getValue();
                        newNode->setValue(grandparent->getValue());
                        grandparent->setValue(newNodeValue);
                         */
                        //repeat
                        checkInsert(grandparent);
                    }
                    else{
                        //newNode's uncle is black, four cases to consider
                        if(grandparent->getLeftChild()==parent){
                            if(parent->getLeftChild()==newNode){
                                //left-left case
                                leftLeftCase(grandparent, parent);
                            }
                            else if(parent->getRightChild()==newNode){
                                //left-right case
                                leftRotate(newNode, parent);
                                leftLeftCase(grandparent, parent);
                            }
                        }
                        else if(grandparent->getRightChild()==parent){
                            if(parent->getRightChild()==newNode){
                                //right-right case
                                rightRightCase(grandparent, parent);
                            }
                            else if(parent->getLeftChild()==newNode){
                                //right-left case
                                rightRotate(newNode, parent);
                                rightRightCase(grandparent, parent);
                            }
                        }
                    }
                }
                else{
                    //newNode's uncle is null, which is considered black
                    if(grandparent->getLeftChild()==parent){
                        if(parent->getLeftChild()==newNode){
                            //left-left case
                            leftLeftCase(grandparent, parent);
                        }
                        else if(parent->getRightChild()==newNode){
                            //left-right case
                            leftRotate(newNode, parent);
                            leftLeftCase(grandparent, parent);
                        }
                    }
                    else if(grandparent->getRightChild()==parent){
                        if(parent->getRightChild()==newNode){
                            //right-right case
                            rightRightCase(grandparent, parent);
                        }
                        else if(parent->getLeftChild()==newNode){
                            //right-left case
                            rightRotate(newNode, parent);
                            rightRightCase(grandparent, parent);
                        }
                    }
                }
            }
        }
    }
}
void redBlackTree::leftRotate(redBlackNode *pivot, redBlackNode *parent){
    //changes pivot from parent's rightChild to the new parent
    if(root==parent){
        root=pivot;
    }
    pivot->setParent(parent->getParent());
    if(parent->getParent()!=NULL){
        (parent->getParent())->setRightChild(pivot);
    }
    parent->setRightChild(pivot->getLeftChild());
    if(pivot->getLeftChild()!=NULL){
        (pivot->getLeftChild())->setParent(parent);
    }
    pivot->setLeftChild(parent);
    parent->setParent(pivot);
}
void redBlackTree::rightRotate(redBlackNode *pivot, redBlackNode *parent){
    //changes pivot from parent's leftChild to the new parent
    if(root==parent){
        root=pivot;
    }
    pivot->setParent(parent->getParent());
    if(parent->getParent()!=NULL){
        (parent->getParent())->setLeftChild(pivot);
    }
    parent->setLeftChild(pivot->getRightChild());
    if(pivot->getRightChild()!=NULL){
        (pivot->getRightChild())->setParent(parent);
    }
    pivot->setRightChild(parent);
    parent->setParent(pivot);
}
void redBlackTree::leftLeftCase(redBlackNode *grandparent, redBlackNode *parent){
    rightRotate(parent, grandparent);
    //swap colors of parent and granparent
    if (parent->getBlack()){
        parent->setBlack(false);
        grandparent->setBlack(true);
    }else{
        parent->setBlack(true);
        grandparent->setBlack(false);
    }
}
void redBlackTree::rightRightCase(redBlackNode *grandparent, redBlackNode *parent){
    leftRotate(parent, grandparent);
    //swap colors of parent and granparent
    if (parent->getBlack()){
        parent->setBlack(false);
        grandparent->setBlack(true);
    }else{
        parent->setBlack(true);
        grandparent->setBlack(false);
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

redBlackNode* redBlackTree::findNode(int target){
    redBlackNode *tmp=root;
    while(tmp!=NULL){
        if(target<tmp->getValue()){
            tmp=tmp->getLeftChild();
        }
        else if(target>tmp->getValue()){
            tmp=tmp->getRightChild();
        }
        else{
            return tmp;
        }
    }
    return NULL;    //if we get here target is not in tree
}

redBlackNode* redBlackTree::findSubtreeMin(redBlackNode *subTreeRoot){
    while(subTreeRoot->getLeftChild()!=NULL){
        subTreeRoot=subTreeRoot->getLeftChild();
    }
    return subTreeRoot;
}

void redBlackTree::removeNode(int target){
    redBlackNode *targetNode=findNode(target);
    if(targetNode==NULL){
        //not in tree
        return;
    }
    else{
        redBlackNode *parent=targetNode->getParent();
        //Three cases to consider
        if(targetNode->getLeftChild()==NULL&&targetNode->getRightChild()==NULL){
            //Case 1: No child
            removeNoChild(targetNode, parent);
        }
        else if(targetNode->getLeftChild()!=NULL&&targetNode->getRightChild()==NULL){
            //Case 2(a): only left childe
            removeLeftChild(targetNode, parent);
        }
        else if(targetNode->getLeftChild()==NULL&&targetNode->getRightChild()!=NULL){
            //Case 2(b):only right child
            removeRightChild(targetNode, parent);
        }
        else{
            //Case 3: two children
            redBlackNode *subTreeMin=findSubtreeMin(targetNode->getRightChild());
            removeTwoChild(targetNode, subTreeMin);
        }
    }
}
void redBlackTree::removeNoChild(redBlackNode *target, redBlackNode *parent){
    if(target->getValue()<parent->getValue()){
        //target node is left child
        parent->setLeftChild(NULL);
    }
    else{
        //target node is right child
        parent->setRightChild(NULL);
    }
    //delete target;
    //target=NULL;
}
void redBlackTree::removeLeftChild(redBlackNode *target, redBlackNode *parent){
    if(target->getValue()<parent->getValue()){
        //target node is left child
        parent->setLeftChild(target->getLeftChild());
        (target->getLeftChild())->setParent(parent);
        if(target==root){
            //readjust root pointer if deleting root
            root=target->getLeftChild();
        }
    }
    else{
        //target node is right child
        parent->setRightChild(target->getLeftChild());
        (target->getLeftChild())->setParent(parent);
        if(target==root){
            //readjust root pointer if deleting root
            root=target->getLeftChild();
        }
    }
    //delete target;
    //target=NULL;
}
void redBlackTree::removeRightChild(redBlackNode *target, redBlackNode *parent){
    if(target->getValue()<parent->getValue()){
        //target node is left child
        parent->setLeftChild(target->getRightChild());
        (target->getRightChild())->setParent(parent);
        if(target==root){
            //readjust root pointer if deleting root
            root=target->getRightChild();
        }
    }
    else{
        //target node is right child
        parent->setRightChild(target->getRightChild());
        (target->getRightChild())->setParent(parent);
        if(target==root){
            //readjust root pointer if deleting root
            root=target->getRightChild();
        }
    }
    //delete target;
    //target=NULL;
}
void redBlackTree::removeTwoChild(redBlackNode *target, redBlackNode *rightTreeMin){
    //int targetValue=target->getValue();
    target->setValue(rightTreeMin->getValue());
    if(rightTreeMin->getRightChild()==NULL){
        removeNoChild(rightTreeMin, rightTreeMin->getParent());
    }
    else{
        removeRightChild(rightTreeMin, rightTreeMin->getParent());
    }
}

