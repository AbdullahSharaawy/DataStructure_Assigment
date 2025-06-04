#pragma once
#include<iostream>
using namespace std;
template<typename T>
class Node
{
private:
	
	T _Data;
public:
	Node* _Next;
	Node* _Prev;
	Node(T Data)
	{
		this->_Data = Data;
		this->_Next = nullptr;
		this->_Prev = nullptr;
	}
	Node()
	{
		
		this->_Next = nullptr;
		this->_Prev = nullptr;
	}
	T getData()
	{
		return this->_Data;
	}
};
template<typename T>
class LinkedList
{
private:
	Node<T>* _Head;
	Node<T> * _Tail;
	int _Size;
public:
	~LinkedList()
	{
		if (this->_Head == nullptr)
			return;

		Node<T>* temp = _Head;
		while (temp->_Next != nullptr)
		{
			Node<T>* deletedNode = temp;

			temp = temp->_Next;

			delete deletedNode;
		}
		delete temp;
	}
	LinkedList()
	{
		this->_Head = nullptr;
		this->_Tail = nullptr;
		_Size = 0;
	}
	void push_back(Node<T> * newNode)
	{
		_Size++;
		if (_Head == nullptr)
		{
			this->_Head = newNode;
			this->_Tail = newNode;
		}
			
		else
		{
			_Tail->_Next = newNode;
			newNode->_Prev = _Tail;
			_Tail = newNode;
		}
	}
	void push_front(Node<T>* newNode)
	{
		_Size++;
		if (_Head == nullptr)
		{
			this->_Head = newNode;
			this->_Tail = newNode;
		}
		else
		{
			_Head->_Prev = newNode;
			newNode->_Next = _Head;
			_Head = newNode;
		}
	}
	void pop_front()
	{
		if (this->_Head == nullptr)
			return;

		this->_Size--;
		Node<T>* temp = this->_Head;
		this->_Head = this->_Head->_Next;

		if(this->_Head!=nullptr)
		   this->_Head->_Prev = nullptr;
		
		delete temp;
	}
	void pop_back()
	{
		if (this->_Tail == nullptr)
			return; 

		this->_Size--;
		Node<T>* temp = this->_Tail;
		this->_Tail = _Tail->_Prev;

		if(this->_Tail!=nullptr)
		   this->_Tail->_Next = nullptr;

		delete temp;
	}
	bool isEmpty()
	{
		return !this->_Size;
	}
	int Size()
	{
		return this->_Size;
	}
	Node<T>* find(T key)
	{
		Node<T>* temp = _Head;
		while (temp->_Next != nullptr)
		{
			if (temp->getData() == key)
				return temp;

			temp = temp->_Next;
		}
		if (temp->getData() == key)
			return temp;
		delete temp;
		return nullptr;
	}
	void Clear()
	{
		if (this->_Head == nullptr)
			return;

		Node<T>* temp = _Head;
		while (temp->_Next != nullptr)
		{
			Node<T>* deletedNode = temp;

			temp = temp->_Next;

			delete deletedNode;
		}
		delete temp;
		// initialization 
		this->_Head = nullptr;
		this->_Tail = nullptr;
		this->_Size = 0;
	}
	void print()
	{
		if (this->_Head == nullptr)
			return;

		
		Node<T>* temp=_Head;
		while (temp->_Next != nullptr)
		{
			cout << temp->getData() << " <-> ";
			temp = temp->_Next;
		}
		cout << temp->getData()<<endl;
		temp = nullptr;
		delete temp;
	}
	Node<T>* front()
	{
		return this->_Head;
	}
	Node<T>* back()
	{
		return this->_Tail;
	}
};

