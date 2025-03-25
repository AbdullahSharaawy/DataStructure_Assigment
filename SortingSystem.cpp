#include<iostream>
#include"SortingSystem.h"
#include"DataInput.h"
#include"DataAccess.h"
using namespace std;

string DataInput::DataType="";
template<typename T>
void Start()
{
    T* Data;
    int* iData;
    int Size;
    
    DataAccess<T>::ReadData(Data, Size);
    SortingSystem<T> obj(Size);
    obj.SetData(Data);
    obj.selectSortingAlgorithm();
    delete[]Data;
}
int main() {
    bool Continue = true;

    while (Continue)
    {
    DataInput::SelectDataType();
    string ans;

    if (DataInput::DataType == "int")
    {
        Start<int>();

    }
        
    else if (DataInput::DataType == "string")
    {
        Start<string>();
    }
   else if (DataInput::DataType == "float")
    {
        Start<float>();
    }
   else if (DataInput::DataType == "double")
    {
        Start<double>();
    }
   else if (DataInput::DataType == "char")
    {
        Start<char>();
    }
    cout << "Do you want to sort another dataset? (y/n):";
    cin >> ans;
    while (ans != "y" && ans != "n" && ans != "Y" && ans != "N")
    {
        cout << "enter a valid choice (y/n):";
        cin >> ans;
    }
    if (ans == "Y" || ans == "y")
        Continue = true;
    else
    {
        cout << "Thank you for using the sorting system! Goodbye!";
        break;
    }
    }
   // the program doesn`t work , because else if statement
    return 0;
}

