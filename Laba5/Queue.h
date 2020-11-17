#pragma once

struct NodeQ {
	int data;
	NodeQ* next;
};

class Queue
{
public:
	NodeQ* front, * rear;
	
	Queue();
	~Queue();

	void insert(int);
	void deleteItem();
	void display();
};

