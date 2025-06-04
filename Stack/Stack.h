#pragma once
#include<iostream>

#include"LinkedList.h"
using namespace std;
template<typename T>
class Stack
{
private:

	LinkedList<T>* _LinkedList;
public:
	Stack()
	{
		this->_LinkedList = new LinkedList<T>();
	}
	void push(T value)
	{
		Node<T>* newNode = new Node<T>(value);
		this->_LinkedList->push_back(newNode);
	}
	void pop()
	{
		this->_LinkedList->pop_back();
	}
	T top()
	{
		Node<T>* newNode = new Node<T>();
		newNode=this->_LinkedList->back();
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
};

