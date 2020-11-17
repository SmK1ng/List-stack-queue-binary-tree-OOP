#include "DLL.h"

DLL::DLL() {
	Head = Tail = NULL;
	Count = 0;
}

DLL::DLL(const DLL& L) {
	Head = Tail = NULL;
	Count = 0;

	Elem* temp = L.Head;

	while (temp != 0) {
		AddTail(temp->data);
		temp = temp->next;
	}
}

DLL::~DLL() {
	cout << "Delete all" << endl;
	DelAll();
}

void DLL::AddHead(int n) {
	Elem* temp = new Elem;

	temp->prev = 0;
	temp->data = n;
	temp->next = Head;

	if (Head != 0) Head->prev = temp;

	if (Count == 0) Head = Tail = temp;
	else Head = temp;

	Count++;
}

void DLL::AddTail(int n) {
	Elem* temp = new Elem;

	temp->next = 0;
	temp->data = n;
	temp->prev = Tail;

	if (Tail != 0) Tail->next = temp;

	if (Count == 0) Head = Tail = temp;
	else Tail = temp;

	Count++;
}

void DLL::Insert(int pos) {
	if (pos == 0) {
		cout << "Input position: ";
		cin >> pos;
	}

	if (pos < 1 || pos > Count + 1) {
		cout << "Incorrect position" << endl;
		return;
	}

	if (pos == Count + 1) {
		int data;
		cout << "Input new number: ";
		cin >> data;
		AddTail(data);
		return;
	}
	else if (pos == 1) {
		int data;
		cout << "Input new number: ";
		cin >> data;
		AddHead(data);
		return;
	}

	int i = 1;

	Elem* Ins = Head;

	while (i < pos) {
		Ins = Ins->next;
		i++;
	}

	Elem* PrevIns = Ins->prev;
	Elem* temp = new Elem;

	cout << "Input new number: ";
	cin >> temp->data;

	if (PrevIns != 0 && Count != 1)
		PrevIns->next = temp;

	temp->next = Ins;
	temp->prev = PrevIns;
	Ins->prev = temp;

	Count++;
}

void DLL::Del(int pos) {
	if (pos == 0) {
		cout << "Input position: ";
		cin >> pos;
	}

	if (pos < 1 || pos > Count + 1) {
		cout << "Incorrect position" << endl;
		return;
	}

	int i = 1;

	Elem* Del = Head;

	while (i < pos) {
		Del = Del->next;
		i++;
	}

	Elem* PrevDel = Del->prev;
	Elem* AfterDel = Del->next;

	if (PrevDel != 0 && Count != 1)
		PrevDel->next = AfterDel;

	if (AfterDel != 0 && Count != 1)
		AfterDel->prev = PrevDel;

	if (pos == 1) Head = AfterDel;
	if (pos == Count) Tail = PrevDel;

	delete Del;

	Count--;
}

void DLL::Print(int pos) {
	if (pos < 1 || pos > Count) {
		cout << "Incorrect position" << endl;
		return;
	}

	Elem* temp;

	if (pos <= Count / 2) {
		temp = Head;
		int i = 1;

		while (i < pos) {
			temp = temp->next;
			i++;
		}
	}
	else {
		temp = Tail;
		int i = 1;

		while (i <= Count - pos) {
			temp = temp->prev;
			i++;
		}
	}

	cout << pos << " element: ";
	cout << temp->data << endl;
}

void DLL::Print() {
	if (Count != 0) {
		Elem* temp = Head;
		cout << "(";
		while (temp->next != 0) {
			cout << temp->data << ", ";
			temp = temp->next;
		}

		cout << temp->data << " )" << endl;
	}
}

void DLL::DelAll() {
	while (Count != 0) Del(1);
}

int DLL::GetCount() {
	return Count;
}

Elem* DLL::GetElem(int pos) {
	Elem* temp = Head;

	if (pos < 1 || pos > Count) {
		cout << "Incorrect position" << endl;
		return 0;
	}

	int i = 1;

	while (i < pos && temp != 0) {
		temp = temp->next;
		i++;
	}

	if (temp == 0)
		return 0;
	else 
		return temp;
}

DLL& DLL::operator= (const DLL& L) {
	if (this == &L)
		return *this;

	this->~DLL(); //DelAll();

	Elem* temp = L.Head;

	while (temp != 0) {
		AddTail(temp->data);
		temp = temp->next;
	}
	
	return *this;
}

DLL DLL::operator+ (const DLL& L) {
	DLL Result(*this); //DLL Result = *this

	Elem* temp = L.Head;

	while (temp != 0 ) {
		Result.AddTail(temp->data);
		temp = temp->next;
	}

	return Result;
}

bool DLL::operator== (const DLL& L) {
	if (Count != L.Count)
		return false;

	Elem* t1, * t2;

	t1 = Head;
	t2 = L.Head;

	while (t1 != 0) {
		if (t1->data != t2->data)
			return false;
		t1 = t1->next;
		t2 = t2->next;
	}

	return true;
}

bool DLL::operator!= (const DLL& L) {
	return !(*this == L);
}

bool DLL::operator>= (const DLL& L) {
	if (Count > L.Count)
		return true;
	if (*this == L)
		return true;

	return false;
}

bool DLL::operator<= (const DLL& L) {
	if (Count < L.Count)
		return true;
	if (*this == L)
		return true;

	return false;
}

bool DLL::operator> (const DLL& L) {
	if (Count > L.Count)
		return true;

	return false;
}

bool DLL::operator< (const DLL& L) {
	if (Count < L.Count)
		return true;

	return false;
}

DLL DLL::operator- () {
	DLL Result;

	Elem* temp = Head;

	while (temp != 0 ) {
		Result.AddHead(temp->data);
		temp = temp->next;
	}

	return Result;
}