#include "LinkedList.h"
#include<iostream>
using namespace std;
int main()
{
	LinkedList<int> myList;
	Node<int>* myNode1=new Node<int>(1);
	Node<int>* myNode2=new Node<int>(2);
	Node<int>* myNode3=new Node<int>(3);
	Node<int>* myNode4=new Node<int>(4);
	Node<int>* myNode5=new Node<int>(5);
	myList.push_back(myNode1);
	myList.push_back(myNode2);
	myList.push_back(myNode3);
	myList.push_back(myNode4);
	myList.push_front(myNode5);
	myList.print();
	Node<int>* findNode = myList.find(1);
	cout <<"node found: "<< findNode->getData()<<endl;
	myList.Clear();
	myNode1 = new Node<int>(6);
	 myNode2 = new Node<int>(2);
	 myNode3 = new Node<int>(3);
	 myNode4 = new Node<int>(4);
	 myNode5 = new Node<int>(5);

	myList.push_back(myNode1);
	myList.push_back(myNode2);
	myList.push_back(myNode3);
	myList.push_back(myNode4);
	myList.push_front(myNode5);
	myList.print();
	myList.pop_back();
	myList.pop_front();
	cout << "mylist after pop back and pop front"<<endl;
	myList.print();
	cout <<"size: "<< myList.Size() << endl;
	cout<<"back: "<<myList.back()->getData() << endl;
	cout <<"front: "<< myList.front()->getData() << endl;
	cout<<"is empty: "<<myList.isEmpty()<<endl;
	
}