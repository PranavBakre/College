#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include"Node.h"


class Queue
{
	Node* Data[max];
	int Front, Rear;

public:
	Queue();
	void Enqueue(Node*);
	Node* Dequeue();
	int Empty();
	int Full();
};

#endif