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
public:
    redBlackTree();
    bool isEmpty();
    redBlackNode *getRoot();
    void insertNode(int newEntry);
    void removeNode(redBlackNode* target);
    void traverseAndPrintInorder(redBlackNode *root);
    void traverseAndPrintPreorder(redBlackNode *root);
    void traverseAndPrintPostorder(redBlackNode *root);
};
#endif /* red_BlackTree_hpp */
