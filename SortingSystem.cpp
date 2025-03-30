#include<iostream>
#include"SortingSystem.h"
#include"DataInput.h"
#include"DataAccess.h"

using namespace std;

string DataInput::DataType;

template<typename T>
void Start() {
    T *Data;
    int Size;

    DataAccess<T>::ReadData(Data, Size);
    SortingSystem<T> obj(Size);
    obj.SetData(Data);
    obj.selectSortingAlgorithm();
    delete[] Data;
}

int main() {
    bool ask = false;

    while (true) {
        if (ask) {
            string ans;
            cout << "Do you want to sort another dataset? (y/n):";
            cin >> ans;
            if (!(ans == "y" || ans == "n" || ans == "Y" || ans == "N")) {
                cout << "invalid choice!" << endl;
                continue;
            }
            if (ans == "N" || ans == "n") {
                cout << "Thank you for using the sorting system! Goodbye!";
                break;
            }
        }

        DataInput::SelectDataType();

        if (DataInput::DataType == "int") {
            Start<int>();
        } else if (DataInput::DataType == "string") {
            Start<string>();
        } else if (DataInput::DataType == "float") {
            Start<float>();
        } else if (DataInput::DataType == "double") {
            Start<double>();
        } else if (DataInput::DataType == "char") {
            Start<char>();
        }

        ask = true;
    }

    return 0;
}
