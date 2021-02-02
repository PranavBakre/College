#pragma once
#ifndef NODE_H
#define NODE_H

#include<iostream>
using namespace std;
//Max size for stack and circular queue
const int max = 100;
class Node
{
protected:
	string Data;
	Node* Left,*Right;

public:
	Node();
	extern friend class BinaryTree;
	extern friend class BinarySearchTree;

};

#endif