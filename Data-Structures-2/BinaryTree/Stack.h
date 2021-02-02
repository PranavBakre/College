#pragma once
#ifndef STACK_H
#define STACK_H
#include<iostream>
#include"Node.h"

using namespace std;



class Stack {
	Node* Data[max];
	int Top;
public:
	Stack();
	void Push(Node* temp);
	Node* Pop();
	Node* RetTop();

	int Empty();
	int Full();
};

#endif
