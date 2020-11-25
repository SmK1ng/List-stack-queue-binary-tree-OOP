#include "QueueMenu.h"

QueueMenu::QueueMenu() {

	addMenuItem("Clear screen");
	addMenuItem("Delete");
	addMenuItem("Insert");
	addMenuItem("Display");

	processMenu();
}

void QueueMenu::processMenuItem(int number)
{
	int data;

	switch (number) {
	case 1:
		queue.display();
		break;

	case 2:
		cout << "Eneter data" << endl;
		cin >> data;
		queue.insert(data);
		break;

	case 3:
		queue.deleteItem();
		break;

	case 4:
		system("cls");
		break;

	}
}
