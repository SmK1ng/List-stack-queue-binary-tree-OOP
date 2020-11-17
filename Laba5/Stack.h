#pragma once

using namespace std;

struct Node {
	int data;
	Node* next;
};

class Stack
{
	Node* top;

public:

	Stack();
	~Stack();

	void push(int);
	void pop();
	bool isEmpty();
	void ShowTop();
};

