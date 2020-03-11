#include "BinaryTree.h"
#include "raylib.h"

BinaryTree::~BinaryTree()
{
}

bool BinaryTree::isEmpty() const
{
	//Return true if the root is null
	if (m_pRoot != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}	
}

void BinaryTree::insert(int a_nValue)
{
	TreeNode* newNode = new TreeNode(a_nValue);

	//If the tree is empty, the value is inserted at the root of  the tree
	if (m_pRoot == nullptr)
	{
		m_pRoot = newNode;
		return;
	}
	//Set the current node to the root
	TreeNode* currentNode = m_pRoot;
	TreeNode* parent = nullptr;
	
	//While the current node is not null
	while (currentNode != nullptr)
	{
		//If the value to be inserted is less than the value in the current node
			//Set the curreent node to the left child and continue
		if (a_nValue < currentNode->getData())
		{
			//assign parent root			
			parent = currentNode;
			//assign current node
			currentNode = currentNode->getLeft();
		}
		//If the value to be inserted is greater than the current node
			//Set the current node to the right child and continue
		else if (a_nValue > currentNode->getData())
		{
			parent = currentNode;
			currentNode = currentNode->getRight();
		}
		//If the value to be inserted is the same as the value in the current node
			//The value is already in the tree, so exit
		else if (a_nValue == currentNode->getData())
		{
			return;
		}
	}				
	//End while

	//Get the parent of the current node(before it was set to null)
	
	//If value to be inserted is less than parent
		//Insert value as left child node
	if (a_nValue < parent->getData())
	{
		parent->setLeft(newNode);
	}
	//Otherwise insert value as right child node
	else
	{
		parent->setRight(newNode);
	}
}

void BinaryTree::remove(int a_nValue)
{
	//Find the value in the tree, obtaining a pointer to the node and its parent
	TreeNode* currentNode = nullptr;
	TreeNode* parent = nullptr;		
	if (!findNode(a_nValue, &currentNode, &parent))
	{
		return;
	}

	//If the current node has a right branch, then
	//if (m_pRoot->getRight != nullptr)
	//{
		//Find the minimum value in the right branch by iterating down the left branch of the 
			//Current node's right child until there are no more left branch nodes		
	//}
	if (currentNode->getRight() != nullptr)
	{
		TreeNode* minimum = nullptr;
		parent = currentNode;
		minimum = currentNode->getRight();

		while (minimum->getLeft() != nullptr)
		{			
			parent = minimum;
			minimum = minimum->getLeft();
		}
		//Copy the value from this minimum node to the current node
		currentNode->setData(minimum->getData());
		//If we are deleting the parent's left node
		if (minimum == parent->getLeft())
		{
			//Set the left child of the parent to the right child of the minimum node
			parent->setLeft(minimum->getRight());
			//Delete the node
			delete minimum;
		}

		//If we are deleting the parent's right node
		else if (minimum == parent->getRight())
		{
			//Set the right child of the parent to the right child of the minimum node
			parent->setRight(minimum->getRight());
			//Delete the node
			delete minimum;
		}
	}					
	//If the current node has no right branch
	else if(currentNode->getRight() == nullptr)
	{	
			//If we are deleting the parent's left child
		if (currentNode == parent->getLeft())
		{
			//Set the left child of the parent to the left child of the current node
			parent->setLeft(currentNode->getLeft());
			//Delete the node
			delete currentNode;
		}
		//If we are deleting the parent's right child
		else if (currentNode == parent->getRight())
		{
			//Set the right child of the parent to the left child of the current node
			parent->setRight(currentNode->getLeft());
			//Delete the node
			delete currentNode;
		}
		//If we are deleting the root
		else if(a_nValue == m_pRoot->getData())
		{			
			//The root becomes the left child of the current node
			m_pRoot = currentNode->getLeft();
			//Delete the node
			delete currentNode;
		}
	}
}

TreeNode * BinaryTree::find(int a_nValue)
{
	//return node with a_nValue	

	TreeNode* currentNode = nullptr;
	TreeNode* parent = nullptr;

	if (findNode(a_nValue, &currentNode, &parent))
	{		
		
		return currentNode;
	}
	return nullptr;
}

void BinaryTree::draw(TreeNode* selected)
{
	draw(m_pRoot, 640, 170, 420, selected);
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode ** ppOutNode, TreeNode ** ppOutParent)
{
	//Set the current node to the root
	TreeNode* currentNode = m_pRoot;
	TreeNode* parent = nullptr;
	//While the current node is not null
	while (currentNode != nullptr)
	{
		//If the search value equals the current node and its parent
			//Return the current node and its parent
		if (a_nSearchValue == currentNode->getData())
		{
			*ppOutParent = parent;
			*ppOutNode = currentNode;
			return true;
		}
		//If the search value is less tham the current node
				//Set the current node to the left child
		else if(a_nSearchValue < currentNode->getData())
		{
			parent = currentNode;
			currentNode = currentNode->getLeft();
		}
		//Otherwise set the current node to the right child
		else
		{
			parent = currentNode;
			currentNode = currentNode->getRight();
		}
	}
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
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			//draw the left node
			draw(pNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		//check to see if right node exists
		if (pNode->hasRight())
		{
			//draw line to the right node
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);
			//draw the right node
			draw(pNode->getRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		pNode->draw(x, y, (selected == pNode));
	}
}