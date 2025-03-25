#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<limits>
#include"DataInput.h"
using namespace std;
template<typename T>
class  DataAccess
{

public:
    static void ReadData(T*& _Data, int& size);// read data from the file

};



template<typename T>
inline void DataAccess<T>::ReadData(T*& _Data, int& size)
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

    _Data = new T[size];

    while (index < size) {
            file >> _Data[index++];

    }

    file.close();

}


