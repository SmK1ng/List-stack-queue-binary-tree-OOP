#pragma once

#include<list>
#include<string>
#include<iostream>

using namespace std;

class Menu
{
	list<string> items;

public:
	//static void select();

	Menu();
	int addMenuItem(string item);
	void processMenu();
	
	virtual void processMenuItem(int number) = 0;
};

