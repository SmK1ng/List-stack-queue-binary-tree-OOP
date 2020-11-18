#include "Queue1.h"

void Queue1::insert(int n) {
	data.AddTail(n);
}

void Queue1::deleteItem() {
	data.Del(1);
}

void Queue1::display() {
	data.Print();
}