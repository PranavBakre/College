#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include"Node.h"
class BinaryTree
{
protected:
	Node* Root;
public:
	BinaryTree();
	void CreateNR();
	void PreorderNR() const;
	void InorderNR() const;
	void PostorderNR()const;

	void CreateR();
	Node *CreateR(Node*);
	void PreorderR() const;
	void PreorderR(Node*) const;
	void InorderR() const;
	void InorderR(Node*) const;
	void PostorderR() const;
	void PostorderR(Node*) const;
	int Erase();
	int Erase(Node*);
	void Height();
	int Height(Node*);

	void Bfs();
};

#endif