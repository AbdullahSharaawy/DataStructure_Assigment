#pragma once
#include<iostream>
#include<cmath>
using namespace std;
namespace Tree
{

	class AVLNode
	{
	private:
		int _ID;
		string _Name;
		
	public:
		AVLNode* _right;
		AVLNode* _left;
		int _Height;
		int getID()
		{
			//if (this == nullptr)
			//	return -1;// mark for no node exists where it is null
			return this->_ID;
		}
		
		void updateData(int ID, string Name)
		{
			this->_ID = ID;
			this->_Name = Name;
		}
		string getName()
		{
			//if (this == nullptr)
			//	return "";// mark for no node exists where it is null
			return this->_Name;
		}
		AVLNode(int ID, string Name)
		{
			this->_right = nullptr;
			this->_left = nullptr;
			this->_ID = ID;
			this->_Name = Name;
			this->_Height = 1;
		}

	};

	class AVL
	{
	public:
		AVLNode* _root;
		AVL()
		{
			this->_root = nullptr;
		}
		
		AVLNode* add(AVLNode* root, AVLNode* newNode)
		{
			if (root == nullptr)
				return root = newNode;
			if (root->getID() < newNode->getID())
				root->_right = add(root->_right, newNode);
			else if (root->getID() > newNode->getID())
				root->_left = add(root->_left, newNode);
			else return root;
			// update height
			root->_Height = 1 + max(getHeight(root->_left), getHeight(root->_right));
			root = rebalnce(root);
			return root;
		}
		int getHeight(AVLNode* node) {
			return node ? node->_Height : 0;
		}
		void Insert(AVLNode* newNode)
		{
			if (newNode == nullptr)
				return;
			this->_root = add(this->_root, newNode);
			
		}
		AVLNode* search(int ID)
		{
			if (_root == nullptr)
				return nullptr;

			AVLNode* temp = this->_root;
			while (temp != nullptr)
			{
				if (temp->getID() < ID)
					temp = temp->_right;
				else if (temp->getID() > ID)
					temp = temp->_left;
				else return temp;
			}
			return nullptr;
		}
		int countNodes()
		{
			int counter = 0;// number of nodes 
			countNodes(counter, this->_root);
			return counter;
		}
		void countNodes(int& counter, AVLNode* root)
		{
			if (root == nullptr)
				return;
			counter++;
			countNodes(counter, root->_left);
			countNodes(counter, root->_right);
		}
		int* MaximumValueInEachLevel()
		{
			int* MaximumValues = new int[MaxDepth()];
			fill(MaximumValues, MaximumValues + MaxDepth(), INT_MIN);
			MaximumValueInEachLevel(0, MaximumValues, this->_root);
			return MaximumValues;
		}
		void MaximumValueInEachLevel(int LevelNumber, int*& arr, AVLNode* root)
		{
			if (root == nullptr)
				return;
			if (root->getID() > arr[LevelNumber])
				arr[LevelNumber] = root->getID();
			MaximumValueInEachLevel(LevelNumber+1, arr, root->_left);
			MaximumValueInEachLevel(LevelNumber+1, arr, root->_right);

		}
		int countLevels()
		{
			int NNodes = countNodes();
			int NLevels = 0;
			bool* LevelsExists = new bool[NNodes];
			for (size_t i = 0; i < NNodes; i++)//initialize operation
				LevelsExists[i] = false;
			countLevels(0, LevelsExists, this->_root);
			for (size_t i = 0; i < NNodes; i++)
			{
				if (!LevelsExists[i])
					break;
				NLevels++;
			}
			delete[]LevelsExists;
			return NLevels;
		}
		void countLevels(int LevelNumber, bool*& arr, AVLNode* root)
		{
			if (root == nullptr)
				return;
			// always assign true as mark for current level 	
			arr[LevelNumber] = true;
			countLevels(LevelNumber + 1, arr, root->_left);
			countLevels(LevelNumber + 1, arr, root->_right);

		}
		void print(AVLNode* root, int n_space)
		{
			if (root == nullptr)
				return;
			print(root->_right, n_space + 5);
			for (size_t i = 0; i < n_space; i++)
			{
				cout << " ";
			}
			cout << root->getID() <<","<<root->_Height << endl;
			print(root->_left, n_space + 5);
		}
		void print()
		{
			print(this->_root, 5);
		}
		int MaxDepth()
		{
			return MaxDepth(this->_root);
		}
		int MaxDepth(AVLNode* root)
		{
			if (root == nullptr)
				return 0;
			int left = MaxDepth(root->_left);
			int right = MaxDepth(root->_right);
			return max(left, right) + 1;
		}
		static bool Identical(AVLNode* root1, AVLNode* root2)
		{
			bool IsIdentical = true;
			Identical(root1, root2, IsIdentical);
			return IsIdentical;
		}
		static void Identical(AVLNode* root1, AVLNode* root2, bool& IsIdentical)
		{
			//base case to end the operation
			if (!IsIdentical)
				return;
			// comparte between two trees
			if (root1 == root2 && root1 == nullptr)
				return;
			else if (root1 == nullptr || root2 == nullptr)
			{
				IsIdentical = false;
			}
			else if (root1->getID() == root2->getID())
			{

				Identical(root1->_left, root2->_left, IsIdentical);
				Identical(root1->_right, root2->_right, IsIdentical);
			}// end the operation
			else IsIdentical = false;

		}
		void deleteNode(int ID)
		{
			AVLNode* target = search(ID);
			if (target == nullptr)
				return;
			this->_root=deleteNode(this->_root,target);
			this->_root->_Height = 1 + max(getHeight(this->_root->_left), getHeight(this->_root->_right));
			this->_root = rebalnce(this->_root);
		}
		AVLNode* deleteNode(AVLNode* root, AVLNode* targetNode)
		{
			if (root == nullptr )
				return nullptr;
			if (targetNode == nullptr)
				return root;
			if (targetNode == root)
			{
				if (root->_right == nullptr)
				{
					AVLNode* temp = root->_left;
					delete root;
					root= temp;
				}
				else if (root->_left == nullptr )
				{
					AVLNode* temp = root->_right;
					delete root;
					root= temp;
				}
				else if (root->_left != nullptr && root->_right != nullptr)
				{
					AVLNode* temp = root->_left;
					
					if (temp->_right == nullptr)
					{
						targetNode->updateData(temp->getID(), temp->getName());
					    root->_left = temp->_left;
						delete temp;
					}
					else
					{
						temp->_right = LastRightNode(temp->_right, targetNode);
						temp->_Height = 1 + max(getHeight(temp->_left), getHeight(temp->_right));
						temp = rebalnce(temp);
						root->_left = temp;
					}
				}
				
			}
			else if (targetNode->getID() < root->getID())
			root->_left=deleteNode(root->_left, targetNode);
			else if (targetNode->getID() > root->getID())
				root->_right = deleteNode(root->_right, targetNode);
			if (root)
			{
				root->_Height = 1 + max(getHeight(root->_left), getHeight(root->_right));// update height
				root = rebalnce(root);
			}
			return root;
		}
		AVLNode* LastRightNode(AVLNode* root, AVLNode* targetNode)
		{
			if (root->_right == nullptr)
			{
				targetNode->updateData(root->getID(), root->getName());
				AVLNode* temp = root->_left;
				delete root;
				root= temp;
			}
			else
			root->_right = LastRightNode(root->_right, targetNode);
			if (root)
			{
				root->_Height = 1 + max(getHeight(root->_left), getHeight(root->_right));
				root = rebalnce(root);
			}
			return root;
		}
		AVLNode* rotateRight(AVLNode* root)
		{
			AVLNode* newRoot = root->_left;
			root->_left = newRoot->_right;
			newRoot->_right = root;
			root->_Height = 1 + max(getHeight(root->_left), getHeight(root->_right));// update root height
            newRoot->_Height= 1 + max(getHeight(newRoot->_left), getHeight(newRoot->_right));
			return newRoot;
		}
		AVLNode* rotateLeft(AVLNode* root)
		{
			AVLNode* newRoot = root->_right;
			root->_right = newRoot->_left;
			newRoot->_left = root;
			root->_Height = 1 + max(getHeight(root->_left), getHeight(root->_right));// update root height
			newRoot->_Height = 1 + max(getHeight(newRoot->_left), getHeight(newRoot->_right));
			return newRoot;
		}
		int calculateBF(AVLNode* root)
		{
			int BF = getHeight(root->_left) - getHeight(root->_right);
			return BF;
		}
		AVLNode* rebalnce(AVLNode* root)
		{
			if (root == nullptr)
				return nullptr;
			int BF = calculateBF(root);
			if (abs(BF) >= 2)
			{
				if (BF >= 2 && calculateBF(root->_left) >= 0)
				{
					root = rotateRight(root);
					root = rebalnce(root);
				}
					
				else if (BF <= -2 && calculateBF(root->_right) <= 0)
				{
					root = rotateLeft(root);
					root = rebalnce(root);
				}
					
				else
				{
					if (BF >= 2 && calculateBF(root->_left) < 0)
					{
						root->_left = rotateLeft(root->_left);
						root->_Height = 1 + max(getHeight(root->_left), getHeight(root->_right));// update root height
						root=rebalnce(root);
					}
					else if (BF <= -2 && calculateBF(root->_right) > 0)
					{
						root->_right = rotateRight(root->_right);
						root->_Height=  1 + max(getHeight(root->_left), getHeight(root->_right));// update root height
						root=rebalnce(root);
					}
					
				}
				
				return root;
			}
			else
				return root;
		}
};
	
}

