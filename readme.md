Binary-Tree 
Matthew Ragas
s178023
Binary tree documentation

##I. Requirements

1. Description of Problem
  -**Name**: Binary Tree
  
  -**Problem Statement**:
  Creation of a binary tree in C++ language
  
  -**Problem Specifications**: 
  Binary tree must include functions for inserting a new value, finding a value, and removing a value from the tree.
 
2. Output Information
-The program displays numbers in  abinary tree format to the user.
  
  
## II. Design

1. _systemArchitecture_

Game Loop

While window should not close, continue to draw the binary tree.

2. ###Object Information

  **File**:TreeNode.h
  
  Description: Class used to define the node of the tree

  **Attributes**
  
    Name: m_value
    Description: variable used to hold the value of a node
    Type: int
    Protection Level: private
    
    Name: m_left
    Description: pointer variable used to hold the value of the node's children
    Type: TreeNode*
    Protection Level: Private
    
    
    Name: m_right
    Description: pointer variable used to hold the value of the node's children
    Type: TreeNode*
    Protection Level: Private
    
  **Operations**
  
    Name: TreeNode
    Description: Default constructor for TreeNode
    Paramaters: int value
    Protection Level: public
    
    Name: ~TreeNode
    Description: Deconstructor for TreeNode
    Protection Level: public
    
    Name: hasLeft
    Description: Returns wether there is a left child
    Type: bool
    Protection Level: public
    
    Name: hasRight
    Description: Returns wether there is a right child
    Type: bool
    Protection Level: public
    
    Name: getData
    Description: Returns the value of the node
    Type: int
    Protection Level: public    
    
    Name: getLeft
    Description: Returns the value of the left child
    Type: TreeNode*
    Protection Level: public
    
    Name: getRight
    Description: Returns the value of the right child
    Type: TreeNode*
    Protection Level: public
    
    Name: setData
    Description: set the value of the node
    Type: void
    Paramaters: int value
    Protection Level: public
    
    name: setLeft
    Description: set the value of the left child
    Type: void
    Paramaters: TreeNode* node
    protection Level: public
    
    name: setRight
    Description: set the value of the right child
    Type: void
    Paramaters: TreeNode* node
    protection Level: public

## License

MIT License - Copyright (c) 2018 Academy of Interactive Entertainment

For more information, see the [license][lic] file.

Third party works are attributed under [thirdparty.md][3p].

[lic]:license.md
[3p]:thirdparty.md
[raylib]:https://github.com/raysan5/raylib
