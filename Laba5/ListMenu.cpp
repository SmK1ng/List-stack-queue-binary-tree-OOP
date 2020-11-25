#include "ListMenu.h"

ListMenu::ListMenu()
{
	addMenuItem("Clear screen");
	addMenuItem("Del");
	addMenuItem("AddHead");
	addMenuItem("AddTail");
	addMenuItem("Insert");
	addMenuItem("Print");

	processMenu();
}

void ListMenu::processMenuItem(int number)
{
	int data, index;

	switch (number) {
	case 1:
		list.Print();
		break;

	case 2:
		cout << "Enter position" << endl;
		cin >> index;
		list.Insert(index);
		break;

	case 3:
		cout << "Enter data" << endl;
		cin >> data;
		list.AddTail(data);
		break;

	case 4:
		cout << "Enter data" << endl;
		cin >> data;
		list.AddHead(data);
		break;

	case 5:
		cout << "Enter position" << endl;
		cin >> index;
		list.Del(index);
		break;

	case 6:
		system("cls");
		break;
	}
}
