#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class DataInput
{
private:

public:
    static void SelectDataType();
    static int ReadChoice(int from, int to);
    static string ReadFileName(string Message);// Read file of Data
    static string DataType;
};



inline int DataInput::ReadChoice(int from, int to)
{
    int choice;
    while (true)
    {
        cout << "Enter a number between "<<from<<" and "<<to<<": ";
        cin >> choice;

        if (cin.fail() || choice < from || choice > to)
        {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            cout << "Invalid input. Please enter a number between " << from << " and " << to << endl;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any extra input
            break;
        }
    }
    return choice;
}


inline void DataInput::SelectDataType()
{
    int choice;
    cout << "\n Select The Data Type:\n";
    cout << "\n 1. integer\n";
    cout << "\n 2. float\n";
    cout << "\n 3. double\n";
    cout << "\n 4. char\n";
    cout << "\n 5. string\n\n";
    choice = ReadChoice(1, 5);
    switch (choice)
    {
    case 1:
        DataInput::DataType = "int";
        break;
    case 2:
        DataInput::DataType = "float";
        break;
    case 3:
        DataInput::DataType = "double";
        break;
    case 4:
        DataInput::DataType = "char";
        break;
    case 5:
        DataInput::DataType = "string";
        break;
    }

}
inline string DataInput::ReadFileName(string message)
{
    string FileName;
    while (true) {
        cout << message << endl;
        getline(cin, FileName);

        // Check if the file exists
        ifstream file(FileName);
        if (file) {
            file.close();
            break;  // Exit loop if file exists
        }
        else {
            cout << "File does not exist. Please try again." << endl;
        }
    }
    return FileName;
}

