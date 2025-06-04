#pragma once
#include<iostream>
#include"LinkedList.h"
using namespace std;
template<typename T>
class Queue
{
private:
	LinkedList<T>* _LinkedList;
public:
	Queue()
	{
		_LinkedList = new LinkedList<T>();
	}
	void push(T value)
	{
		Node<T>* newNode = new Node<T>(value);
		this->_LinkedList->push_front(newNode);
	}
	void pop()
	{
		this->_LinkedList->pop_back();
	}
	T front()
	{
		Node<T>* newNode = new Node<T>();
		newNode = this->_LinkedList->back();
		return newNode->getData();
	}
	int size()
	{
		return this->_LinkedList->Size();
	}
	bool empty()
	{
		return this->_LinkedList->isEmpty();
	}
	void print()
	{
		this->_LinkedList->print();
	}
};

