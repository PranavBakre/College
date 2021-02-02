#pragma once
#include "Node.h"
#include "Queue.h"
#include "Stack.h"
class Graph
{
	int n;
	Node* Users[max];
public:
	Graph();
	void CreateAL();
	bool Friend_Exists(int, string);
	int Account_Exists(string);
	void displayF(int );
	void displayALL();
	void BFS();
	void DFSNR();
	void DFSR();
	void DFSR(bool[],int);
};

