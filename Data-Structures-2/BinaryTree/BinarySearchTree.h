#pragma once
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "BinaryTree.h"
class BinarySearchTree :
	public BinaryTree
{
	

public:
	BinarySearchTree();
	void CreateR();
	Node* CreateR(Node *,string);

	void CreateNR();
	void Search();
	Node** Search(string);
	int Delete();
};

#endif