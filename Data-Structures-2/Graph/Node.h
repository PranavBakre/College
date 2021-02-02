#pragma once
#include<iostream>
using namespace std;
class Node
{
	string name;
	Node* friends;

public:
	friend class Graph;
	Node (): name(""),friends(nullptr){}
};

const int max = 100;

