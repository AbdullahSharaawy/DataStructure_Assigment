#pragma once
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include"AVLNode.h"
#include<iomanip>
using namespace std;
namespace AVL
{
	
	class AVLTree
	{
	private:
		AVLNode* Root;
		int NodesNumber,MaxWidth=1;
		AVLNode* LeftRotation(AVLNode* root)
		{
			// left rotation when the balance foctor for right subtree is biger from left subtree
			AVLNode* newRoot = root->RightChild;
			AVLNode* temp = newRoot->LeftChild;
			newRoot->LeftChild = root;
			root->RightChild = temp;
			// updat the height of the old root
			root->Height = updateHeight(root);
			return newRoot;
		}
		AVLNode* RightRotation(AVLNode* root)
		{
			// right rotation when the balance foctor for left subtree is biger from right subtree 
			AVLNode* newRoot = root->LeftChild;
			AVLNode* temp = newRoot->RightChild;
			newRoot->RightChild = root;
			root->LeftChild = temp;
			// updat the height of the old root
			root->Height = updateHeight(root);
			
			return newRoot;
		}
		AVLNode* rebalance(AVLNode* root)
		{
			
			// calculate the balance factor of the root
			int BFRoot = BalanceFactor(root);

			// it is balance tree
			if (abs(BFRoot) < 2)
				return root;
			
			/// single right rotation
			else if (BFRoot >= 2 && BalanceFactor(root->LeftChild) >= 0)
				root = RightRotation(root);

			// single left rotation
			else if (BFRoot <= -2 && BalanceFactor(root->RightChild) <=0)
				root = LeftRotation(root);
		
			else
			{
				// left rotation then right rotation
				if (BFRoot >= 2 && BalanceFactor(root->LeftChild) <= -1)
				{
					root->LeftChild = LeftRotation(root->LeftChild);
					root->LeftChild->Height = updateHeight(root->LeftChild);
				}
					
				// right rotation then left rotation
				else if (BFRoot <= -2 && BalanceFactor(root->RightChild) >= 1)
				{
					root->RightChild = RightRotation(root->RightChild);
					root->RightChild->Height = updateHeight(root->RightChild);
				}
					
				// then rebalance again
				root = rebalance(root);
			}
			// end the rotation operations
			return root;
		}
		int BalanceFactor(AVLNode* root)
		{
			// calculate the balance factor where it is the difference between tow subtree (height of left child - height of right child)
			if (root->RightChild == NULL && root->LeftChild == NULL)
				return 0;
			if (root->RightChild == NULL)
				return root->LeftChild->Height ;
			if (root->LeftChild == NULL)
				return 0-root->RightChild->Height ;

			return root->LeftChild->Height - root->RightChild->Height ;
		}
		int updateHeight(AVLNode* root)
		{
			// update the height of the node after each insert or delete 
			if (root->RightChild == NULL && root->LeftChild == NULL)
				return 1;
			if (root->RightChild == NULL)
				return root->LeftChild->Height + 1;
			if (root->LeftChild == NULL)
				return root->RightChild->Height + 1;

			return root->LeftChild->Height > root->RightChild->Height ? root->LeftChild->Height + 1 : root->RightChild->Height + 1;
		}
		AVLNode* insert(AVLNode* root, AVLNode* newNode)
		{
			//insert as binary search tree
			if (root == NULL)
				return newNode;
			if (root->getContactID() < newNode->getContactID())
				root->RightChild = insert(root->RightChild, newNode);
			else if (root->getContactID() > newNode->getContactID())
				root->LeftChild = insert(root->LeftChild, newNode);
			else
			{
				cout << "Error: Contact with ID " << root->getContactID() << " already exists.\n";
				return root;
			}
				
			// update the height node
			root->Height = updateHeight(root);
			// rebalance the tree to be AVL tree
			root = rebalance(root);
			// return the node to his parent node as left child or right child
			return root;
		}
		
		
		int levelOrder(AVLNode* node)
		{
			return (getHeight() - node->Height) + 1;
		}
		AVLNode* search(int ID)
		{
			if (this->Root == NULL)
				return NULL;
			AVLNode* temp = this->Root;

			while (temp != NULL)
			{
				if (temp->getContactID() == ID)
					return temp;

				else if (temp->getContactID() < ID)
					temp = temp->RightChild;

				else if (temp->getContactID() > ID)
					temp = temp->LeftChild;
			}
			return NULL;
		}
		void printInfo(AVLNode* targetNode)
		{
			cout << endl << endl;
			cout << "Contact found :" << endl;
			cout << "ID: " << targetNode->getContactID() << endl;
			cout << "Name : " << targetNode->getName() << endl;
			cout << "Phone : " << targetNode->getPhone() << endl;
			cout << "Email : " << targetNode->getEmail() << endl;
		}
		void inorderTraversal(AVLNode* root)
		{
			// using it to print list of all contacts orderd
			if (root == NULL)
				return;
			inorderTraversal(root->LeftChild);
			// the process
			cout << " ID: " << root->getContactID() << ", Name : " << root->getName() << ", Phone : " << root->getPhone() << ", Email : " << root->getEmail() << endl;
			inorderTraversal(root->RightChild);
		}
		AVLNode* deleteContact(AVLNode* root,AVLNode* targetNode)
		{
			
			
		    if (root->RightChild == NULL)
			{
				targetNode->setContactID(root->getContactID());
				targetNode->setEmail(root->getEmail());
				targetNode->setPhone(root->getPhone());
				targetNode->setName(root->getName());
				cout << "\nContact deleted successfully.\n";
				delete root;
				return NULL;
			}
			
			else
			root->RightChild = deleteContact(root->RightChild,targetNode);
			// update the height node
			root->Height = updateHeight(root);
			// rebalance the tree to be AVL tree
			root = rebalance(root);
			// return the node to his parent node as left child or right child
			return root;
		}
		AVLNode* deleteContact(AVLNode* root, int ID)
		{
			if (root == NULL)
			{
				cout << "\nContact not found.\n";
				return NULL;
			}
			if (root->getContactID() == ID)
			{
				if (root == NULL && root->RightChild == NULL)
				{
					delete root;
					cout << "\nContact deleted successfully.\n";
					return NULL;
				}
				else if (root->LeftChild == NULL)
				{
					AVLNode* temp = root->RightChild;
					delete root;
					cout << "\nContact deleted successfully.\n";
					return temp;
				}
				root->LeftChild = deleteContact(root->LeftChild, root);
			}
			else if (root->getContactID() < ID)
				root->RightChild = deleteContact(root->RightChild, ID);
			else if (root->getContactID() > ID)
				root->LeftChild = deleteContact(root->LeftChild, ID);
			// update the height node
			root->Height = updateHeight(root);
			// rebalance the tree to be AVL tree
			root = rebalance(root);
			// return the node to his parent node as left child or right child
			return root;
		}
		string space(int noSpaces)
		{
			string spaces;
			for (size_t i = 0; i < noSpaces; i++)
			{
				spaces+= " ";
			}
			return spaces;
		}
		void clear(AVLNode* node) {
			if (!node) return;
			clear(node->LeftChild);
			clear(node->RightChild);
			delete node;
		}
		int nodeWidth(AVLNode* node)
		{
			if (node)
			{
				int a = to_string(node->getContactID()).length()+3 ;
				return abs(a);
			}
				
			else
				return 2;
		}
public:
		AVLTree()
		{
			this->Root = NULL;
			NodesNumber = 0;
		}
		~AVLTree()
		{
			clear(this->Root);
			this->Root = nullptr;
		}
		

