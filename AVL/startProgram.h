#pragma once
#include <iostream>
#include"AVLTree.h"
#include"AVLNode.h"
#include "DataInput.h"
#include "DataAccess.h"
using namespace AVL;

using namespace std;
class startProgram
{
private:
	static void mainMenu()
	{
		cout << "Address Book Application\n";
		cout << "------------------------\n";
		cout << "1. Add New Contacts\n";
		cout << "2. Search for Contact\n";
		cout << "3. Delete Contact(Optional)\n";
		cout << "4. List All Contacts(Sorted by ID)\n";
		cout << "5. Display Current Tree Structure\n";
		cout << "6. End the program\n";
		cout << "------------------------\n";
		cout << "Enter operation(1 - 5) :\n";
	}
	static int readContactID()
	{
		int ID;
		while (true)
		{
			cout << "\nEnter Contact ID : ";
			cin >> ID;

			if (cin.fail())
			{
				cin.clear(); // Clear the error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
				cout << "Invalid input. Please enter a valid ID \n";
			}
			else
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any extra input
				break;
			}
		}
		return ID;
	}
public:
	static void run()
	{
		AVLNode** _Data ;  // correct: array of pointers to AVLNode
		AVLTree* tree = new AVLTree();
		bool _continue=true;
		while (_continue)
		{
		mainMenu();
		int choice = DataInput::ReadChoice(1, 6);
		int ID;
		switch (choice)
		{
		case 1:
		{
			int _size=0;
			DataAccess::ReadData(_Data,_size);
			tree->clear();
			for (size_t i = 0; i < _size; i++)
			{
				tree->insert(_Data[i]);
			}
			delete[]_Data;
			break;
		}
		case 2:
		{
		
			if (tree->getHeight())
			{
				ID = readContactID();
				tree->find(ID);
			}
			else cout << "\nPlease Enter The Contacts: \n";
			break;
		}
		case 3:
		{
			if (tree->getHeight())
			{
				ID = readContactID();
				tree->deleteContact(ID);
			}
			else cout << "\nPlease Enter The Contacts: \n";
			break;
		}
		case 4:
		{
			
			if (tree->getHeight())
				tree->ListAllContacts();
			else cout << "\nPlease Enter The Contacts: \n";
			break;
		}
		case 5:
		{
			if (tree->getHeight())
				tree->printTree();
			else cout << "\nPlease Enter The Contacts: \n";
			break;
		}
		case 6:
		{
			tree->clear();
			_continue = false;
			break;
		}
		default:
			break;
		}
		}
	}
};

