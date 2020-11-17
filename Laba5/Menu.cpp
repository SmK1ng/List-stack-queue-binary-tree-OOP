#include "Menu.h"
#include "DLL.h"
#include "Stack.h"
#include "Queue.h"
#include "BST.h"

#include<stdio.h>

void Menu::select() {
	DLL DLL;
	Stack Stack;
	Queue Queue;
	BST BST;

	while (true) {
		system("cls");
		int num_class;
		cout << "Choose a class:" << endl;
		cout << "1 - Doubly Linked List" << endl;
		cout << "2 - Stack" << endl;
		cout << "3 - Queue" << endl;
		cout << "4 - BST" << endl;
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
				cout << "8 - Exit in Main Menu" << endl;

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
					flag = false;
				}

				system("pause");
			}
			break;
			

		case 2:
			while (flag) {
				system("cls");
				int num;
				cout << "Select a stack operation: " << endl;
				cout << "1 - Push" << endl;
				cout << "2 - Pop" << endl;
				cout << "3 - Show the top element" << endl;
				cout << "4 - Exit in Main Menu" << endl;

				cin >> num;

				int data;

				switch (num) {
				case 1:
					cout << "Enter the stack node data: ";
					cin >> data;
					Stack.push(data);
					break;

				case 2:
					Stack.pop();
					break;

				case 3:
					Stack.ShowTop();
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
				cout << "Select a queue operation: " << endl;
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
					Queue.insert(data);
					break;

				case 2:
					Queue.deleteItem();
					break;

				case 3:
					Queue.display();
					break;

				case 4:
					flag = false;
				}

				system("pause");
			}

			break;
			
		case 4:
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
	}