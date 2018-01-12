//
//  red-blackNode.cpp
//  RedBlackTree
//
//  Created by Shawn O'Grady on 12/21/17.
//  Copyright © 2017 Shawn O'Grady. All rights reserved.
//

#include "red-blackNode.hpp"

//constructors
redBlackNode::redBlackNode(){
    //default
    value=NULL;
    parent=NULL;
    leftChild=NULL;
    rightChild=NULL;
    black=true;
    doubleBlack=false;
    isNULL=true;
}
redBlackNode::redBlackNode(int v){
    value=v;
    black=false; //I am making each node red by default
    doubleBlack=false;
    parent=NULL;
    isNULL=false;
    /*
    leftChild=NULL;
    rightChild=NULL;
    */
    
    leftChild=new redBlackNode;
    rightChild=new redBlackNode;
     
    
}

//setters:
void redBlackNode::setValue(int v){
    value=v;
}
void redBlackNode::setBlack(bool b){
    black=b;
}
void redBlackNode::setDoubleBlack(bool b){
    doubleBlack=b;
}
void redBlackNode::setNULL(bool b){
    isNULL=b;
}
void redBlackNode::setParent(redBlackNode *newParent){
    parent=newParent;
}
void redBlackNode::setLeftChild(redBlackNode *newLeftChild){
    leftChild=newLeftChild;
}
void redBlackNode::setRightChild(redBlackNode *newRightChild){
    rightChild=newRightChild;
}
//getters:
int redBlackNode::getValue(){
    return value;
}
bool redBlackNode::getBlack(){
    return black;
}
bool redBlackNode::getDoubleBlack(){
    return doubleBlack;
}
bool redBlackNode::getNULL(){
    return isNULL;
}
redBlackNode* redBlackNode::getParent(){
    return parent;
}
redBlackNode* redBlackNode::getLeftChild(){
    return leftChild;
}
redBlackNode* redBlackNode::getRightChild(){
    return rightChild;
}
redBlackNode* redBlackNode::getGrandParent(){
    redBlackNode *grandparent=parent->getParent();
    return grandparent;
}
redBlackNode* redBlackNode::getUncle(){
    redBlackNode *grandparent=getGrandParent();
    redBlackNode *uncle;
    if(grandparent->getValue()>value){
        //current node is left of grandparent, so uncle is grandparents left child
        uncle=grandparent->getRightChild();
    }
    else{
        //current node is right of grandparent, so uncle is grandparents right child
        uncle=grandparent->getLeftChild();
    }
    return uncle;
}
redBlackNode* redBlackNode::getSibling(){
    if(parent->getValue()>value){
        //current node is left child
        return parent->getRightChild();
    }
    else{
        //current node is right child
        return parent->getLeftChild();
    }
}