		void clear() {
			clear(this->Root);
			Root = nullptr;
		}
		void find(int ID)
		{
			AVLNode* targetNode = search(ID);
			if (targetNode != NULL)
			{
				printInfo(targetNode);
			}
			else
				cout<< "Contact not found :" << endl;
		}
		void insert(AVLNode* newNode)
		{
			this->NodesNumber++;// counter for number of nodes
			// calculate the max width for the nodes , where i need it in print the tree
			if (to_string(newNode->getContactID()).length() > this->MaxWidth)
				MaxWidth = to_string(newNode->getContactID()).length();
			// end the insert operation
			this->Root = insert(this->Root, newNode);
			
			/*if (this->Root == NULL)
				this->Root = newNode;
			AVLNode* temp = this->Root;
			AVLNode* previous = this->Root;

			while (temp != NULL)
			{

				if (temp->getContactID() < newNode->getContactID())
				{
					
					previous = temp;
					temp = temp->RightChild;
				}
				else if (temp->getContactID() > newNode->getContactID())
				{
					previous = temp;
					temp = temp->LeftChild;
				}
				else
					break;
			}
			if (temp == NULL && previous->getContactID() < newNode->getContactID())
			{
				previous->RightChild = newNode;
			}
			else if (temp == NULL && previous->getContactID() > newNode->getContactID())
			{
				previous->LeftChild = newNode;
			}*/
		}
		int initialLeadingSpace(int level, int nodeWidth) {
			return static_cast<int>((pow(2, getHeight() - level) - 1) * (MaxWidth / 2.0));
		}

