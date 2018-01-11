//
//  red-BlackTree.hpp
//  RedBlackTree
//
//  Created by Shawn O'Grady on 12/21/17.
//  Copyright © 2017 Shawn O'Grady. All rights reserved.
//

#ifndef red_BlackTree_hpp
#define red_BlackTree_hpp

#include <stdio.h>
#include "red-blackNode.hpp"
class redBlackTree{
private:
    redBlackNode *root;
    int blackHeight;
protected:
    void checkInsert(redBlackNode* newNode);
    void checkRemove(redBlackNode* target, redBlackNode* replacement);
    void leftRotate(redBlackNode* pivot, redBlackNode* parent);
    void rightRotate(redBlackNode* pivot, redBlackNode* parent);
    void leftLeftCase(redBlackNode*grandparent, redBlackNode*parent);
    void rightRightCase(redBlackNode*grandparent, redBlackNode*parent);
    void removeNoChild(redBlackNode* target, redBlackNode*parent);
    void removeLeftChild(redBlackNode* target, redBlackNode*parent);
    void removeRightChild(redBlackNode* target, redBlackNode* parent);
    void removeTwoChild(redBlackNode* target, redBlackNode* rightTreeMin);
    redBlackNode* findSubtreeMin(redBlackNode* subTreeRoot);
public:
    redBlackTree();
    bool isEmpty();
    redBlackNode *getRoot();
    void insertNode(int newEntry);
    void removeNode(int target);
    void traverseAndPrintInorder(redBlackNode *root);
    void traverseAndPrintPreorder(redBlackNode *root);
    void traverseAndPrintPostorder(redBlackNode *root);
    redBlackNode * findNode(int target);
};
#endif /* red_BlackTree_hpp */
