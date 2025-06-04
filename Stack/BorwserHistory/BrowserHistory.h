#pragma once
#include<iostream>
#include"Stack.h"
using namespace std;
template<typename T>
class BrowserHistory
{
private:
	Stack<T> _BackStack;
	Stack<T> _ForwardStack;
	string _CurrentUrl="";
	
public:
	void printHistory()
	{
		cout << endl << "the current url: " << this->_CurrentUrl << endl;
		cout << endl << "Back Stack: " << endl;
		this->_BackStack.print();
		cout << endl << "Forward Stack: " << endl;
		this->_ForwardStack.print();
	}
	void visit(string url)
	{
		if (_CurrentUrl != "")
			this->_BackStack.push(_CurrentUrl);

		this->_CurrentUrl = url;
		printHistory();
	}
	void goBack()
	{
		if (_BackStack.size()!=0)
		{
			this->_ForwardStack.push(this->_CurrentUrl);
			this->_CurrentUrl = this->_BackStack.top();
			this->_BackStack.pop();
			printHistory();

		}
	}
	void goForward()
	{
		if (_ForwardStack.size()!=0)
		{
			this->_BackStack.push(this->_CurrentUrl);

			this->_CurrentUrl = this->_ForwardStack.top();
			this->_ForwardStack.pop();
			printHistory();

		}
			
	}
};