		int spaceBetween(int level, int nodeWidth) {
			return static_cast<int>((pow(2, getHeight() - level + 1) - 1) * (MaxWidth / 2.0));
		}
		void printTree()
		{
			if (this->Root == NULL)
				return;
			// this old code, i can`t use it beacause memory leak for reason undefined
			{
			// AVLNode** Nodes = new AVLNode * [NodesNumber*2];  // correct: array of pointers to AVLNode
			// for (int i = 0; i < NodesNumber * 2; ++i)
			//	 Nodes[i] = nullptr;
			//int front = 0, last = 0;
			//string levelArrows = "";
			//int no_currentLevel = 1;// Nodes Number of current level
			//int counter = 0;// nodes number that are printed in the current level
			//int Level = 1;// the current level  equal { log2(number of nodes that includes for this level) - 1 }
			//Nodes[last++] =this->Root;
			// 
			//	while (front < last && Level<=getHeight())
			//{
			//	
			//	AVLNode* currentNode = Nodes[front++];
			//	{
			//		/////////////////////////////////////////////	
			//		// print the nodes
			//		// print initial leading space
			//		
			//		if (counter == 0) {
				//		string l=space(initialLeadingSpace(Level, nodeWidth(currentNode)));
				//		levelArrows = l;
				//		cout << setw(initialLeadingSpace(Level, nodeWidth(currentNode)))<<l;
				//	}
			//		// print the contact ID
			//		if (currentNode == nullptr) {
					//	string l=space(nodeWidth(currentNode));
					//	levelArrows += l;
					//	cout << setw(nodeWidth(currentNode))<<l;
					//}
			
			//		    else {
					// 	 cout <<setw(nodeWidth(currentNode))<< currentNode->getContactID();
					// 	 // Calculate arrow positions relative to node
					// 	 int arrowPos = nodeWidth(currentNode) / 2; // Center arrows under node
					// 	 levelArrows += space(arrowPos);
					// 	 if (currentNode->LeftChild && currentNode->RightChild)
					// 		 levelArrows += "/  \\";
					// 	 else if (currentNode->RightChild)
					// 		 levelArrows += "  \\";
					// 	 else if (currentNode->LeftChild)
					// 		 levelArrows += "/  ";
					// 	 else
					// 		 levelArrows += "  ";
					// 	// levelArrows += space(nodeWidth(currentNode) - arrowPos - 1);
					// }

					// // Print space between nodes
					// string l=space(spaceBetween(Level, nodeWidth(currentNode)));
					// levelArrows += l;
					// cout <<setw(spaceBetween(Level, nodeWidth(currentNode)))<< l;
					
					// counter++;

					// // Check if all nodes in the current level are processed
					// if (counter == no_currentLevel) {
					// 	cout << endl <<setw(levelArrows.length())<< levelArrows << endl;
					// 	counter = 0;
					// 	no_currentLevel *= 2;
					// 	Level = static_cast<int>(log2(no_currentLevel)) + 1;
					// 	levelArrows = "";
					// }
			//		/////////////////////////////////////////
			//	}
			//	if (currentNode != NULL && currentNode->LeftChild != NULL)
			//		Nodes[last++] = currentNode->LeftChild;
			//	else
			//		Nodes[last++] = nullptr;
			//		
			//	if (currentNode != NULL && currentNode->RightChild != NULL)
			//		Nodes[last++] = currentNode->RightChild;
			//	else
			//		Nodes[last++] = nullptr;
			//	
			// }
			//	delete[]Nodes;
		}
			// the new code using vector
			

				vector<AVLNode*> nodes;
				int front = 0, last = 0;
				int no_currentLevel = 1;
				int counter = 0;
				int Level = 1;
				string levelArrows = "";
				nodes.push_back(Root);
				last++;

				while (front < last && Level <= getHeight()) {
					AVLNode* currentNode = nodes[front++];
					
					// Print initial leading space if starting the level
					if (counter == 0) {
						string l=space(initialLeadingSpace(Level, nodeWidth(currentNode)));
						levelArrows = l;
						cout << setw(initialLeadingSpace(Level, nodeWidth(currentNode)))<<l;
					}

					// Print node's contact ID or spaces if null
					if (currentNode == nullptr) {
						string l=space(nodeWidth(currentNode));
						levelArrows += l;
						cout << setw(nodeWidth(currentNode))<<l;
					}
					else {
						 cout <<setw(nodeWidth(currentNode))<< currentNode->getContactID();
						 // Calculate arrow positions relative to node
						 int arrowPos = nodeWidth(currentNode) / 2; // Center arrows under node
						 levelArrows += space(arrowPos);
						 if (currentNode->LeftChild && currentNode->RightChild)
							 levelArrows += "/  \\";
						 else if (currentNode->RightChild)
							 levelArrows += "  \\";
						 else if (currentNode->LeftChild)
							 levelArrows += "/  ";
						 else
							 levelArrows += "  ";
						// levelArrows += space(nodeWidth(currentNode) - arrowPos - 1);
					}

					// Print space between nodes
					string l=space(spaceBetween(Level, nodeWidth(currentNode)));
					levelArrows += l;
					cout <<setw(spaceBetween(Level, nodeWidth(currentNode)))<< l;
					
					counter++;

					// Check if all nodes in the current level are processed
					if (counter == no_currentLevel) {
						cout << endl <<setw(levelArrows.length())<< levelArrows << endl;
						counter = 0;
						no_currentLevel *= 2;
						Level = static_cast<int>(log2(no_currentLevel)) + 1;
						levelArrows = "";
					}

					// Enqueue left child
					if (currentNode && currentNode->LeftChild) {
						nodes.push_back(currentNode->LeftChild);
					}
					else {
						nodes.push_back(nullptr);
					}
					last++;

					// Enqueue right child
					if (currentNode && currentNode->RightChild) {
						nodes.push_back(currentNode->RightChild);
					}
					else {
						nodes.push_back(nullptr);
					}
					last++;
				}
			}
		int getHeight()//  the height of tree
		{
			return this->Root? this->Root->Height:0;
		}
		void ListAllContacts()
		{
			inorderTraversal(this->Root);
		}
		void deleteContact(int ID)
		{
			this->Root = deleteContact(this->Root, ID);
		}
		
	};

}
