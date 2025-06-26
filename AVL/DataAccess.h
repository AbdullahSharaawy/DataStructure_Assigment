#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<limits>
#include"DataInput.h"
#include "AVLNode.h"
using namespace std;

class  DataAccess
{

public:
    static AVLNode* processingLine(string line);// convert the line to Node after processing it
    static void ReadData(AVLNode**& _Data, int& size);// read data from the file
    
};
inline AVLNode* DataAccess::processingLine(string line)
{
    int ContactID = stoi(line.substr(0, line.find("#")));
    line = line.erase(0, line.find("#") + 1);
    string Name = line.substr(0, line.find("#"));
    line = line.erase(0, line.find("#") + 1);
    string Phone = line.substr(0, line.find("#"));
    line = line.erase(0, line.find("#") + 1);
    string Email = line.substr(0, line.find("#"));
    AVLNode* newNode = new AVLNode(ContactID, Name, Phone, Email);
    return newNode;
}
inline void DataAccess::ReadData(AVLNode**& _Data, int& size)
{
   
    string FileName = DataInput::ReadFileName("Enter The File Name: ");
    string line;
    int index = 0;
    size = 0;
    ifstream file(FileName);
   
    while (getline(file, line))
        size++;
    // Reset the file pointer to the beginning
    file.clear();
    file.seekg(0, ios::beg);
   
    _Data = new AVLNode * [size ];  // correct: array of pointers to AVLNode
    fill(_Data, _Data + size , nullptr);
    
    
    while (getline(file,line) && index<size) {
        _Data[index++] = processingLine(line);
    }

    file.close();
    
}



