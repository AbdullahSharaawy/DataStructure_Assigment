#pragma once
#include<iostream>
#include<cmath>
using namespace std;
class HeapNode
{
private:
	string _Name;
	int _Severity;
	int _ID;
public:
	HeapNode(string Name, int ID, int Severity)
	{
		this->_Name = Name;
		this->_ID = ID;
		this->_Severity = Severity;
	}
	string getName()
	{
		return this->_Name;
	}
	int getSeverity()
	{
		if (this == nullptr)
			return -1;

		return this->_Severity;
	}
	int getID()
	{
		if (this == nullptr)
			return -1;
		return this->_ID;
	}
};
class MaxHeap
{
private:
	int _Size ;
	int _Capacity;
	HeapNode** _HeapNodes;
	void Swap(HeapNode* &node1, HeapNode* &node2)
	{
		HeapNode* temp = node1;
		node1 = node2;
		node2 = temp;
	}
	void updateIndices(int& ParentIndex, int& ChildIndex)
	{
		// for rehipifyup
		Swap(this->_HeapNodes[ParentIndex], this->_HeapNodes[ChildIndex]);

		ChildIndex = ParentIndex;
		ParentIndex = floor((ChildIndex - 1) / 2);
	}
	void ReheapifyUp()
	{
		if (this->_Size - 1 == 0)
			return;
		int Last = this->_Size - 1;
		int ParentIndex = floor((Last - 1)/2);
		
		while (Last > 0)
		{
			if (this->_HeapNodes[ParentIndex]->getSeverity() == this->_HeapNodes[Last]->getSeverity())
			{
				if (this->_HeapNodes[ParentIndex]->getID() > this->_HeapNodes[Last]->getID())
				{
					updateIndices(ParentIndex, Last);
				}
				else break;
			}
			else if (this->_HeapNodes[ParentIndex]->getSeverity() < this->_HeapNodes[Last]->getSeverity())
			{
				updateIndices(ParentIndex, Last);
			}
			else break;
				
		}
	}
	
	void ReheapifyDown()
	{
		if (this->_Size - 1 == 0)
			return;
		int Child1Index = 1;
		int Child2Index = 2;
		int ParentIndex = 0;
		while (Child1Index < this->_Size  && Child2Index < this->_Size )
		{
			int CurrentParentIndex=-1;
			if (this->_HeapNodes[ParentIndex]->getSeverity() == this->_HeapNodes[Child1Index]->getSeverity() && this->_HeapNodes[ParentIndex]->getSeverity() == this->_HeapNodes[Child2Index]->getSeverity())
			{
				if (this->_HeapNodes[ParentIndex]->getID() > this->_HeapNodes[Child1Index]->getID())
				{
					Swap(this->_HeapNodes[ParentIndex], this->_HeapNodes[Child1Index]);
					CurrentParentIndex = Child1Index;
				}
				if (this->_HeapNodes[ParentIndex]->getID() > this->_HeapNodes[Child2Index]->getID())
				{
					Swap(this->_HeapNodes[ParentIndex], this->_HeapNodes[Child2Index]);
					CurrentParentIndex = Child2Index;
				}
				if (CurrentParentIndex == -1)
					return;
			}
			else {
				if (this->_HeapNodes[ParentIndex]->getSeverity() < this->_HeapNodes[Child1Index]->getSeverity())
				{
					Swap(this->_HeapNodes[ParentIndex], this->_HeapNodes[Child1Index]);
					CurrentParentIndex = Child1Index;
				}
				if (this->_HeapNodes[ParentIndex]->getSeverity() < this->_HeapNodes[Child2Index]->getSeverity())
				{
					Swap(this->_HeapNodes[ParentIndex], this->_HeapNodes[Child2Index]);
					CurrentParentIndex = Child2Index;
				}
				if (CurrentParentIndex == -1)
					return;
			}
			
			ParentIndex = CurrentParentIndex;
			Child1Index = 2 * ParentIndex + 1;
			Child2Index = 2 * ParentIndex + 2;
		}
	}
public:
	void print()
	{
		for (size_t i = 0; i < this->_Size; i++)
		{
			cout << this->_HeapNodes[i]->getID()<<endl;
		}
	}
	
	MaxHeap()
	{
		this->_Capacity = 4;
		this->_Size = 0;
		this->_HeapNodes = new HeapNode*[this->_Capacity];
	}
	void insert(HeapNode* newNode)
	{
		if (this->_Size == this->_Capacity)
		{
			this->_Capacity *= 2;
			HeapNode** temp = new HeapNode * [this->_Capacity];
			for (size_t i = 0; i < this->_Size; i++)
			{
				temp[i] = this->_HeapNodes[i];
			}
			delete[]this->_HeapNodes;

			this->_HeapNodes = temp;
		}
		this->_HeapNodes[this->_Size++]=newNode;
		ReheapifyUp();
	}
	HeapNode* peek()
	{
		if (this->_Size - 1 == 0)
			return nullptr;

		return this->_HeapNodes[0];
	}
	HeapNode* extractMax()
	{
		if(this->_Size  == 0)
			return nullptr;
		HeapNode* temp = this->_HeapNodes[0];
		this->_HeapNodes[0] = this->_HeapNodes[this->_Size - 1];
		 this->_HeapNodes[this->_Size - 1]==nullptr;
		this->_Size--;
		ReheapifyDown();
		return temp;
	}
};

