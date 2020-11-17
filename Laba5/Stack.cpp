#include "Stack.h"

#include <iostream>

using namespace std;

Stack::Stack() {
	top = NULL;
}

Stack::~Stack() {
	delete[] top;
}

void Stack::push(int value) {
	Node* ptr = new Node();
	//cout << "Enter value" << endl;
	//cin >> value;

	ptr->data = value;
	ptr->next = top;
	top = ptr;
}

bool Stack::isEmpty() {
	if (top == NULL)
		return true;
	else
		return false;
}

void Stack::pop() {
	if (isEmpty()) {
		cout << "Stack is empty" << endl;
	}
	else {
		struct Node* temp = top;
		top = top->next;
		delete(temp);
	}
}

void Stack::ShowTop() {
	if (isEmpty()) {
		cout << "Stack is empty" << endl;
	}
	else {
		cout << top->data << endl;
	}
}