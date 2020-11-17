#include "Queue.h"

#include<iostream>

using namespace std;

Queue::Queue() { front = rear = NULL; }

Queue::~Queue() {
	while (front != NULL) {
		NodeQ* temp = front;
		front = front->next;
		delete temp;
	}
	rear = NULL;
}

void Queue::insert(int n) {
	NodeQ* temp = new NodeQ;

	if (temp == NULL) {
		cout << "Overflow" << endl;
		return;
	}
	
	temp->data = n;
	temp->next = NULL;

	if (front == NULL)
		front = rear = temp;
	else {
		rear->next = temp;
		rear = temp;
	}
}

void Queue::display() {
	if (front == NULL) {
		cout << "Underflow" << endl;
		return;
	}
	NodeQ* temp = front;

	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void Queue::deleteItem() {
	if (front == NULL) {
		cout << "Underflow" << endl;
		return;
	}

	if (front == rear)
		front = rear = NULL;
	else
		front = front->next;
}