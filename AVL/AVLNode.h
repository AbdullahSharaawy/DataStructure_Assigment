#pragma once
#include <iostream>
using namespace std;

class AVLNode
{
private:
	int ContactID;
	string Name;
	string Phone;
	string Email;
public:
	AVLNode* RightChild;
	AVLNode* LeftChild;
	int Height;

	inline AVLNode(int contactID, string Name, string phone, string email)
	{
		this->ContactID = contactID;
		this->Phone = phone;
		this->Name = Name;
		this->Email = email;
		this->RightChild = NULL;
		this->LeftChild = NULL;
		this->Height = 1;
	}
	inline AVLNode()
	{
		this->RightChild = NULL;
		this->LeftChild = NULL;
		this->Height = 1;
	}
	inline int getContactID()
	{
		return this->ContactID;
	}
	inline string getPhone()
	{
		return this->Phone;
	}
	inline string getEmail()
	{
		return this->Email;
	}
	inline string getName()
	{
		return this->Name;
	}
	inline void setContactID(int ContactID)
	{
		this->ContactID = ContactID;
	}
	inline void setPhone(string Phone)
	{
		this->Phone = Phone;
	}
	inline void setEmail(string Email)
	{
		this->Email = Email;
	}
	inline void setName(string Name)
	{
		this->Name = Name;
	}
};

