#pragma once

#include "DLL.h"

class Queue2: private DLL
{
public:
	void insert(int pos);
	void deleteItem();
	void display();
};

