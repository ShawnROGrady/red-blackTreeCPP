# red-blackTreeCPP
Implementation of a red-black tree in C++

In order to maintain my proficiency in C++, I have decided to try implementing data structures that weren't covered in my undergraduate courses. 

The first of these is the red-black tree, which is very similar to a regular binary search tree but each node in the tree has an additional bit. This extra bit allows for the tree to be close to self-balancing, which reduces the worst-case time complexity for [standard operations](http://bigocheatsheet.com/).

For the time being, I am only considering the case where all values in the tree are **integers**. 

My end goal is to implement a binary search tree that takes user input to perform the following five functions:
  1. insert a value to the tree
  2. remove a value from the tree
  3. print the entire tree (inorder, preorder, or postorder)
  4. search the tree for a specified value
  5. close the program
