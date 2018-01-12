//
//  red-blackNode.hpp
//  RedBlackTree
//
//  Created by Shawn O'Grady on 12/21/17.
//  Copyright © 2017 Shawn O'Grady. All rights reserved.
//

#ifndef red_blackNode_hpp
#define red_blackNode_hpp

#include <stdio.h>
class redBlackNode{
private:
    int value;
    bool black;
    bool doubleBlack;
    redBlackNode *parent;
    redBlackNode *leftChild;
    redBlackNode *rightChild;
public:
    //constructors
    redBlackNode(); //default
    redBlackNode(int v);
    //setters:
    void setValue(int v);
    void setBlack(bool b);
    void setDoubleBlack(bool b);
    void setParent(redBlackNode *newParent);
    void setLeftChild(redBlackNode *newLeftChild);
    void setRightChild(redBlackNode *newRightChild);
    //getters
    int getValue();
    bool getBlack();
    bool getDoubleBlack();
    redBlackNode* getParent();
    redBlackNode* getLeftChild();
    redBlackNode* getRightChild();
    redBlackNode* getGrandParent();
    redBlackNode* getUncle();
    redBlackNode* getSibling();
};
#endif /* red_blackNode_hpp */
