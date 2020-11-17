#pragma once

#include <iostream>

using namespace std;

struct Elem {
	int data;
	Elem* next, * prev;
};

class DLL
{
	Elem* Head, * Tail;
	int Count;

public:
	DLL();
	DLL(const DLL&);
	~DLL();

	int GetCount();
	Elem* GetElem(int);
	bool isEmpty();

	void DelAll();
	void Del(int pos = 0);
	
	void Insert(int pos = 0);

	void AddTail(int n);
	void AddHead(int n);

	void Print();
	void Print(int pos);

	DLL& operator = (const DLL&);
	DLL operator + (const DLL&);

	bool operator == (const DLL&);
	bool operator != (const DLL&);
	bool operator <= (const DLL&);
	bool operator >= (const DLL&);
	bool operator < (const DLL&);
	bool operator > (const DLL&);

	DLL operator - (); //переворачивание
};

