#include "BinaryTree.h"
#include "raylib.h"

BinaryTree::~BinaryTree()
{
}

bool BinaryTree::isEmpty() const
{
	//Return true if the root is null
	return false;
}

void BinaryTree::insert(int a_nValue)
{
	//If the tree is empty, the value is inserted at the root of  the tree
	if (m_pRoot == nullptr)
	{
		m_pRoot->setData(a_nValue);
	}
	//Set the current node to the root
	TreeNode* currentNode = m_pRoot;
	TreeNode* parent;
	//While the current node is not null
	while (currentNode != nullptr)
	{
		//If the value to be inserted is less than the value in the current node
			//Set the curreent node to the left child and continue
		if (a_nValue < currentNode->getData)
		{
			//assign parent root			
			parent = currentNode;
			//assign current node
			currentNode = currentNode->getLeft;
		}
		//If the value to be inserted is greater than the current node
			//Set the current node to the right child and continue
		else if (a_nValue > currentNode->getData)
		{
			parent = currentNode;
			currentNode = currentNode->getRight;
		}
		//If the value to be inserted is the same as the value in the current node
			//The value is already in the tree, so exit
		else if (a_nValue == currentNode->getData)
		{
			break;
		}
	}				
	//End while

	//Get the parent of the current node(before it was set to null)
	
	//If value to be inserted is less than parent
		//Insert value as left child node
	if (a_nValue < parent->getData)
	{
		parent->getLeft = a_nValue;
	}
	//Otherwise insert value as right child node
	else
	{
		parent->getRight = a_nValue;
	}
}

void BinaryTree::remove(int a_nValue)
{
	//Find the value in the tree, obtaining a pointer to the node and its parent
	//If the current node has a right branch, then
		//Find the minimum value in the right branch by iterating down the left branch of the 
			//Current node's right child until there are no more left branch nodes
		//Copy the value from this minimum node to the current node
		//Find the minimum node's parent node (the parent of the node you are deleting)
			//If you are deleting the parent's left node
				//Set the left child of the parent to the right child of the minimum node
			//If you are deleting the parent's right node
				//Set the right child of the parent to the minimum node's right child

	//If  the current node has no right branch
		//If we are deleting the parent's left child
			//Set the left child of the parent to the left child of the current node
		//If you are deleting the parent's right node
			//Set the right child of the parent to the left child of the current node
		//If we are deleting the root
			//The root becomes the left child of the current node
}

TreeNode * BinaryTree::find(int a_nValue)
{
	return nullptr;
}

void BinaryTree::draw(TreeNode* selected)
{
	draw(m_pRoot, 640, 680, 640, selected);
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode ** ppOutNode, TreeNode ** ppOutParent)
{
	//Set the current node to the root
	//While the current node is not null
		//If the search value equals the current node and its parent
			//Return the current node and its parent
		//Otherwise
			//If the search value is less tham the current node
				//Set the current node to the left child
			//Otherwise set the current node to the right child
	//End while
	//If the loop exits, then a match was not found, so return false
	return false;
}

void BinaryTree::draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	horizontalSpacing /= 2;

	//DEPTH FIRST SEARCH
	//check to see if node exists
	if (pNode)
	{
		//check to see if left node exists
		if (pNode->hasLeft())
		{
			//draw a line to the left node
			DrawLine(x, y, x - horizontalSpacing, y - 80, RED);
			//draw the left node
			draw(pNode->getLeft(), x - horizontalSpacing, y - 80, horizontalSpacing, selected);
		}
		//check to see if right node exists
		if (pNode->hasRight())
		{
			//draw line to the right node
			DrawLine(x, y, x + horizontalSpacing, y - 80, RED);
			//draw the right node
			draw(pNode->getLeft(), x + horizontalSpacing, y - 80, horizontalSpacing, selected);
		}
		pNode->draw(x, y, (selected == pNode));
	}
}