#include "Menu.h"
#include "DLL.h"
#include "Stack.h"
#include "Queue.h"
#include "BST.h"
#include "Queue1.h"
#include "Queue2.h"

#include<stdio.h>

Menu::Menu() {
	items.push_back("Add element menu");
	items.push_back("Quit");
}

int Menu::addMenuItem(string item) {
	items.push_front(item);
	return items.size();
}

void Menu::processMenu() {
	
	int menu_item;
	do {
		int num = 1;

		for (auto item : items) {
			cout << num << "-" << item << endl;
			num++;
		}

		cin >> menu_item;

		if (menu_item > 0 && menu_item < items.size()) {
			if (menu_item == items.size() - 1) {
				string item_name;

				cout << "Enter menu item name: " << endl;
				cin >> item_name;

				addMenuItem(item_name);

				system("cls");
			}
			else {
				this->processMenuItem(menu_item);
			}
		}
	} while (menu_item != items.size());
}

/*void Menu::select() {
	DLL DLL;
	Stack Stack;
	Queue Queue;
	BST BST;
	Queue1 Queue1;
	Queue2 Queue2;

	while (true) {
		system("cls");
		int num_class;
		cout << "Choose a class:" << endl;
		cout << "1 - Doubly Linked List" << endl;
		cout << "2 - Queue1" << endl;
		cout << "3 - Queue2" << endl;
		//cout << "4 - BST" << endl;
		cout << "5 - Exit" << endl;

		cin >> num_class;

		bool flag = true;

		switch (num_class) {
		case 1:
			while (flag) {
				system("cls");
				int num;
				cout << endl << "Select a list operation: " << endl;
				cout << "1 - DelAll" << endl;
				cout << "2 - Del" << endl;
				cout << "3 - Insert" << endl;
				cout << "4 - AddTail" << endl;
				cout << "5 - AddHead" << endl;
				cout << "6 - Print" << endl;
				cout << "7 - PrintPos" << endl;
				cout << "8 - Is Empty" << endl;
				cout << "9 - Exit in Main Menu" << endl;
				

				cin >> num;
				int key;
				int data;

				switch (num) {
				case 1:
					DLL.DelAll();
					break;

				case 2:
					cout << "Enter the list node key: ";
					cin >> key;
					DLL.Del(key);
					break;

				case 3:
					DLL.Insert();
					break;

				case 4:
					cout << "Enter the list node data: ";
					cin >> data;
					DLL.AddTail(data);
					break;

				case 5:
					cout << "Enter the list node data: ";
					cin >> data;
					DLL.AddHead(data);
					break;

				case 6:
					DLL.Print();
					break;

				case 7:
					cout << "Enter the list node key: ";
					cin >> key;
					DLL.Print(key);
					break;

				case 8:
					cout << DLL.isEmpty() << endl;
					break;

				case 9:
					flag = false;
				}

				system("pause");
			}
			break;
			

		case 2:
			while (flag) {
				system("cls");
				int num;
				cout << "Select a Queue1 operation: " << endl;
				cout << "1 - insert" << endl;
				cout << "2 - deleteItem" << endl;
				cout << "3 - display" << endl;
				cout << "4 - Exit in Main Menu" << endl;

				cin >> num;

				int data;

				switch (num) {
				case 1:
					cout << "Enter the stack node data: ";
					cin >> data;
					Queue1.insert(data);
					break;

				case 2:
					Queue1.deleteItem();
					break;

				case 3:
					Queue1.display();
					break;

				case 4:
					flag = false;
				}

				system("pause");
			}

			break;

		case 3:
			while (flag) {
				system("cls");
				int num;
				cout << "Select a Queue2 operation: " << endl;
				cout << "1 - Insert" << endl;
				cout << "2 - Delete item" << endl;
				cout << "3 - Print" << endl;
				cout << "4 - Exit in Main Menu" << endl;

				cin >> num;

				int data;

				switch (num) {
				case 1:
					cout << "Enter the queue node data: ";
					cin >> data;
					Queue2.insert(data);
					break;

				case 2:
					Queue2.deleteItem();
					break;

				case 3:
					Queue2.display();
					break;

				case 4:
					flag = false;
				}

				system("pause");
			}

			break;
			
		/*case 4:
			while (flag) {
				system("cls");
				int num;
				cout << "Select a BST operation: " << endl;
				cout << "1 - Insert" << endl;
				cout << "2 - Search" << endl;
				cout << "3 - Print" << endl;
				cout << "4 - Remove" << endl;
				cout << "5 - Exit in Main Menu" << endl;
				cout << "6" << endl;

				cin >> num;

				int data;

				switch (num) {
				case 1:
					cout << "Enter the BST node data: ";
					cin >> data;
					BST.Insert(data);
					break;

				case 2:
					cout << "Enter the BST node data: ";
					cin >> data;
					BST.Search(data);
					break;

				case 3:
					BST.PrintTreeInOrder();
					break;

				case 4:
					cout << "Enter the BST node data: ";
					cin >> data;
					BST.Remove(data);
					break;

				case 5:
					flag = false;

				case 6:
					cout << "Enter the BST node data: ";
					cin >> data;
					BST.Successor(data);
					break;
				}

				system("pause");
			}

			break;

		case 5:
			exit(0);
			}
		}
	}*/