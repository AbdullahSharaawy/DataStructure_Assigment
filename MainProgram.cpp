#include<iostream>
#include"Controller.h"
#include"DataInput.h"
using namespace std;
void Start()
{
    DataInput::SelectDataType();

    if (DataInput::DataType == "int") {
        Controller<int>::StartSortingSystem();
    }
    else if (DataInput::DataType == "double") {
        Controller<double>::StartSortingSystem();
    }
    else if (DataInput::DataType == "float") {
        Controller<float>::StartSortingSystem();
    }
    else if (DataInput::DataType == "char") {
        Controller<char>::StartSortingSystem();
    }
    else if (DataInput::DataType == "string") {
        Controller<string>::StartSortingSystem();
    }
}

string DataInput::DataType = "";
int main()
{
    
    Start();
    return 0;
}
 
