#pragma once
#include "TreeNode.h"

class BinaryTree
{
public:
	BinaryTree() { m_pRoot = nullptr; }
	~BinaryTree();

	bool isEmpty() const;
	void insert(int a_nValue);
	void remove(int a_nValue);

	TreeNode* find(int a_nValue);

	void draw(TreeNode* selected);

private:
	bool findNode(int a_nSearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent);

	void draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected = nullptr);

	//The root node of the tree
	TreeNode* m_pRoot;	
};

