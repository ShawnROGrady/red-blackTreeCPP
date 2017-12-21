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
    parent=NULL;
    leftChild=NULL;
    rightChild=NULL;
}
redBlackNode::redBlackNode(int v){
    value=v;
    parent=NULL;
    leftChild=NULL;
    rightChild=NULL;
}

//setters:
void redBlackNode::setValue(int v){
    value=v;
}
void redBlackNode::setBlack(bool b){
    black=b;
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
redBlackNode* redBlackNode::getParent(){
    return parent;
}
redBlackNode* redBlackNode::getLeftChild(){
    return leftChild;
}
redBlackNode* redBlackNode::getRightChild(){
    return rightChild;
}
